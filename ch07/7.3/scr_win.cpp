/*
*File : ch06/7.3/scr_win.cpp
*Date : 2022-07-18
*Page : 249
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Window_mgr {
    public :
        using ScreenIndex = vector<Screen>::size_type;
        ScreenIndex addScreen(const Screen &);
        void clear(ScreenIndex);
    private:
        vector<Screen> screens{Screen(24, 80, ' ')};
};
/*
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
*/

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}


//以下为move和set返回类型不是引用的版本
//可以依赖默认拷贝和赋值操作，因为类中没有分配内存的操作。
//Screen类中只有内置类型和string可以使用拷贝和赋值操作
class Screen{
    friend class Window_mgr;  //将整个类设为友元
    //friend void Window_mgr::clear(ScreenIndex);//这要求要求必须在Screen类之前声明Window_mgr::clear
    public:
        typedef string::size_type pos;
        //等价于
        //using pos = string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd){ }
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){ }

        char get() const {return contents[cursor];} //  返回光标当前位置
        //成员函数重载
        inline char get(pos ht, pos wd) const;  //返回指定位置的字符
        Screen move(pos r, pos c);
        void some_member() const;

        Screen set(char);
        Screen set(pos, pos, char);

        Screen &display(ostream &os) {do_display(os); return *this;}
        const Screen &display(ostream &os) const {do_display(os); return *this;}
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        mutable size_t access_ctr;
        void do_display(ostream &os) const {os << contents;}
};

void Screen::some_member() const
{
    ++access_ctr;   //即使是const成员函数也可以改变mutable可变数据成员
}

inline Screen Screen::move(pos r, pos c)     //在类外部声明成inline
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const   //在类内部声明成inline
{
    pos row = r * width;
    return contents[row + c];
}
//move和set返回对象的引用，即对象本身
//故可以执行myScreen.move(4, 0).set('#');
inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}







int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    system("pause");
    return 0;
}