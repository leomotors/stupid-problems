#include "aquagenlib.h"
#include "numlib.hpp"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    long long a = atoll(argv[1]);
    long long b = atoll(argv[2]);

    cout << toThai(to_string(rnd.next(0ll, a - 1))) << " "
         << toThai(to_string(rnd.next(0ll, b - 1))) << "\n";
}
