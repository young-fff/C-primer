/*
*File : ch12/12.1/StrBlob.cpp
*Date : 2022-08-05
*Page : 405
*/

#include <iostream>
#include "Str_Blob.h"

using namespace std;

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2.size = " << b2.size() << endl;
    }
    cout << "b1.size = " << b1.size() << endl;
    cout << b1.size() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    system("pause");
    return 0;
}