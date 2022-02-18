#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int A = atoi(argv[2]);
    int P = atoi(argv[3]);
    ensure(A >= 1 && A <= N);

    cout << N << " " << A << " " << P << "\n";

    vector<int> Pe;
    for (int i = 0; i < P; i++) {
        Pe.push_back(rnd.next(1, N));
    }

    sort(Pe.begin(), Pe.end());
    for (int p : Pe) {
        cout << p << "\n";
    }
}