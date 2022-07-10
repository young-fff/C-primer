/*
*File : ch01/1.4/if.cpp
*Date : 2022-07-10
*Page : 15
*/

#include<iostream>

int main()
{
    //currVal是我们正在统计的数；我们将读入的新值存入val
    int currVal = 0, val = 0;
    //读取第一个数，并确保确实有数据可以处理
    if (std::cin >> currVal){
        int cnt = 1;
        while (std::cin >> val){
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                << cnt << " times " << std::endl;
                currVal = val;
                cnt = 1;
            }
        }//while 循环在这里结束
        //记住打印文件中的最后一个值的个数
        std::cout << currVal << " occurs "
        << cnt << " times " << std::endl;
    }//最外层的if在这里结束
    system("pause");
    return 0;
}