#include <bits/stdc++.h>
using namespace std;

int N, T;
int money[100005];
set<int> adj[100005];

int trySolution(int t) {
    vector<bool> eligible(N, true);

    for (int i = 0; i < N; i++) {
        if (!eligible[i])
            continue;

        if (money[i] > t) {
            eligible[i] = false;
            continue;
        }

        for (int j : adj[i]) {
            if (money[j] > t) {
                eligible[i] = false;
                break;
            }
        }
    }

    int eligible_count = 0;
    for (int i = 0; i < N; i++) {
        if (eligible[i]) {
            eligible_count++;
        }
    }

    return eligible_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T;

    int lb = 0, ub = 1;

    for (int i = 0; i < N; i++) {
        cin >> money[i];

        ub = max(ub, money[i]);

        int C;
        cin >> C;

        for (int j = 0; j < C; j++) {
            int x;
            cin >> x;
            adj[i].insert(x);
            adj[x].insert(i);
        }
    }

    while (lb < ub) {
        // cerr << "lb = " << lb << ", ub = " << ub << "\n";

        int mid = (lb + ub) / 2;

        int eligible_count = trySolution(mid);
        // cerr << "ans = " << eligible_count << "\n";

        if (eligible_count >= T) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }

    cout << lb << "\n";
}
