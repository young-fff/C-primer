/*
*File : ch03/3.2/is_punct.cpp
*Date : 2022-07-12
*Page : 83
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string str = "Hello,World! ";
    decltype(str.size()) punct_cnt = 0;
    for (auto c: str)
        if (ispunct(c))
            ++punct_cnt;
    
    cout << punct_cnt << " punctuation characters in " << str << endl;
    system("pause");
    return 0;
}