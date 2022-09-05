#include "find_root.h"
#include <functional>

int find_root(std::function<double(double)> f) {
    int l = -10, r = 10;

    while (l <= r) {
        int mid = (l + r) / 2;

        double res = f(mid);
        double m = f((double)mid + 0.001) - res;

        if (res == 0)
            return mid;

        if (!(res > 0 ^ m > 0)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}
