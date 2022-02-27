#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = atoi(argv[1]);
    int F = atoi(argv[2]);
    int O = atoi(argv[3]);

    cout << T << " " << F << "\n";

    int RCL = atoi(argv[4]);
    int RVL = atoi(argv[5]);

    for (int i = 0; i < T; i++) {
        int rs = rnd.next(RCL == 2 ? 2 : 1, RCL);
        cout << rs << " ";

        if (O == 69420 && rnd.next(10) >= 5) {
            cout << 177013 << "\n";
        } else {
            cout << O << "\n";
        }

        for (int j = 0; j < rs; j++) {
            if (RVL == 69) {
                cout << "69 ";
                continue;
            }

            int r = rnd.next(-RVL, RVL);
            cout << r << " ";
        }
        cout << "\n";
    }
}