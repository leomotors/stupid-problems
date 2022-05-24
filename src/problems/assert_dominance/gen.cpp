#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int R = atoi(argv[1]);
    auto C = atoi(argv[2]);
    auto chance = atoi(argv[3]);
    ensure(R >= 3 && R <= 10'000);
    ensure(C >= 3 && C <= 10'000);

    ensure(chance >= 0 && chance <= 1'000'000);

    cout << R << " " << C << "\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << ((rnd.next(1'000'000) < chance) ? 'X' : '.');
        }
        cout << "\n";
    }
}