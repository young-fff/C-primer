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

using namespace std;

class StrBlob {
public:
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

#endif