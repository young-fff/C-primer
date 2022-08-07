/*
*File : ch12/12.1/weak_ptr.cpp
*Date : 2022-08-07
*Page : 420
*/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include "Str_Blob.h"

using namespace std;


int main()
{
   auto p = make_shared<int>(42);
   weak_ptr<int> wp(p);//wp弱共享，p的引用计数未变

   if (shared_ptr<int> np = wp.lock()) {//若np不为空则条件成立
        //在if中，np与p共享对象
        //只有在lock返回true才会进入if语句体，在if中使用np访问共享对象是安全的
   }

    system("pause");
    return 0;
}