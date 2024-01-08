#include <iostream>
#include <string>

std::string s(int n) {
    return std::string(n, '#');
}

std::string t(int n) {
    return std::string(1, ' ');
}

int main() {
    int n;
    std::cin >> n;

    using std::cout;

    cout << "#" << t(2 * n - 3) << "#\n";

    for (int i = 1; i <= 2 * n - 3; i++) {
        cout << "#" << t(i - 1) << "#" << t(2 * n - 3 - i) << "#\n";
    }

    cout << "#" << t(2 * n - 3) << "#\n";
}
