#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long N, P;
    cin >> N >> P;

    long long latestPos = INT64_MIN, ans = 0;
    for (long long i = 1; i <= N; i++) {
        long long x;
        cin >> x;

        if (x > latestPos) {
            ans++;
            latestPos = x + P - 1;
        }
    }
    cout << ans;
    return 0;
}