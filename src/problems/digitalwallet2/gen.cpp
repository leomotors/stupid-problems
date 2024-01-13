#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int Nmax = atoi(argv[1]);
    int maxM = atoi(argv[2]);
    int maxCk = atoi(argv[3]);

    int N = rnd.next(2, Nmax);
    int T = rnd.next(1, N);
    int ckQuota = maxCk;

    cout << N << " " << T << "\n";
    ensure(T <= N);

    for (int i = 0; i < N; i++) {
        cout << rnd.next(0, maxM) << "\n";
        int ck = rnd.next(0, ckQuota);

        set<int> child;

        for (int j = 0; j < ck; j++) {
            int rd = rnd.next(0, N - 2);
            if (rd >= i)
                rd++;

            child.insert(rd);
        }

        cout << child.size();
        for (int x : child) {
            cout << " " << x;
        }

        cout << "\n";
        ckQuota -= child.size();
    }
}
