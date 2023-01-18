#include "aquagenlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);

    int n = rnd.next(1, N);
    int m = rnd.next(0, (int)min((long long)n * (n - 1) / 2, 1000000LL));

    cout << n << " " << m << "\n";

    auto edges = gen_undirected_graph(n, m);

    for (auto &[p, q] : edges) {
        cout << p + 1 << " " << q + 1 << "\n";
    }
}
