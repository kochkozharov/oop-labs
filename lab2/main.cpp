#include <iostream>
#include "money.h"
int main() {
    xyz::Money m("1.66");
    xyz::Money m2("02.34");
    std::cout << std::boolalpha << (m<=m2) << '\n';
    std::cout << m+m2 << '\n';
    std::cout << m2-m << '\n';
    return 0;
}