/*
*File : ch05/5.3/switch.cpp
*Date : 2022-07-14
*Page : 160
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, vowelCnt = 0, otherCnt = 0, spaceCnt = 0;
    char ch;
    while (cin >> ch) {
        switch (ch)
        {
            case 'a':case 'A':
                ++aCnt;
                break;
            case 'e':case 'E':
                ++eCnt;
                break;
            case 'i':case 'I':
                ++iCnt;
                break;
            case 'o':case 'O':
                ++oCnt;
                break;
            case 'u':case 'U':
                ++uCnt;
                break;
            case '\0':case '\n':case '\t':
                ++spaceCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
        switch (ch)
        {
            case 'a':case 'A':
            case 'e':case 'E':
            case 'i':case 'I':
            case 'o':case 'O':
            case 'u':case 'U':
                ++vowelCnt;
                break;
            //等价于case 'a':case 'e':case 'i':case 'o':case 'u':
            default:
                break;
        }
    }
    cout << "Number of a : " << aCnt << '\n';
    cout << "Number of e : " << eCnt << '\n';
    cout << "Number of i : " << iCnt << '\n';
    cout << "Number of o : " << oCnt << '\n';
    cout << "Number of u : " << uCnt << endl;
    cout << "Number of vowel : " << vowelCnt << endl;
    cout << "Number of other : " << otherCnt << endl;
    cout << "Number of space : " << spaceCnt << endl;
    system("pause");
    return 0;
}