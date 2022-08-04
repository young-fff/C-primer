/*
*File : ch11/11.3/word_transform.cpp
*Date : 2022-08-04
*Page : 392
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <sstream>

using namespace std;
using std::istringstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;//保存转换规则
    string key;//要转换的单词
    string value;//替换后的单词
    //读取一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)//检查是否有转换规则
            trans_map[key] = value.substr(1);//跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    //实际的转换工作，此部分是程序的核心
    auto map_it = m.find(s);
    //如果单词在转换规则map中
    if (map_it != m.cend())
        return map_it -> second;//使用替换短语
    else 
        return s;//否则返回原string
}

void word_transform(ifstream &map_file, ifstream &input)
{
    
    auto trans_map = buildMap(map_file);//保存转换规则
    string str;
    while (getline(input, str)) {//读取一行
        istringstream stream(str);//读每一个单词
        string word;
        bool firstword = true;//控制是否打空格
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);//打印输出
        }
        cout << endl;//完成一行
    }
}

int main()
{
    ifstream rule("ch11/11.3/transform_rule.txt");
    ifstream text("ch11/11.3/transform_text.txt");
    //if (rule && text)
    word_transform(rule, text);
    //else
    //    cout << "open file error!" << endl;
    system("pause");
    return 0;
}