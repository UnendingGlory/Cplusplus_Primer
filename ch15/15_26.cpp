#include "15_26.h"

int main()
{
    Bulk_quote bq1;
    std::cout << "==============================\n";
    Bulk_quote bq2("ss", 1.0, 10, 0.1);
    std::cout << "==============================\n";
    bq2 = bq1;
    std::cout << "==============================\n";
    // tackle self-assignment
    bq2 = std::move(bq2);
    std::cout << "==============================\n";
    bq2 = std::move(bq1);
    std::cout << "==============================\n";
    return 0;
}