#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::istringstream;
using std::ifstream;
using std::vector;
using std::string;

void read(const string &path, vector<string> &vec)
{
    ifstream is(path);
    if(is)
    {
        string buf;
        while(std::getline(is, buf))
            vec.emplace_back(buf);
    }
}

int main()
{
    vector<string> vec;
    string path = "./data.txt";
    read(path, vec);
    for(auto i : vec)
    {
        istringstream iss(i);
        string word;
        // 因为有空格，所以用getline，如果iss>>word则只会打印每行的第一个单词
        std::getline(iss, word);
        std::cout << word << '\n';
    }
    return 0;
}