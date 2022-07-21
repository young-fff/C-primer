#include <vector>
using namespace std;
class Example {
public:
    //static double rate = 6.5;
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    //static vector<double> vec(vecSize);//vector 不需要再类内就定义大小
    static vector<double> vec;
};