#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    cout << rnd.next(a, b) << "\n";
}
