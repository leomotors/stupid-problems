#include <bits/stdc++.h>
using namespace std;

int dsu[1000005];

int getParent(int i) {
    int parent = dsu[i];

    if (parent == i) {
        return i;
    }

    // * path compression
    dsu[i] = getParent(parent);
    return dsu[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, P;
    cin >> N >> R >> P;

    for (int i = 1; i <= N; i++) {
        dsu[i] = i;
    }

    for (int i = 0; i < R; i++) {
        int u, v;
        cin >> u >> v;
        dsu[getParent(v)] = getParent(u);
    }

    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;

        if (getParent(u) == getParent(v)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}
