/*
*File : ch15/15.3/final.cpp
*Date : 2022-08-16
*Page : 538
*/

#include <string>
#include <iostream>

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B {
    void f1(int) const override;
    //void f2(int) override;
    //void f3() override;
    //void f4() override;
};

struct D2 : B {
    void f1(int) const final;
};

struct D3 : D2 {
    void f2();
    //void f1(int) const;
};

int main()
{
   

    system("pause");
    return 0;
}

