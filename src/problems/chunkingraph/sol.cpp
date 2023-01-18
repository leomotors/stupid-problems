#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 5e5 + 5;

int n, m;
int cnt;
vector<int> g[N];
int low[N], pre[N];

void dfs(int u, int p) {
    static int dep = 0;
    pre[u] = low[u] = ++dep;
    for (int v : g[u])
        if (v != p) {
            if (pre[v] == 0) {
                dfs(v, u);
                if (low[v] > pre[u]) {
                    // cerr << "=> " << u << ' ' << v << endl;
                    cnt++;
                }
            }
            low[u] = min(low[u], low[v]);
        }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (pre[i] == 0) {
            // cerr << "YES" << endl;
            cnt = 0;
            dfs(i, 0);
            ans += cnt + 1;
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //   cerr << i << ' ' << low[i] << endl;
    // }
    printf("%d\n", ans);
}