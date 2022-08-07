/*
*File : ch12/12.3/TextQuery.cpp
*Date : 2022-08-07
*Page : 431
*/

#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <new>
#include <map>
#include <set>
#include <sstream>

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string& word) const;

private:
    std::shared_ptr<std::vector<std::string>> sp_text;

    //单词到行号的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> sp_dict;
};

TextQuery::TextQuery(ifstream& is) : sp_text(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        sp_text -> push_back(text);
        int n = sp_text -> size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = sp_dict[word];
            if (!lines) 
                lines.reset(new set<line_no>);
            lines -> insert(n);
        }
    }
}

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::line_no>> sp_set, 
        shared_ptr<vector<string>> sp_vec) : sought(s), lines(sp_set), file(sp_vec) {}
private:
    string sought;                              //待查找的单词
    shared_ptr<set<TextQuery::line_no>> lines;  //出现的行号
    shared_ptr<vector<string>> file;            //输入文件
};


QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = sp_dict.find(sought);
    if (loc == sp_dict.end())
        return QueryResult(sought, nodata, sp_text);
    else
        return QueryResult(sought, loc -> second, sp_text);
}

ostream& print(ostream& os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines -> size() << " " << make_plural(qr.lines -> size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file -> begin() + num) << endl;
    return os;
}

#endif