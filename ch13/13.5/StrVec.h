/*
*File : ch13/13.5/StrVec.h
*Date : 2022-08-09
*Page : 465
*/

#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <new>
#include <set>
#include <utility>

class StrVec {
public:
    StrVec(std::initializer_list<std::string>& il);
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}
    void reserve(size_t n);
    void resize (size_t n);
    void resize (size_t, const std::string& s);
    void alloc_n_move(size_t capacity);
private:
    void range_initial(const std::string* first, const std::string* last);
    static std::allocator<std::string> alloc;
    void chk_n_alloc() 
        {if (size() == capacity()) reallocate();}
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {free();}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::alloc_n_move(size_t capacity)
{
    auto newdata = alloc.allocate (capacity);

    auto dest = newdata;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i) {
        alloc.construct (dest++, std::move(*elem++));
    }
    elements = newdata;
    first_free = dest;
    cap = elements + capacity;
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity()) return;
    alloc_n_move(n);
}

void StrVec::resize(size_t n)
{
    resize (n, "");
}

void StrVec::resize (size_t n, const std::string& s)
{
    if (n > size()) {
        if (n > capacity()) {
            reserve (n);
        }

        for (size_t i = size(); i < n; ++i) {
            alloc.construct (first_free++, s);
        }
    }
    else if (n < size()) {
        while ((elements+n) != first_free) {
            alloc.destroy (--first_free);
        }
    }
}

void StrVec::range_initial(const std::string* first, const std::string* last)
{
    auto newdata = alloc_n_copy (first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string>& il)
{
    range_initial (il.begin(), il.end());
}

#endif