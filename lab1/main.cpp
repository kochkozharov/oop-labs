#include <iostream>

#include "task.h"

int main() {
    std::string str;
    getline(std::cin, str);
    std::cout << removeVowels(str) << std::endl;
    return 0;
}