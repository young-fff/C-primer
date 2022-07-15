/*
*File : ch06/6.1/fact.cpp
*Date : 2022-07-15
*Page : 182
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int fact (int val) 
{
    int ret = 1;
    while (val > 1) 
        ret *= val--;
    return ret;
}

int fact1 (int val)
{
    int ret = 1, res = 1;
    while (ret <= val) {
        res *= ret++;
    }
    return res;
}

int myabs (int val)
{
    return ((val > 0) ? val : -1*val);
}
int main()
{
    int j = fact(5);
    int k = fact1(5);
    cout << "5! is " << j << endl;
    cout << "5! is " << k << endl;

    cout << "Enter a number : " ;
    int l;
    cin >> l;
    int result = fact1(l);
    cout << l << "! is " << result << endl;
    
    cout << "Enter a number : " ;
    int m;
    cin >> m;
    int result2 = myabs(m);
    cout << "|" << m << "| is " << result2 << endl;

    system("pause");
    return 0;
}