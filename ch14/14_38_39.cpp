#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

// 判断一个字符串
class IsInRange{
public:
    IsInRange(size_t _lower, size_t _upper) : _lower(_lower), _upper(_upper) {};

    bool operator()(const std::string s) const
    {
        return s.size() >= _lower && s.size() <= _upper;
    }

    size_t lower_limit() const {return _lower;}
    size_t upper_limit() const {return _upper;}

private:
    size_t _lower;
    size_t _upper;
};

int main()
{
    size_t lower = 1;
    // u代表无符号整数
    auto uppers = {3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u};
    std::vector<IsInRange> predicates;
    for(auto upper : uppers)
    {
       // 聚合类：都是public且没有构造函数（struct）
        predicates.emplace_back(IsInRange{lower, upper});
    }

    // upper bound and count
    std::map<size_t, size_t> count_table;
    for(auto upper : uppers) count_table[upper] = 0;

    std::ifstream fin("../ch12/speak_now_lyrics.txt");
    for(std::string word; fin >> word; )
    {
        for(auto is_size_in_range : predicates)
            if(is_size_in_range(word))
                ++count_table[is_size_in_range.upper_limit()];
    }

    for(auto pair : count_table)
        std::cout << "count in range[1, " << pair.first << "] : " << pair.second << '\n';

    return 0;
}