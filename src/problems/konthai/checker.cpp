#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream userout(argv[3]);

    string ans;
    userout >> ans;
    // cin >> ans;

    if (ans.size() > 200) {
        cout << 0;
        cerr << "String too big";
        return 0;
    }

    vector<int> chars;
    set<int> seen;

    for (int i = 0; i < ans.size() - 2; i++) {
        if (ans[i] == -32 && ans[i + 1] == -72) {
            int index = ans[i + 2] + 127;

            if (index != 35 && index != 37 && index >= 0 && index < 46) {
                if (seen.count(index)) {
                    continue;
                }

                seen.insert(index);
                chars.push_back(index);
            }
        }
    }

    vector<int> lis;

    for (auto c : chars) {
        if (lis.empty() || c > lis.back())
            lis.push_back(c);
        else
            *lower_bound(lis.begin(), lis.end(), c) = c;
    }

    int S = lis.size();

    if (S > 44) {
        cerr << "Unexpected Score";
        cout << 0;
        return 0;
    }

    double score = 0;

    if (S <= 1) {
        score = 0;
    } else if (S <= 4) {
        score = 0.25 * (S - 1);
    } else if (S <= 13) {
        score = S - 4;
    } else if (S <= 23) {
        score = 10 + 2 * (S - 14);
    } else if (S <= 33) {
        score = 30 + 3 * (S - 24);
    } else if (S <= 43) {
        score = 60 + 4 * (S - 34);
    } else if (S == 44) {
        score = 100;
    }

    if (score == 100)
        cerr << "คุณเป็นเยาวชนแบบอย่างที่ดีต่อคนรุ่นหลัง";
    else if (score >= 60)
        cerr << "คุณเป็นคนไทยธรรมดาคนหนึ่งที่จำได้เกือบหมด";
    else
        cerr << "ไอพวกสามกีบชังชาติ";

    cerr << " (Raw Score = " << S << ")";

    cout << score / 100;
}
