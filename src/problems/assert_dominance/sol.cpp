#include <bits/stdc++.h>
#define DEBUG 0
#define st first
#define nd second
#define ll long long
#define mp make_pair
#define pi pair<int, int>
using namespace std;
typedef double db;
const int SZ = 2e5 + 3;
const int MX = 1e9 + 7;
const int MOD = 1e9 + 7;

const int SIZE = 1e4 + 7;
short pos_col[SIZE][SIZE];
short pos_row_left[SIZE][SIZE];
short pos_row_right[SIZE][SIZE];
short arr[SIZE][SIZE], res;

void process(void) {
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j + 1] = (s[j] == 'X');
    }
    for (int i = 1; i <= n; i++) {
        int now = 0;
        for (int j = 1; j <= m; j++) {
            if (arr[i][j])
                pos_row_left[i][j] = now;
            else
                now = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        int now = m + 1;
        for (int j = m; j >= 1; j--) {
            if (arr[i][j])
                pos_row_right[i][j] = now;
            else
                now = j;
        }
    }
    for (int i = 1; i <= m; i++) {
        int now = n + 1;
        for (int j = n; j >= 1; j--) {
            if (arr[j][i])
                pos_col[j][i] = now;
            else
                now = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!arr[i][j])
                continue;
            int tmp =
                (pos_col[i][j] - i) - ((pos_col[i][j] - i) % 2 == 0 ? 1 : 0);
            res = max((int)res,
                      min({(int)(pos_row_right[i][j] - j) * 2 - 1,
                           (int)(j - pos_row_left[i][j]) * 2 - 1, (int)tmp}));
        }
    }
    if (res < 3)
        res = 0;
    cout << res;
    return;
}

int main() {
#ifndef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int t(1);
    while (t--)
        process();
}