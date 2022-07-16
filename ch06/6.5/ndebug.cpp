/*
*File : ch06/6.5/ndebug.cpp
*Date : 2022-07-16
*Page : 216
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NDEBUG

void print(const int ia[], size_t size)
{
    #ifdef NDEBUG
    cerr << __func__ << ": array size is " << size << endl;
    #endif
}
int main()
{
    string word{"pink"};
    int threshold = 5;
    if (word.size() < threshold)
        cerr << "Error: " << __FILE__
            << " : in function " << __func__
            << " at line " << __LINE__ << endl
            << "       Compiled on " << __DATE__
            << " at " << __TIME__ << endl
            << "       Word read was \"" << word 
            << "\": Length too short" << endl;  
    system("pause");
    return 0;
}