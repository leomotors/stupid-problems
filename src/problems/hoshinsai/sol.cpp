#include "find_root.h"
#include <cmath>
#include <functional>
#include <iostream>
#include <set>
#include <utility>

const double _1e3 = 1.0 / 1000.0;

std::pair<double, double> getF(std::function<double(double)> f, double x) {
    double h = f(x);
    double dh = f(x + _1e3);

    return {h, (dh - h) / _1e3};
}

int find_root(std::function<double(double)> f) {
    std::set<int> seen;

    double x = 0;

    double y = 0, dy = 1;

    int co = 0;

    do {
        int oldx = x;
        x = x - y / dy;

        if (!(dy > 0 ^ y > 0)) {
            x = std::floor(x);
        } else {
            x = std::ceil(x);
        }

        if (seen.find(x) != seen.end()) {
            x = std::round((oldx + x) / 2);
        }

        seen.insert(x);

        auto [_y, _dy] = getF(f, x);

        co += 2;
        y = _y;
        dy = _dy;
    } while ((int)y != 0 && co < 100'000);

    return std::round(x);
}
