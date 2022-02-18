#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    cout << (int)rnd.next(-1e9, 1e9) << " " << (int)rnd.next(-1e9, 1e9) << "\n";
}
