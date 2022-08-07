/*
*File : ch12/12.1/StrBlob.h
*Date : 2022-08-05
*Page : 405
*/

#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
//#include "StrBlobPtr.h"

using namespace std;

//对于StrBlobPtr中的友元来说，此前置声明是必要的
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();

    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {return data -> size();}
    bool empty() const {return data -> empty();}
    //添加和删除元素
    void push_back(const std::string &t) {data -> push_back(t);}
    void pop_back();
    //元素访问
    std::string& front();
    std::string& back();
    //const版本
    const string& front() const;
    const string& back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data -> size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data -> front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data -> back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data -> pop_back();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data -> front();
}

const string& StrBlob::back() const 
{
    check(0, "back on empty StrBlob");
    return data -> back();
}

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr (StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr();     // 前缀递增
    size_t cur() {return this -> curr;}
private:
    // 若检查成功，check返回一个指向vector的shared_ptr.
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;      // 保存一个weak_ptr，意味着vector有可能被销毁。
    size_t curr;        // 在数组中当前的位置
};
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr (*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

//StrBlobPtr的check与StrBlob的不一样，还需要检查指向的vector是否还存在
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock(); //检查vector是否还存在
    if (!ret) 
        throw std::runtime_error("unbound StrBLobPtr");
    if (i >= ret -> size())
        throw std::out_of_range(msg);
    return ret; //否则返回指向vector的shared_ptr
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)是对象所指向的vector
}

//前缀递增：返回递增后的对象的引用
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;//推进当前位置
    return *this;
}

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    //构造函数接受的是非const型引用,故不能将StrBlobPtr绑定到const StrBlob对象
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const;
    ConstStrBlobPtr& incr();//前缀递增
    size_t cur() {return this -> curr;}
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    //保存一个weak_ptr,意味着底层vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;//在数组中当前的位置
};

#endif