#include <stdbool.h>
#include <stdio.h>

bool isPrime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0)
            return false;

        // if (i * i >= x)
        //     return true;
    }

    return true;
}

int solve(int n) {
    int current_prime = 2;
    int prime_index = 1;

    if (n == 1)
        return 2;

    while (prime_index < n) {
        int current_number = current_prime;

        while (!isPrime(++current_number)) {
        }

        current_prime = current_number;
        prime_index++;
    }

    return current_prime;
}

int main(void) {
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int n;
        scanf("%d", &n);
        int s = solve(n);
        printf("%lld\n", (long long)s * (long long)s);
    }
}
