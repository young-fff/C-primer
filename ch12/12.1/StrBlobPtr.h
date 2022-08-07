/*
*File : ch12/12.1/StrBlobPtr.h
*Date : 2022-08-07
*Page : 421
*/

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include "Str_Blob.h"
#include "StrBlobPtr.h"

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    //构造函数接受的是非const型引用,故不能将StrBlobPtr绑定到const StrBlob对象
    //StrBlobPtr (StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();//前缀递增
    size_t cur() {return this -> curr;}
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    //保存一个weak_ptr,意味着底层vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;//在数组中当前的位置
};

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

#endif