#include "find_root.h"
#include <bits/stdc++.h>
using namespace std;

int find_root(std::function<double(double)> f) {
    for (int i = -10; i <= 10; i++) {
        if ((int)f(i) == 0) {
            return i;
        }
    }
    return 0;
}
