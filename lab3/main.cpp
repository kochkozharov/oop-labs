#include <iostream>

#include "figure.h"
#include "figure_array.h"
#include "rectangle.h"
#include "square.h"
#include "trapezoid.h"

class MainRoutine {
   private:
    void eraseFigure() {
        size_t n;
        std::cin >> n;
        n--;
        try {
            data.erase(n);
        } catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
            return;
        }
        std::cout << "Success.\n";
    }

    void pushFigure() {
        std::string type;
        std::cin >> type;
        try {
            if (type == "square") {
                Square *sq = new Square;
                std::cin >> *sq;
                data.pushBack((Figure *)sq);
            } else if (type == "rectangle") {
                Rectangle *tr = new Rectangle;
                std::cin >> *tr;
                data.pushBack((Figure *)tr);
            } else if (type == "trapezoid") {
                Trapezoid *oct = new Trapezoid;
                std::cin >> *oct;
                data.pushBack((Figure *)oct);
            } else {
                std::cout << "Unknown figure name.\n";
                return;
            }
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            return;
        }
        std::cout << "Success.\n";
    }

    void wholeArea() { std::cout << data.sumOfSquares() << std::endl; }

    void info() {
        std::cout << "Info: \n";
        for (int i = 0; i < data.size(); i++) {
            std::cout << (i + 1) << ":\n";
            std::cout << "  area : " << static_cast<double>(*data[i]) << "\n"
                      << "  enter : " << data[i]->center() << "\n";
        }
    }

    FigureArray data;

   public:
    void start() {
        std::string command;
        std::cout << "> ";
        std::cin >> command;
        while (command != "exit") {
            if (command == "push") {
                pushFigure();
            } else if (command == "info") {
                info();
            } else if (command == "erase") {
                eraseFigure();
            } else if (command == "area") {
                wholeArea();
            } else {
                std::cout << "Unknown command.\n";
            }
            std::cout << "> ";
            std::cin >> command;
        }
    }
};

int main() {
    MainRoutine r;
    r.start();
}