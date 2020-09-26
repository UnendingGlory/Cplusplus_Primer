#ifndef CH7_57_H
#define CH7_57_H

class Account
{
private:
    static constexpr int period = 30;
    double daily_tb[period];
    static double interestRate;
    static double initRate();

public:
    Account() = default;
    ~Account();
    static double rate() {return interestRate;}
    static void rate(double);
};



#endif