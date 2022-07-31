#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> sstack;
        char Top;
        for (auto i : s) {
            if (!sstack.empty()) {
                Top = sstack.top();
                cout <<"i = " << i << " Top = " << Top << endl;
                switch (i)
                {
                    case ')': {
                        if (Top == '(') {
                            sstack.pop();
                            continue;
                        }
                        break;
                    }
                    case ']': {
                        if (Top == '[') {
                            sstack.pop();
                            continue;
                        }
                        break;
                    }
                    case '}': {
                        if (Top == '{') {
                            sstack.pop();
                            continue;
                        }
                        break;
                    }
                }
            }
            sstack.push(i);
        }
        return sstack.empty();
    }
int main () 
{
    string s = "({{{{}}}))";
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}