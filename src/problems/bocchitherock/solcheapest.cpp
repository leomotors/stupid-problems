#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
    }

    cin >> K;

    int64_t minairway = INT64_MAX;

    for (int i = 0; i < K; i++) {
        int64_t k, c;
        cin >> k >> c;

        if (c < minairway) {
            minairway = c;
        }
    }

    cout << minairway << "\n";
}
