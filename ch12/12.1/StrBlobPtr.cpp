/*
*File : ch12/12.1/StrBlobPtr.cpp
*Date : 2022-08-07
*Page : 422
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include "Str_Blob.h"

using namespace std;

int main()
{
    string ifile = "ch12/12.1/infile.txt";
    ifstream ifs(ifile);
    if (ifs) {
        string temp;
        StrBlob s;
        while (getline(ifs ,temp)) 
            s.push_back(temp);
        cout << "Read all word" << endl;
        for (StrBlobPtr pbeg = s.begin(), pend = s.end(); pbeg.cur() != pend.cur(); pbeg.incr())
            cout << pbeg.deref() << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}