/*
*File : ch06/6.5/default_arg.cpp
*Date : 2022-07-16
*Page : 211
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char background = ' ');
//一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值

sz wd = 80;
char def = ' ';
sz ht();
string screen2(sz = ht(), sz = wd, char = def);
string window;
void f2()
{
    def = '*';
    sz wd = 100;
    window = screen2();
}
int main()
{
    
    window = screen();
    window = screen(66);
    window = screen(66, 256);
    window = screen(66, 256, '#');

    //window = screen(, , '?');
    window = screen('?');

    string screen1(sz ht, sz wid, char background = ' ');
    //string screen1(sz ht, sz wid, char background = '*');
    //不能修改已经存在的默认值
    string screen1(sz ht = 24, sz wid =80, char);

    window = screen2();

    
    system("pause");
    return 0;
}