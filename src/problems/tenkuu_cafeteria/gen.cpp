#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int C = atoi(argv[1]);
    int O = atoi(argv[2]);
    cout << C << " " << O << "\n";

    for (int i = 0; i < C - 1; i++) {
        cout << rnd.next(1, (int)1e9) << " ";
    }
    cout << rnd.next(1, (int)1e9) << "\n";

    auto g = gen_directed_graph(C, O);
    for (auto &e : g) {
        cout << e.second + 1 << " " << e.first + 1 << " "
             << rnd.next(1, (int)1e9) << "\n";
    }
}