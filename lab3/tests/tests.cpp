#include <gtest/gtest.h>

#include "figure.h"

using namespace lab3;

TEST(figures, test1) {
    Square sq1({0, 0}, {3, 3});
    Square sq2({3, 0}, {0, 3});
    ASSERT_EQ(sq1, sq2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}