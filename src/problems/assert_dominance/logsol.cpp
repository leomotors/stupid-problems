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
int qs_row[SIZE][SIZE];
int qs_col[SIZE][SIZE];
int arr[SIZE][SIZE];

void process(void) {
    int n, m, res(0);
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j + 1] = (s[j] == 'X');
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            qs_row[i][j] = qs_row[i][j - 1] + arr[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            qs_col[j][i] = qs_col[j - 1][i] + arr[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!arr[i][j])
                continue;
            int l = (res / 2) + 1, r = max(n, m);
            while (l ^ r) {
                int mi = (l + r) >> 1;
                if (2 * mi + i > n || j + mi > m || j - mi < 1) {
                    r = mi;
                    continue;
                }
                bool chx1 = false, chx2 = false;
                if (qs_row[i][j + mi] - qs_row[i][j - mi - 1] == 2 * mi + 1)
                    chx1 = true;
                if (qs_col[i + 2 * mi][j] - qs_col[i - 1][j] == 2 * mi + 1)
                    chx2 = true;
                if (chx1 && chx2) {
                    l = mi + 1;
                    res = max(res, 2 * mi + 1);
                } else
                    r = mi;
            }
        }
    }
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