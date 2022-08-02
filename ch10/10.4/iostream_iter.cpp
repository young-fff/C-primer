/*
*File : ch10/10.4/iostream_iter.cpp
*Date : 2022-08-02
*Page : 359
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <list>
#include <string>


using namespace std;

void readIntByFile(string& in_file, string& out_file_odd, string& out_file_even)
{
    ifstream in(in_file);
    ofstream out_odd(out_file_odd);
    ofstream out_even(out_file_even);
    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> out_iter_odd(out_odd, " "), out_iter_even(out_even, "\n");

    std::for_each(in_iter, eof, [&out_iter_odd, &out_iter_even](const int i) {
             (i%2 ? out_iter_odd : out_iter_even)++ = i;
             });
}

int main()
{
//使用istream_iter
    vector<int> vec;
    istream_iterator<int> int_iter(cin);
    istream_iterator<int> eof;
    while (int_iter != eof)
        vec.push_back(*int_iter++);

    istream_iterator<int> in_iter2(cin), eof2;
    vector<int> vec2(in_iter2, eof2);

    ifstream in("afile");
    istream_iterator<string> str_In(in);
    istream_iterator<int> in2(cin), eof3;
    cout <<  accumulate(in2, eof3, 0) << endl;

//使用ostream_iter
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec)
        *out_iter++ = e;// * 和 ++没有作用，但可以提高可读性和未来换迭代器的一致性
    cout << endl;

    for (auto e : vec)
        out_iter  = e;
    cout << endl;

    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    ifstream in3("afile");
    istream_iterator<string> in_iter3(in3);
    istream_iterator<string> eof4;
    vector<string> svec3;
    while (in_iter3 != eof4) {
        svec3.push_back(*in_iter3++);
    }  

    istream_iterator<int> in5(cin), en;
    ostream_iterator<int> os5(cout);
    vector<int> vec5(in5, en);
    sort(vec5.begin(), vec5.end());
    copy(vec5.begin(), vec5.end(), os5);
    unique_copy(vec5.begin(), vec5.end(), os5);
    system("pause");
    return 0;
}