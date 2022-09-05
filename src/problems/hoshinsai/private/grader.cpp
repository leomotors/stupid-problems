#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "hoshinsai.h"

static std::vector<int> roots;
static int Q = 0;
static int csQ = 0;

static double f(double x) {
    Q++;
    csQ++;

    if (csQ > 1000001) {
        std::cout << "fail100\n";
        exit(0);
    }

    double res = 1.0;
    for (auto r : roots) {
        res *= (x - (double)r);
    }

    return res;
}

int main() {
    using namespace std;
    int T;
    cin >> T;

    double total_score = 0;

    for (int i = 0; i < T; i++) {
        int R;
        cin >> R;
        roots.clear();

        csQ = 0;
        for (int j = 0; j < R; j++) {
            int t;
            cin >> t;
            roots.push_back(t);
        }

        int user_ans = find_root(f);

        if (f(user_ans) != 0) {
            std::cout << "wa\n";
            return 0;
        }

        Q--;
    }
    cout << "success " << Q << " end"
         << "\n";
}