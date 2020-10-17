#include "12_27.cc"

using std::cin; using std::cout;
using std::ostream;

// no punctuation process
void RunQeury(ifstream &infile)
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
    ifstream ifs("./speak_now_lyrics.txt");
    RunQeury(ifs);
    return 0;
}
