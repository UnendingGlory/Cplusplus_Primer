#include <iostream>
#include <bitset>
#include <string>
using std::bitset; using std::string;

// 由于要传入不同的题数
// 但是bitset又不能用非静态成员初始化
// 因此设计为一个模板类，N可变
template <size_t N>
class QuizAns
{
public:
	// constructors
	QuizAns() = default;
	QuizAns(const string &s) : bst(s) {}

	// generate StuAns grade
	template <size_t M>
	friend size_t grade(QuizAns<M> const&, QuizAns<M> const&);

	// update bst accord to the answer of an question
	void update(std::pair<size_t, bool>);

	// overload output operator
	template <size_t M>
	friend std::ostream& operator<<(std::ostream&, QuizAns<M> const&);

private:
	bitset<N> bst;
};

// return grade of a student
template <size_t M>
size_t grade(QuizAns<M> const& stdAns, QuizAns<M> const& stuAns)
{
	// 相同置为0，不同置为1
	auto result = stdAns.bst ^ stuAns.bst;
	result.flip(); // 反转过后即对的题，同或 = ~^
	return result.count();
}

template <size_t M>
std::ostream& operator<<(std::ostream &os, const QuizAns<M>& q)
{
	os << q.bst;
	return os;
}

template <size_t N>
void QuizAns<N>::update(std::pair<size_t, bool> p)
{
	bst[p.first] = p.second;
}

int main()
{
	//Ex17_11
    std::string s = "1010101";
    QuizAns<10> quiz(s);
    std::cout << quiz << std::endl;

	// Ex17_12，最低位错误
	quiz.update(std::make_pair(0, false));
	std::cout << quiz << std::endl;

	// Ex17_13
	std::string answer = "10011";
    std::string stu_answer = "11001";
    QuizAns<5> ans(answer), stu_ans(stu_answer);
    std::cout << grade(ans, stu_ans) << std::endl;

	// 缺点：只能改判断，不能改选择题
	return 0;
}