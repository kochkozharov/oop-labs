#include <gtest/gtest.h>

#include "allocator.h"
#include "vector.h"

#include <iostream>
#include <map>
#include <vector>

using namespace lab5;

static int fact(int n) {
    if (n == 0)
        return 1;
    int result = 1;
    for (; n > 0; n--) {
        result *= n;
    }
    return result;
}

TEST(Lab5, AllocatorMapTest) {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> m;
    m[0] = 1;
    for (int i = 1; i < 10; i++) {
        m[i] = m[i - 1] * i;
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(m[i], fact(i));
    }
}

TEST(Lab5, VectorTest) {
    Vector<int> a = {0, 1, 2, 3, 4};
    a.pushBack(5);
    a.pushBack(6);
    int sum = 0;
    for (const auto& i : a) {
        sum += i;
    }
    EXPECT_EQ(sum, 21);
    std::vector<std::vector<int>> meow = {
        {1, 2, 3},
        {3, 2, 1},
        {123, 3123, 3}
    };
    Vector<std::vector<int>> mmeow;
    for (size_t i = 0; i < meow.size(); i++) {
        mmeow.pushBack(meow[i]);
    }
    for (size_t i = 0; i < mmeow.size(); i++) {
        EXPECT_EQ(meow[i], mmeow[i]);
    }
}

TEST(Lab5, VectorBinAllocatorTest) {
    Vector<int, Allocator<int>> a = {0, 1, 2, 3, 4};
    a.pushBack(5);
    a.pushBack(6);
    int sum = 0;
    for (const auto& i : a) {
        sum += i;
    }
    EXPECT_EQ(sum, 21);
    std::vector<std::string> meow = {
        "abc",
        "meow",
        "pepe"
    };
    Vector<std::string, Allocator<std::string>> mmeow;
    for (size_t i = 0; i < meow.size(); i++) {
        mmeow.pushBack(meow[i]);
    }
    for (size_t i = 0; i < mmeow.size(); i++) {
        EXPECT_EQ(meow[i], mmeow[i]);
    }
}

TEST(Lab5, VectorInteratorTest) {
    Vector<std::string, Allocator<std::string>> a = {
        "abc",
        "meow",
        "clcl"
    };

    Vector<std::string, Allocator<std::string>> b(3);
    std::copy(a.begin(), a.end(), b.begin());
    for (size_t i = 0; i < b.size(); i++) {
        EXPECT_EQ(a[i], b[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}