#include "aquagenlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    assert(argc >= 4);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int a = atoi(argv[3]);
    int s = rnd.next(n);
    int e = rnd.next(n);

    if (argc >= 5 && string(argv[4]) == "s1") {
        cout << "5 6 1 5\n";
        cout << "1 2 9\n1 3 4\n1 4 3\n2 5 7\n3 5 5\n4 5 1\n";
        return 0;
    } else {
        cout << n << " " << m << " " << s + 1 << " " << e + 1 << "\n";
    }

    auto graph = gen_undirected_graph(n, m);

    for (auto &edge : graph) {
        cout << edge.first + 1 << " " << edge.second + 1 << " "
             << rnd.next(1, a) << "\n";
    }
}
