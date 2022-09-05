#include "find_root.h"
#include <functional>

int find_root(std::function<double(double)> f) {
    int y0 = f(0);
    return -y0;
}
