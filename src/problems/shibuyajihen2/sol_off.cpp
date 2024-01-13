#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    double state[] = {1, 0, 0, 0};

    while (N--) {
        double u1[] = {0, 0, 0, 0};
        double u2[] = {0, 0, 0, 0};

        cin >> u1[0] >> u1[1] >> u1[2] >> u1[3];
        cin >> u2[0] >> u2[1] >> u2[2] >> u2[3];

        double tensorProduct[4][4] = {
            {u1[0] * u2[0], u1[0] * u2[1], u1[1] * u2[0], u1[1] * u2[1]},
            {u1[0] * u2[2], u1[0] * u2[3], u1[1] * u2[2], u1[1] * u2[3]},
            {u1[2] * u2[0], u1[2] * u2[1], u1[3] * u2[0], u1[3] * u2[1]},
            {u1[2] * u2[2], u1[2] * u2[3], u1[3] * u2[2], u1[3] * u2[3]},
        };

        double newState[] = {
            state[0] * tensorProduct[0][0] + state[1] * tensorProduct[0][1] +
                state[2] * tensorProduct[0][2] + state[3] * tensorProduct[0][3],
            state[0] * tensorProduct[1][0] + state[1] * tensorProduct[1][1] +
                state[2] * tensorProduct[1][2] + state[3] * tensorProduct[1][3],
            state[0] * tensorProduct[2][0] + state[1] * tensorProduct[2][1] +
                state[2] * tensorProduct[2][2] + state[3] * tensorProduct[2][3],
            state[0] * tensorProduct[3][0] + state[1] * tensorProduct[3][1] +
                state[2] * tensorProduct[3][2] + state[3] * tensorProduct[3][3],
        };

        for (int i = 0; i < 4; i++) {
            state[i] = newState[i];
        }
    }

    // cerr << "====================\n";
    for (int i = 0; i < 4; i++) {
        // cerr << i << " " << state[i] << "\n";
        state[i] = state[i] * state[i];
    }

    // cerr << "Total Sum: " << state[0] + state[1] + state[2] + state[3] << "\n";

    double maxpos = 0;
    double maxval = state[0];

    for (int i = 1; i < 4; i++) {
        if (state[i] > maxval) {
            maxval = state[i];
            maxpos = i;
        }
    }

    cout << maxpos + 1 << "\n";

    // int primes[] = {2, 3, 5, 7};

    // int key = 1;

    // cerr << "Max Val = " << maxval << ", Max Pos = " << maxpos << "\n";
    // for (int i = 0; i < 4; i++) {
    //     if (maxval - state[i] < 0.01) {
    //         key *= primes[i];
    //     }
    // }

    // cerr << "=========== KEY ===========\n";
    // cout << key << "\n";
}
