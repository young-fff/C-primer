/*
*File : ch08/8.1/buf.cpp
*Date : 2022-07-22
*Page : 282
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "hi!" << endl;
    cout << "hi!" << flush;
    cout << "hi!" << ends;
    cout << unitbuf;    //所有输出操作后都会立即刷新缓冲区
    //任何输出都立刻刷新
    cout << nounitbuf;  //回归正常刷新

    cin.tie(&cout);
    ostream *old_tie = cin.tie(nullptr);
    cin.tie(&cerr);
    cin.tie(old_tie);

    system("pause");
}