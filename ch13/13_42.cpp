/**
 * @brief run the code by the following command
 * g++ 13_42.cpp 13_42_TextQuery.cpp 13_42_StrVec.cpp -Wall -o 13_42
 * ./13_42
 */
 
#include "13_42_TextQuery.h"

using std::cin; using std::cout;
using std::ostream;

// no punctuation process
void RunQeury(std::ifstream &infile)
{
    // infile points to the file we want to process
    TextQuery tq(infile);

    while (true)
    {
        std::cout << "enter a word to look for, or q to quit: ";
        string s;
        if(!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.Query(s));
    }
}

int main()
{
    std::ifstream ifs("../ch12/speak_now_lyrics.txt");
    RunQeury(ifs);
    return 0;
}
