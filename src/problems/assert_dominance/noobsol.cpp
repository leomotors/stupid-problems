#include <bits/stdc++.h>
using namespace std;

int R, C;

char bits[10005][10005];
int qshor[10005][10005];
int qsvert[10005][10005];

inline int toc(char x) {
    return x == 'X' ? 1 : 0;
}

inline bool check(int T, int x, int y) {
    return (qshor[x][y + T - 1] - qshor[x][y] == T - 1) &&
           (qsvert[x + T - 1][y + T / 2] - qsvert[x][y + T / 2] == T - 1) &&
           (bits[x][y + T / 2] == 'X');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> bits[i];
    }

    // * QS INIT
    for (int i = 0; i < R; i++) {
        qshor[i][0] = toc(bits[i][0]);

        for (int j = 1; j < C; j++) {
            qshor[i][j] = toc(bits[i][j]) + qshor[i][j - 1];
        }
    }

    for (int j = 0; j < C; j++) {
        qsvert[0][j] = toc(bits[0][j]);

        for (int i = 1; i < R; i++) {
            qsvert[i][j] = toc(bits[i][j]) + qsvert[i - 1][j];
        }
    }

    int T = min(R, C);
    for (; T >= 2; T--) {
        if (T % 2 == 0)
            continue;

        bool pass = false;

        for (int i = 0; i <= R - T; i++) {
            for (int j = 0; j <= C - T; j++) {
                if (bits[i][j] == 'X' && check(T, i, j)) {
                    pass = true;
                    //cout << i << " " << j << "\n";
                    break;
                }
            }

            if (pass)
                break;
        }

        if (pass)
            break;
    }

    if (T < 3)
        T = 0;

    cout << T << "\n";
}
