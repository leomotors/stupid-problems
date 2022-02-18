#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    cout << rnd.next(1, INT_MAX) << "\n";
}