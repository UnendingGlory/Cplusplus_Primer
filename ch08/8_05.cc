#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

void read_file(const string &infile, vector<string> &vec)
{
    ifstream is(infile);
    if(is)
    {
        string buf;
        // 以流进行输入，则会以空格为分割
        while(is >> buf)
            vec.emplace_back(buf);
    }
}

int main()
{
    vector<string> vec;
    read_file("./data.txt", vec);
    for(auto i : vec)
        std::cout << i << '\n';
    return 0;
}