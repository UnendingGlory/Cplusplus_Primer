#include "orQuery.h"

// // 返回运算对象结果set的并集
// QueryResult OrQuery::eval(const TextQuery& text) const
// {
//     // 调用Query::eval，对潜在的Query_base对象虚调用
//     // 在调用时，首先Query("")构造了一个WordQuery对象
//     // WordQuery对象重载了eval，查询得到一个QueryResult
//     auto left = lhs.eval(text), right = rhs.eval(text);
//     // 将左侧运算对象的行号拷贝到结果set中
//     auto ret_lines = std::make_shared<set<line_no>>(left.begin(), left.end());
//     // 右侧运算对象行号
//     ret_lines->insert(right.begin(), right.end());
//     // 返回一个新的QueryResult，表示lhs和rhs的并集
//     return QueryResult(rep(), ret_lines, left.get_file());
// }

int main()
{
    return 0;
}
