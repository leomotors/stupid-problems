#include <bits/stdc++.h>
using namespace std;

const string zero = "๐";

string _toArabic(string &thai, int index) {
    if (index >= thai.size())
        return "";

    if (thai[index] != -32 || thai[index + 1] != -71) {
        throw "Cannot Parse!";
    }

    return to_string(thai[index + 2] + 112) + _toArabic(thai, index + 3);
}

string toArabic(string thai) {
    return _toArabic(thai, 0);
}

string toThai(string arabic) {
    string res = "";

    for (auto c : arabic) {
        string czero = zero;
        czero[2] += c - '0';
        res += czero;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << toThai(
        to_string(atoi(toArabic(a).c_str()) + atoi(toArabic(b).c_str())));
}
