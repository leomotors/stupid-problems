#include <cmath>
#include <iostream>
#include <vector>

#include "find_root.hpp"

static std::vector<int> roots;
static int Q = 0;

static double f(double x) {
    Q++;

    double res = 1.0;
    for (auto r : roots) {
        res *= (x - (double)r);
    }

    return res;
}

int main() {
    using namespace std;
    int T, F;
    cin >> T >> F;

    double total_score = 0;

    for (int i = 0; i < T; i++) {
        int R, O;
        cin >> R >> O;
        roots.clear();
        Q = 0;
        for (int j = 0; j < R; j++) {
            int t;
            cin >> t;
            roots.push_back(t);
        }

        int user_ans = find_root(f);

        if (f(user_ans) != 0)
            continue;

        Q--;

        if (Q <= O) {
            total_score += F;
            continue;
        }

        total_score += (double)F * (2.0 * O) / (O + Q);
    }

    total_score /= T;

    cout << std::floor(total_score * 100) / 100 << "\n";
}