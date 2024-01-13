#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double basicMatrices[][4] = {
    // I
    {1, 0, 0, 1},
    // X
    {0, 1, 1, 0},
    // Z
    {1, 0, 0, -1},
    // H,
    {1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), -1 / sqrt(2)},
};

vector<double> rY(double theta) {
    theta /= 2;

    return vector<double>({cos(theta), -sin(theta), sin(theta), cos(theta)});
}

void printGate(double *gate) {
    cout << gate[0] << " " << gate[1] << "\n";
    cout << gate[2] << " " << gate[3] << "\n";
}

void genGate(int gateIndex, int subtask, int seed) {
    if (gateIndex == 2 && (subtask == 1 || subtask == 3)) {
        printGate(basicMatrices[0]);
        return;
    }

    if (subtask == 1) {
        printGate(basicMatrices[seed % 3]);
        return;
    }

    if (subtask == 2) {
        printGate(basicMatrices[rnd.next(0, 2)]);
        return;
    }

    if (rnd.next(0, 1)) {
        printGate(basicMatrices[rnd.next(0, 3)]);
    } else {
        printGate(&rY(rnd.next(0, 200) * M_PI / 100)[0]);
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    cout << setprecision(15) << fixed;

    int N = atoi(argv[1]);
    int subtask = atoi(argv[2]);
    int seed = atoi(argv[3]);

    ensure(N >= 1 && N <= 10);
    cout << N << "\n";

    while (N--) {
        genGate(1, subtask, seed);
        genGate(2, subtask, seed);
    }
}
