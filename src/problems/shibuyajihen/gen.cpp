#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv);

    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    ensure(A >= 3 && A <= 1000);
    ensure(B >= 3 && B <= 1000);

    cout << rnd.next(A, B) << "\n";
}
