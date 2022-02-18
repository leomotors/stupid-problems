#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int p = argc >= 4 ? atoi(argv[3]) : 1e3;
    int a = argc >= 5 ? atoi(argv[4]) : 1e6;
    cout << n << " " << m << "\n";

    for (int i = 0; i < n - 1; i++)
        cout << rnd.next(p) << " ";
    cout << rnd.next(p) << "\n";

    auto graph = gen_undirected_graph(n, m);

    for (auto &edge : graph) {
        cout << edge.first + 1 << " " << edge.second + 1 << " "
             << rnd.next(1, a) << "\n";
    }
}
