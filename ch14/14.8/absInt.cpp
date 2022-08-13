/*
*File : ch14/14.8/absInt.cpp
*Date : 2022-08-13
*Page : 506
*/

#include <iostream>
#include <vector>
using namespace std;

struct absInt {
    int operator() (int val) const {
        return val < 0 ? -val : val;
    }
};

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const string &s) const {os << s << sep;}
private:
    ostream &os;
    char sep;
};

class PrintString2 {
public:
    PrintString2(istream &i) : is(i) {}
    string& operator()() 
    {
        return s;
    }
private:
    istream &is;
    string s;
};

class PrintString3 {
    friend std::ostream& operator<< (std::ostream& os, PrintString3& ps);
public:
    PrintString3 (std::istream& i) : is (i)
    {
        std::string s;
        while (std::getline (is, s)) {
            svec.push_back(s);
        }
    }

private:
    istream& is;
    vector<std::string> svec;
};

ostream& operator<< (ostream& os, PrintString3& ps)
{
    for (auto i : ps.svec) {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

int main()
{
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    std::cout << ui << std::endl;

    string s = "hello";
    PrintString printer;
    printer(s);
    PrintString errors(cerr, '\n');
    errors(s);

    PrintString2 ps(cin);
    string str = ps();
    cout << str << endl;

    system("pause");
    return 0;
}