#include <bits/stdc++.h>
using namespace std;

void rpt(char x, int times) {
    for (int i = 0; i < times; i++) {
        cout << x;
    }
}

inline void block(int n) {
    rpt('#', n);
}

inline void space(int n) {
    rpt(' ', n);
}

inline void newline() {
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    block(n);
    space(1);
    block(n);
    space(1);
    block(n);
    space(1);
    block(n - 1);
    newline();

    for (int i = 0; i < n - 2; i++) {
        block(1);
        space(n);
        block(1);
        space(n - 2);
        block(1);
        space(1);
        block(1);
        space(n - 2);
        block(1);
        space(1);
        block(1);
        space(n - 2);
        block(1);
        newline();
    }

    block(n);
    space(1);
    block(1);
    space(n - 2);
    block(1);
    space(1);
    block(n);
    space(1);
    block(1);
    space(n - 2);
    block(1);
    newline();

    for (int i = 0; i < n - 2; i++) {
        block(1);
        space(n);
        block(1);
        space(n - 2);
        block(1);
        space(1);

        block(1);
        space(i);
        block(1);
        space(n - 1 - i);

        block(1);
        space(n - 2);
        block(1);
        newline();
    }

    block(1);
    space(n);
    block(n);
    space(1);
    block(1);
    space(n - 2);
    block(1);
    space(1);
    block(n - 1);
}
