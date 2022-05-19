#include <bits/stdc++.h>
using namespace std;

long long N, A, P;
vector<long long> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;

    pos.reserve(N);

    for (long long i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (pos[pos.size() - 1] != x)
            pos.push_back(x);
    }

    deque<pair<long long, long long>> sw;
    sw.push_back({1, pos[0]});
    long long bestwin = 1;
    for (long long i = 1; i < pos.size(); i++) {
        while (!sw.empty() && sw.front().second <= pos[i] - P)
            sw.pop_front();

        sw.push_back({bestwin + 1, pos[i]});
        bestwin = sw.front().first;
    }

    cout << bestwin << "\n";
}
