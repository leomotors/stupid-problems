#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv);

    int Q = atoi(argv[1]);
    int uN = atoi(argv[2]);

    int required = rnd.next(1, Q);

    cout << Q << "\n";

    for (int i = 1; i <= Q; i++) {
        if (i == required) {
            cout << uN << "\n";
        } else {
            cout << rnd.next(1, uN) << "\n";
        }
    }
}
