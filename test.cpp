#include <iostream>
#include <regex>
#include <string>
#include <exception>

void try_rvalue(int &&i) {}

template <typename T>
void try_rvalue_template(T&& i) {}

int main()
{
    // Tokenization (non-matched fragments)
    // Note that regex is matched only two times; when the third value is obtained
    // the iterator is a suffix iterator.
    const std::string text = "Quick brown fox.";
    const std::regex ws_re("[ ]"); // whitespace
    // -1 represents that match pattern acts like seperator
    // use ostream iterator
    std::copy( std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
               std::sregex_token_iterator(),
               std::ostream_iterator<std::string>(std::cout, "\n"));

    std::cout << '\n' ;

    // Iterating the first submatches
    const std::string html = R"(<p><a href="http://google.com">google</a> )"
                             R"(< a HREF ="http://baidu.com">baidu</a>\n</p>)";
    const std::regex url_re(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
    std::copy( std::sregex_token_iterator(html.begin(), html.end(), url_re, 1),
               std::sregex_token_iterator(),
               std::ostream_iterator<std::string>(std::cout, "\n"));
    
    std::terminate();
}