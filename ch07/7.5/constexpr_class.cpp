/*
*File : ch06/7.5/constexpr_class.cpp
*Date : 2022-07-21
*Page : 268
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
    constexpr bool any() {return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }
private:
    bool hw;
    bool io;
    bool other;
};

int main()
{
    constexpr Debug io_sub(false, true, false);
    //if (io_sub.any())
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false);
    //if (prod.any())
        cerr << "print an error message" << endl;   
}
