#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int R = atoi(argv[2]);
    int P = atoi(argv[3]);

    cout << N << " " << R << " " << P << "\n";

    for (int i = 0; i < R + P; i++) {
        cout << rnd.next(N) + 1 << " " << rnd.next(N) + 1 << "\n";
    }
}
