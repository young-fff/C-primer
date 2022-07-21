/*
*File : ch06/7.4/class_space.cpp
*Date : 2022-07-19
*Page : 255
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef double Money;
string bal;
class Account  {
    public:
        Money balance() {return bal;}
    private:
        Money bal;
        //...
};

int heught;
class Screen {
    public:
        typedef string::size_type pos;
        void setHeight(pos);
        pos height = 0;
};
Screen::pos verify(Screen::pos);
void Screen::setHeight(pos var) {
    height = verify(var);
}