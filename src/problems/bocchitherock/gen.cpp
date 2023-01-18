#include "aquagenlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int NRange = atoi(argv[1]);
    int MRange = atoi(argv[2]);
    int KRange = atoi(argv[3]);
    int Subtask = atoi(argv[4]);

    int N = rnd.next(3, NRange);
    int M = rnd.next(N - 1, (int)min((long long)MRange,
                                     (long long)N * ((long long)N - 1) / 2));
    int K = rnd.next(1, min(KRange, N));

    auto graph = gen_undirected_graph(N, M);

    cout << N << "\n" << M << "\n";

    for (auto &[u, v] : graph) {
        cout << u << " " << v << " "
             << (Subtask == 2 ? 0 : rnd.next(0, 1000000)) << "\n";
    }

    cout << K << "\n";

    if (Subtask == 1) {
        int minCost = rnd.next(0, 1000);
        cout << "0 " << minCost << "\n";

        for (int i = 0; i < K - 1; i++) {
            cout << rnd.next(0, N - 1) << " "
                 << rnd.next(minCost + 1, 100000000) << "\n";
        }
    } else {
        for (int i = 0; i < K; i++) {
            cout << rnd.next(0, N - 1) << " " << rnd.next(0, 100000000) << "\n";
        }
    }
}
