/*
*File : ch03/3.2/vector.cpp
*Date : 2022-07-12
*Page : 83
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    vector<string> text;
    string word;
    for (int i = 0; i < 10; i++)
        ivec.push_back(i);
    while (cin >> word)
        text.push_back(word);

    for(auto i : ivec) 
        cout << i <<" ";
    cout << endl;
    for(auto i : text)
        cout << i <<" " << endl;
    system("pause");
    return 0;
}