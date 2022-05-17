#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    long long a = atoll(argv[2]);
    long long b = atoll(argv[3]);

    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        cout << rnd.next(a, b) << " " << rnd.next(a, b) << "\n";
    }
}
