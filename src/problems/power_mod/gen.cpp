#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int Q = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int c = atoi(argv[4]);
    ensure(Q >= 1 && a >= 2 && b >= 2 && c >= 2);

    cout << Q << "\n";

    for (int i = 0; i < Q; i++) {
        cout << rnd.next(2, a) << " " << rnd.next(2, b) << " " << rnd.next(2, c)
             << "\n";
    }
}