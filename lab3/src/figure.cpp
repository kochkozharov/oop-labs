#include "figure.h"

#include <iostream>

#include "utils.h"

namespace lab3 {

Square::Square(const Point& a, const Point& b) {
    if (!eq(std::abs(a.x - b.x), std::abs(a.y - b.y))) {
        throw std::invalid_argument("Bad points");
    }
    if (orientedOpposite(a, b)) {
        this->a = a;
        this->b = b;
    } else if (orientedOpposite(b, a)) {
        this->a = b;
        this->b = a;
    } else if (orientedOpposite(a, b, false)) {
        this->a.x = a.x;
        this->a.y = b.y;
        this->b.x = b.x;
        this->b.y = a.y;
    } else {
        this->a.x = b.x;
        this->a.y = a.y;
        this->b.x = a.x;
        this->b.y = b.y;
    }  // normalized
}

bool operator==(const Square& sq1, const Square& sq2) {
    return sq1.a == sq2.a && sq1.b == sq2.b;
}

std::ostream& operator<<(std::ostream& output, const Figure& figure) {
    figure.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, Figure& figure) {
    figure.input(input);
    return input;
}

Square::operator double() const {}
Point Square::geometricCenter() const {}
void Square::print(std::ostream& output) const {}
void Square::input(std::istream& input) {}
}  // namespace lab3
   // namespace lab3
