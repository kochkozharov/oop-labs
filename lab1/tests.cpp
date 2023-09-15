#include <gtest/gtest.h>

#include "task.h"

TEST(test1, remove_vowels) {
    std::string s = "";
    ASSERT_TRUE(_removeVowels(s) == "");
}

TEST(test2, remove_vowels) {
    std::string s = "1 3";
    ASSERT_TRUE(_removeVowels(s) == "1 3");
}

TEST(test3, remove_vowels) {
    std::string s = "abc";
    ASSERT_TRUE(_removeVowels(s) == "bc");
}

TEST(test4, remove_vowels) {
    std::string s = "ABC";
    ASSERT_TRUE(_removeVowels(s) == "BC");
}

TEST(test5, remove_vowels) {
    std::string s = "testing::InitGoogleTest";
    ASSERT_TRUE(_removeVowels(s) == "tstng::ntGglTst");
}

TEST(test6, remove_vowels) {
    std::string s = "This website is for losers LOL!";
    ASSERT_FALSE(_removeVowels(s) == "Ths wbst s fr losrs LL!");
}

TEST(test7, remove_vowels) {
    std::string s = "ABC";
    ASSERT_TRUE(removeVowels(s) == "BC");
}

TEST(test8, remove_vowels) {
    std::string s = "testing::InitGoogleTest";
    ASSERT_TRUE(removeVowels(s) == "tstng::ntGglTst");
}

TEST(test9, remove_vowels) {
    std::string s = "This website is for losers LOL!";
    ASSERT_FALSE(removeVowels(s) == "Ths wbst s fr losrs LL!");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}