#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int varRVL(int r, int i, int t) {
    if (r < 100)
        return r;

    return pow(10, sqrt(static_cast<double>(i) / t) * log10(r));
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = atoi(argv[1]);

    cout << T << "\n";

    int RCL = atoi(argv[2]);
    int _RVL = atoi(argv[3]);
    int SubtaskID = atoi(argv[4]);

    vector<int> RVLS;
    for (int i = 0; i < T; i++) {
        RVLS.push_back(varRVL(_RVL, i + 1, T));
    }

    for (int i = 0; i < 10'000; i++) {
        swap(RVLS[rnd.next(T)], RVLS[rnd.next(T)]);
    }

    for (int i = 0; i < T; i++) {
        int RVL = RVLS[i];
        ensure(RVL <= _RVL);
        ensure(RVL > 0);

        int singleroot = rnd.next(-RVL, RVL);

        int rs = rnd.next(RCL == 2 ? (RCL == 3 ? 3 : 2) : 1, RCL);
        cout << rs << " ";

        for (int j = 0; j < rs; j++) {
            if (RVL == 69) {
                cout << "69 ";
                continue;
            }

            int r = SubtaskID == 4 ? singleroot : rnd.next(-RVL, RVL);
            cout << r << " ";
        }
        cout << "\n";
    }
}