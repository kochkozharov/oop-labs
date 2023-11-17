#pragma once

#include <iostream>

#include "point.h"

namespace lab3 {

class Figure {
    friend std::istream& operator>>(std::istream& input, Figure& figure);
    friend std::ostream& operator<<(std::ostream& output, const Figure& figure);

   public:
    virtual Point geometricCenter() const = 0;
    virtual operator double() const = 0;

   private:
    virtual void input(std::istream& input) = 0;
    virtual void print(std::ostream& output) const = 0;
};

class Square : public Figure {
    friend bool operator==(const Square& a, const Square& b);

   public:
    Square(const Point& a, const Point& b);
    virtual Point geometricCenter() const override;
    virtual operator double() const override;

   private:
    virtual void print(std::ostream& output) const override;
    virtual void input(std::istream& input) override;
    Point a, b;
};

class Rectangle : public Figure {
    friend bool operator==(const Rectangle& a, const Rectangle& b);

   public:
    Rectangle(Point& a, Point& b);
    virtual Point geometricCenter() const override;
    virtual operator double() const override;

   private:
    virtual void input(std::istream& input) override;
    virtual void print(std::ostream& output) const override;
    Point a, b;
};

class Trapezoid : public Figure {
    friend bool operator==(const Trapezoid& a, const Trapezoid& b);

   public:
    Trapezoid(Point& a, Point& b, Point& c, Point& d);
    virtual Point geometricCenter() const override;
    virtual operator double() const override;

   private:
    virtual void print(std::ostream& output) const override;
    virtual void input(std::istream& input) override;
    Point a, b, c, d;
};

}  // namespace lab3