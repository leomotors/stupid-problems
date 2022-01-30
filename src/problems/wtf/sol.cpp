#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    srand(n + 571892333);

    if (rand() > INT_MAX / 2) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}
