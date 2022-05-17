#include <bits/stdc++.h>
using namespace std;
using tp = tuple<int, int, int>;

const int mxn = 100'005, mxt = 205;
int dist[mxn][mxt];
bool vis[mxn][mxt];

int n, m, s, t;
int a, b, c;
int ans = mxt;
vector<pair<int, int>> adj[mxn];

priority_queue<tp, vector<tp>, greater<tp>> pq;

int main() {
    // memset(dist, -1, sizeof dist);
    //fill(dist, dist+sizeof(dist), mxt);
    cin >> n >> m >> s >> t;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 200; j++) {
            dist[i][j] = mxt;
        }
    }

    while (m--) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dist[s][0] = mxt;
    pq.push({0, 0, s});
    while (!pq.empty()) {
        auto [a, b, c] = pq.top();
        pq.pop();
        if (vis[c][b])
            break;
        vis[c][b] = 1;
        for (pair<int, int> e : adj[c]) {
            int nxmx = max(b, e.second), nxmn = min(e.second, dist[c][b]);
            if (dist[e.first][nxmx] < nxmn) {
                dist[e.first][nxmx] = nxmn;
                pq.push({nxmx - nxmn, nxmx, e.first});
            }
        }
    }
    for (int i = 1; i < mxt; i++) {
        if (dist[t][i] != mxt)
            ans = min(ans, i - dist[t][i]);
    }
    cout << ans;
}