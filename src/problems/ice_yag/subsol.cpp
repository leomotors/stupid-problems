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

struct Data {
    int w, high, low, v;
    bool operator<(const Data &joox) const {
        return w > joox.w;
    }
};

set<int> disc[SZ];
int mem_low[SZ][1200], hey[SZ][1200];
vector<pair<int, int>> node[SZ];

void process(void) {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    assert(s != e);
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        node[u].emplace_back(v, w);
        node[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++)
        disc[i].insert(-1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 1200; j++) {
            mem_low[i][j] = MX;
        }
    }
    priority_queue<Data> hx;
    hx.push({0, 0, MX, s});
    while (!hx.empty()) {
        auto o = hx.top();
        hx.pop();

        if (hey[o.v][o.high] > o.low)
            continue;

        if (DEBUG) {
            cout << "NOW : ";
            cout << o.w << ' ' << o.low << ' ' << o.high << " NODE : ";
            cout << o.v << '\n';
        }

        if (o.v == e) {
            if (DEBUG)
                cout << o.low << ' ' << o.high << '\n';
            cout << o.w;
            break;
        }

        for (auto x : node[o.v]) {
            int new_low = min(o.low, x.nd);
            int new_high = max(o.high, x.nd);
            if (x.st == s)
                continue;
            if (hey[x.st][new_high] < new_low) {
                hey[x.st][new_high] = new_low;
                hx.push({new_high - new_low, new_high, new_low, x.st});
            }
        }
    }
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