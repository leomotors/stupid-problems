#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, P;
    cin >> N >> P;

    int latestPos = INT32_MIN, ans = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        if (x > latestPos) {
            ans++;
            latestPos = x + P - 1;
        }
    }
    cout << ans;
    return 0;
}