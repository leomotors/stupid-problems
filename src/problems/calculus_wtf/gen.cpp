#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int T = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (string(argv[3]) == "sample1") {
        cout << "2\n1 0\n1 2\n";
        return 0;
    }

    cout << T << "\n";

    map<int, int> terms;
    terms[0] = rnd.next(1, 10);
    terms[2] = rnd.next(1, 10);
    while (terms.size() < T) {
        int targetDeg = rnd.next(1, n);
        terms[targetDeg] = rnd.next(1, 10);
    }

    for (auto t : terms) {
        cout << t.second << " " << t.first << "\n";
    }
}