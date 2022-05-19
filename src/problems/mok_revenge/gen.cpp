#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    auto P = atoll(argv[2]);
    auto xr = atoll(argv[3]);
    ensure(N >= 1 && N <= 6'000'000);
    ensure(P >= 1 && P <= 1e18);

    cout << N << " " << P << "\n";

    vector<long long> Xi;
    for (int i = 0; i < N; i++) {
        Xi.push_back(rnd.next(-xr, xr));
    }

    sort(Xi.begin(), Xi.end());
    for (auto p : Xi) {
        cout << p << " ";
    }
    cout << "\n";
}