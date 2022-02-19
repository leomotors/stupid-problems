#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int currdeg = 1;
        int currmod = a % c;

        int64_t dp[100]{0};
        dp[0] = currmod;

        for (int i = 1; i <= log2(b); i++) {
            dp[i] = dp[i - 1] * dp[i - 1] % c;
        }

        int64_t mult = 1;
        while (b > 0) {
            int t = log2(b);
            mult *= dp[t];
            mult %= c;
            b -= pow(2, t);
        }

        cout << mult << "\n";
    }
}
