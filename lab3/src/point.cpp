#include "point.h"

#include <cmath>

#include "utils.h"
namespace lab3 {
bool operator==(const Point &p1, const Point &p2) {
    return eq(p1.x, p2.x) && eq(p1.y, p2.y);
}
Point::Point() : x(0), y(0){};
Point::Point(double x, double y) : x(x), y(y){};
bool orientedOpposite(const Point &p1, const Point &p2,
                      bool orientation) {  // checked that not eq
    if (orientation)
        return p1.x < p2.x && p1.y < p2.y;  // bottom left and top right
    else 
        return p1.x < p2.x && p1.y > p2.y; // top left and bottom right
}
}  // namespace lab3