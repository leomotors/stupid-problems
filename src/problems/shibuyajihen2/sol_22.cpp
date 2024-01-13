#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    double sQ1[2] = {1, 0};
    double sQ0[2] = {1, 0};

    while (N--) {
        double u1[4] = {0, 0, 0, 0};
        double u2[4] = {0, 0, 0, 0};

        cin >> u1[0] >> u1[1] >> u1[2] >> u1[3];
        cin >> u2[0] >> u2[1] >> u2[2] >> u2[3];

        double sQ1New[2] = {
            sQ1[0] * u1[0] + sQ1[1] * u1[1],
            sQ1[0] * u1[2] + sQ1[1] * u1[3],
        };

        double sQ0New[2] = {
            sQ0[0] * u2[0] + sQ0[1] * u2[1],
            sQ0[0] * u2[2] + sQ0[1] * u2[3],
        };

        sQ1[0] = sQ1New[0];
        sQ1[1] = sQ1New[1];
        sQ0[0] = sQ0New[0];
        sQ0[1] = sQ0New[1];
    }

    double state[4] = {
        sQ1[0] * sQ0[0],
        sQ1[0] * sQ0[1],
        sQ1[1] * sQ0[0],
        sQ1[1] * sQ0[1],
    };

    for (int i = 0; i < 4; i++) {
        state[i] = state[i] * state[i];
    }

    double maxpos = 0;
    double maxval = state[0];

    for (int i = 1; i < 4; i++) {
        if (state[i] > maxval) {
            maxval = state[i];
            maxpos = i;
        }
    }

    cout << maxpos + 1 << "\n";
}
