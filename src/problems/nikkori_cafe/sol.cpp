#include <bits/stdc++.h>
using namespace std;

int N, A, P;
vector<int> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> P;

    pos.reserve(P);

    for (int i = 0; i < P; i++) {
        int x;
        cin >> x;
        if (pos[pos.size() - 1] != x)
            pos.push_back(x);
    }

    deque<pair<int, int>> sw;
    sw.push_back({1, pos[0]});
    int bestwin = 1;
    for (int i = 1; i < pos.size(); i++) {
        while (!sw.empty() && sw.front().second <= pos[i] - A)
            sw.pop_front();

        sw.push_back({bestwin + 1, pos[i]});
        bestwin = sw.front().first;
    }

    cout << bestwin << "\n";
}
