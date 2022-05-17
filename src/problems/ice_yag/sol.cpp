#include <bits/stdc++.h>
#define DEBUG 0
#define st first
#define nd second
#define ll long long
#define mp make_pair
#define pi pair<int, int>
using namespace std;
typedef double db;
const int SZ = 1e5 + 3;
const int MX = 1e9 + 7;
const int MOD = 1e9 + 7;
const int WMAX = 200;

int par[SZ];

int get_low(int x) {
    if (x ^ par[x]) {
        par[x] = get_low(par[x]);
    }
    return par[x];
}

struct Edge {
    int u, v, d;
    bool operator<(const Edge &joox) const {
        return d < joox.d;
    }
};
vector<Edge> path;

void process(void) {
    int n, m, s, e, res(MX);
    cin >> n >> m >> s >> e;
    assert(s != e);
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        assert(u != v);
        assert(w > 0 && w <= WMAX);
        path.push_back({u, v, w});
    }
    sort(path.begin(), path.end());
    for (int i = 1; i <= WMAX; i++) {
        int stx;
        for (int j = 0; j < m; j++) {
            if (path[j].d >= i) {
                stx = j;
                break;
            }
        }
        for (int j = 1; j <= n; j++)
            par[j] = j;
        for (int j = stx; j < m; j++) {
            int a = get_low(path[j].u);
            int b = get_low(path[j].v);
            if (a != b) {
                par[a] = par[b];
                if (get_low(s) == get_low(e)) {
                    res = min(res, path[j].d - path[stx].d);
                    break;
                }
            }
        }
    }
    cout << res;
    assert(res >= 0 && res != MX);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
#endif
    // cin.tie(nullptr)->ios::sync_with_stdio(false);
    int t(1);
    // cin >> t;
    while (t--)
        process();
}