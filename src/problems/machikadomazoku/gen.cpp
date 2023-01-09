#include "aquagenlib.h"
using namespace std;

pii withSwap(int a, int b) {
    if (rnd.next(2)) {
        return {a, b};
    } else {
        return {b, a};
    }
}

vector<pii> gen_linear(int N) {
    vector<pii> res;

    for (int i = 0; i < N - 1; i++) {
        res.push_back(withSwap(i, i + 1));
    }

    shuffle(res.begin(), res.end());

    return res;
}

vector<pii> gen_circle(int N) {
    vector<pii> res = gen_linear(N);

    res.push_back(withSwap(0, N - 1));
    shuffle(res.begin(), res.end());

    return res;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int TestCaseId = atoi(argv[2]);
    int w = atoi(argv[3]);
    int D = atoi(argv[4]);

    int M = TestCaseId == 0   ? 8
            : TestCaseId == 2 ? N - 1
            : TestCaseId == 3 ? N
                              : rnd.next(N - 1, min(50000, N * (N - 1) / 2));

    cout << N << " " << M << "\n";

    auto graph = TestCaseId == 2   ? gen_linear(N)
                 : TestCaseId == 3 ? gen_circle(N)
                                   : gen_undirected_graph(N, M);

    for (auto &edge : graph) {
        cout << edge.first << " " << edge.second << " " << rnd.next(1, w)
             << "\n";
    }

    cout << rnd.next(1, D) << "\n";
}
