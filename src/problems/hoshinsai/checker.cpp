#include <bits/stdc++.h>
using namespace std;

void unknown() {
    cout << 0;
    cerr << "Unknown Error! Maybe caused by Security Violation. Are you SUS?\n";
    exit(0);
}

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ifstream out(argv[2]);
    ifstream userout(argv[3]);

    string user_status;
    int judge_perf, user_perf;

    out >> judge_perf;
    userout >> user_status;

    if (user_status == "fail100") {
        cout << 0;
        cerr << "You call function more than 1,000,000 times in a test case";
        return 0;
    } else if (user_status == "wa") {
        cout << 0;
        cerr << "translate:wrong";
        return 0;
    } else if (user_status != "success") {
        unknown();
    }

    userout >> user_perf;

    string sus;
    userout >> sus;

    if (sus != "end")
        unknown();

    cerr << "Judge: " << judge_perf << ", User: " << user_perf << "\n";

    int full_threshold = ceil(1.03 * judge_perf);

    if (user_perf < full_threshold) {
        cout << "1\n";
    } else {
        cout << (2.0 * judge_perf) / (user_perf + judge_perf) << "\n";
    }
}
