#include <cmath>

namespace lab3 {
inline constexpr double EPS = 1e-6;
inline bool eq(double x, double y, double epsilon = EPS) {
    return std::abs(x - y) < epsilon;
}
}  // namespace lab3