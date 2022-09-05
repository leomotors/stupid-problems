#include "numlib.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << toThai(
        to_string(atoll(toArabic(a).c_str()) + atoll(toArabic(b).c_str())));
}
