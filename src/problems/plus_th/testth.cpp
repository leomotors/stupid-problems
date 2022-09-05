#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<string> nums = {"๐", "๑", "๒", "๓", "๔", "๕", "๖", "๗", "๘", "๙"};

    vector<std::string> chars = {"ก", "ข", "ค"};

    for (auto alphabet : chars) {
        std::cout << "Inspecting: " << alphabet << "\n";

        for (auto c : alphabet) {
            std::cout << c << " -> " << static_cast<int>(c) << "\n";
        }
    }

    // string a = "ก";
    // cout << 0 << " " << a << "\n";
    // for (int i = 1; i < 46; i++) {
    //     a[2]++;
    //     cout << i << " " << a << "\n";
    // }
    // cout << "\n";
}
