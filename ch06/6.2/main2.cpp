/*
*File : ch06/6.2/main2.cpp
*Date : 2022-07-15
*Page : 197
*/

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
    char **arg = argv + 1;
    while (*arg != 0)
        cout << *arg++ << endl;
    system("pause");
    return 0;
}