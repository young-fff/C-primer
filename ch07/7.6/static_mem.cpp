/*
*File : ch06/7.6/static_mem.cpp
*Date : 2022-07-21
*Page : 269
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    static constexpr int period = 30;
    double daily_tbl[period];
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};
void Account::rate(double newRate)
{
    interestRate = newRate;
}
double Account::interestRate = initRate();
int main()
{
    double r;
    r = Account::rate();

    Account ac1;
    Account *ac2;
    r = ac1.rate();
    r = ac2->rate();
}
