#include <bits/stdc++.h>
using namespace std;

int N, M;
int pop[505];
int floyd[505][505];
const int floyd_INF = INT32_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> pop[i];
    }

    // * Init
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                floyd[i][j] = 0;
            } else {
                floyd[i][j] = floyd_INF;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        int u, v;
        int64_t l;
        cin >> u >> v >> l;
        assert(floyd[u][v] == floyd_INF);
        assert(floyd[v][u] == floyd_INF);
        floyd[u][v] = l;
        floyd[v][u] = l;
    }

    // * Floyd-Warshall
    for (int m = 1; m <= N; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j || i == m)
                    continue;

                floyd[i][j] = min(floyd[i][j], floyd[i][m] + floyd[m][j]);
            }
        }
    }

    // * Find Best Location
    int bestloc = 0;
    int64_t bestcost = floyd_INF;
    for (int i = 1; i <= N; i++) {
        int64_t totalcost = 0;
        for (int j = 1; j <= N; j++) {
            totalcost += floyd[i][j] * pop[j];
        }

        if (totalcost < bestcost) {
            bestcost = totalcost;
            bestloc = i;
        }
    }

    cout << bestloc << " " << bestcost << "\n";
}
