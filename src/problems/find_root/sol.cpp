#include "find_root.hpp"
#include <cmath>
#include <functional>
#include <iostream>
#include <utility>

const double _1e6 = 1.0 / 1000000.0;

std::pair<double, double> getF(std::function<double(double)> f, double x) {
    double h = f(x);
    double dh = f(x + _1e6);

    return {h, (dh - h) / _1e6};
}

int find_root(std::function<double(double)> f) {
    double x = 0;

    double y = 0, dy = 1;

    int co = 0;

    do {
        x = x - y / dy;

        if (dy > 0) {
            x = std::floor(x);
        } else {
            x = std::ceil(x);
        }

        auto [_y, _dy] = getF(f, x);

        co += 2;
        y = _y;
        dy = _dy;

        //std::cerr << "(" << x << ", " << y << ") -> ";

    } while ((int)y != 0 && co <= 1000000);

    //std::cerr << "RETURN " << int(x) << "\n";

    return (int)x;
}
