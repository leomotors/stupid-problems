#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 5;
int n, m, k, x, y, z, d[N];
vector<pii> v[N];
priority_queue<pii, vector<pii>, greater<pii>> q;
bool f[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        d[i] = INT_MAX;
    while (m--) {
        scanf("%d %d %d", &x, &y, &z);
        x++, y++;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &x, &y);
        x++;
        v[0].emplace_back(x, y);
    }
    d[0] = 0;
    q.emplace(d[0], 0);
    while (!q.empty()) {
        int nn, nd;
        tie(nd, nn) = q.top();
        q.pop();
        if (f[nn])
            continue;
        f[nn] = 1;
        for (auto &e : v[nn]) {
            int tn, td;
            tie(tn, td) = e;
            if (d[tn] > d[nn] + td) {
                d[tn] = d[nn] + td;
                q.emplace(d[tn], tn);
            }
        }
    }
    printf("%d", d[1]);
}