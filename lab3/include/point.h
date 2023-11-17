#pragma once

#include <limits>

namespace lab3 {

struct Point {
    Point();
    Point (double x, double y);
    double x, y;
};
bool operator==(const Point &p1, const Point &p2);
bool orientedOpposite(const Point &p1, const Point &p2, bool orientation = true);
}  // namespace lab3