#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;

void test1228()
{
    std::ifstream ifs ("ch12/12.3/textfile.txt");
    std::ofstream ofs ("ch12/12.3/result.txt");
    string tmp_line;
    vector<string> line_str;
    decltype (line_str.size()) lineNo{0};
    std::map <string, std::set<unsigned int>> dictionary;

    while (getline(ifs, tmp_line)) {
        line_str.push_back(tmp_line);
        ++ lineNo;
        std::istringstream line_stream (tmp_line);
        string unique_word, text;
        for (unique_word, text; line_stream >> text; unique_word.clear()) {
            // 把每行的以空格隔开的单词拷贝到unique_word中，标点符号除外。
            std::remove_copy_if (text.begin(), text.end(), back_inserter(unique_word), ispunct);
            // 把每个出现的单词和行号都放入map中，如果已经存在，则只插入行号。
            dictionary[unique_word].insert(lineNo);
        }
    }

    string s;
    while (true) {
        std::cout << "enter a word to search, or q to quit: ";
        if (!(std::cin >> s) || (s == "q")) {
            break;
        }
        auto found_iter = dictionary.find(s);
        if (found_iter != dictionary.end()) {
            std::cout << s << " occurs " << found_iter->second.size() << " times." << std::endl;
            for (auto i : found_iter->second) {
                std::cout << "\t(line" << i << ")" << line_str.at(i-1) << std::endl;
            }
        }
        else {
            std::cout << "Not found it." << std::endl;
        }
    }

    // 用do...while改写如下：
    do {
            std::cout << "enter a word to search, or q to quit: ";
            if (!(std::cin >> s) || (s == "q")) {
                break;
            }
            auto found_iter = dictionary.find(s);
            if (found_iter != dictionary.end()) {
                std::cout << s << " occurs " << found_iter->second.size() << " times." << std::endl;
                for (auto i : found_iter->second) {
                    std::cout << "\t(line" << i << ")" << line_str.at(i-1) << std::endl;
                }
            }
            else {
                std::cout << "Not found it." << std::endl;
            }
        } while (true);
}