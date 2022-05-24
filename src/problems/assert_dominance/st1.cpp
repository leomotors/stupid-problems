#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    int t = min(R, C);

    if (t % 2 == 0)
        t--;

    if (t < 3)
        t = 0;

    cout << t << "\n";
}
