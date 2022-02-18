#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> terms;

double f(double x) {
    double sum = 0;
    for (auto &t : terms) {
        sum += (double)t.first * pow(x, t.second);
    }

    return 1 / sum;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int c, d;
        cin >> c >> d;
        terms.push_back({c, d});
    }

    double riemann_sum = 0;
    const double dx = 1.0 / 1000000;

    for (double x = 0; x < 1000000; x++) {
        riemann_sum += f((x + 0.5) * dx) * dx;
    }

    for (int i = 0; i < 6; i++) {
        const double startPoint = pow(10, i);
        const double endPoint = pow(10, i + 1);
        const double dd = pow(10, i - 5);

        for (double x = 100000; x < 1000000; x++) {
            riemann_sum += f((x + 0.5) * dd) * dd;
        }
    }

    cout << riemann_sum << "\n";
}
