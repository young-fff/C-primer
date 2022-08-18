/*
*File : ch15/15.7/move.h
*Date : 2022-08-18
*Page : 554
*/

#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
    virtual ~Quote() = default;
};

#endif