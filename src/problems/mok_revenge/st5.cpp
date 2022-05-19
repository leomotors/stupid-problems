#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long P;

    cin >> N >> P;

    long long a, b;
    cin >> a >> b;

    if (b - a > P) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
}