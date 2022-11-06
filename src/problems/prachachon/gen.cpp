#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void generate(bool correct) {
    int sum_digits = 0;

    for (int i = 13; i >= 2; i--) {
        int curr = rnd.next(0, 9);
        cout << curr;
        sum_digits += i * curr;
    }

    sum_digits %= 11;
    sum_digits = (11 - sum_digits) % 10;

    if (correct) {
        cout << sum_digits << "\n";
    } else {
        int wrong_digit = rnd.next(0, 9);

        if (wrong_digit == sum_digits) {
            wrong_digit = (wrong_digit + 1) % 10;
        }

        cout << wrong_digit << "\n";
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv);

    int Q = atoi(argv[1]);
    ensure(Q >= 1);

    cout << Q << "\n";

    int chance = rnd.next(30, 50);

    for (int i = 0; i < Q; i++) {
        generate(rnd.next(0, 100) > chance);
    }
}
