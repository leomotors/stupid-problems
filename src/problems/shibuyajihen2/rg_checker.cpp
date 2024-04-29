#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ifstream out(argv[3]);
    ifstream userout(argv[2]);

    int sol;
    out >> sol;

    int user_out;
    userout >> user_out;

    if (user_out < 1 || user_out > 4) {
        cout << "Invalid Output" << endl << "0" << endl;
        return 0;
    }

    int primes[] = {2, 3, 5, 7};
    int userAns = primes[user_out - 1];

    if (sol % userAns == 0) {
        cout << "Correct" << endl << "100" << endl;
    } else {
        cout << "Incorrect" << endl << "0" << endl;
    }
}
