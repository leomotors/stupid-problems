#include <bits/stdc++.h>
using namespace std;

int64_t floyd[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, D;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            floyd[i][j] = i == j ? 0 : (INT64_MAX / 3);
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        floyd[u][v] = w;
        floyd[v][u] = w;
    }

    cin >> D;

    for (int m = 0; m < N; m++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || i == m)
                    continue;

                floyd[i][j] = min(floyd[i][j], floyd[i][m] + floyd[m][j]);
            }
        }
    }

    int total = 0;
    int isNear = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            total++;
            if (floyd[i][j] <= D)
                isNear++;
        }
    }

    if (isNear == 0) {
        cout << "0/1\n";
    } else {
        int comdiv = gcd(total, isNear);
        cout << isNear / comdiv << "/" << total / comdiv << "\n";
    }
}
