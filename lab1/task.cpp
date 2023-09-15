#include "task.h"

std::string& removeVowels(std::string& str) {
    const std::string vowels = "aeiouyAEIOUY";
    size_t i = 0;
    while (i < str.length()) {
        if (vowels.find(str[i]) != std::string::npos)
            str.erase(str.begin() + i);
        else
            i++;
    }
    return str;
}