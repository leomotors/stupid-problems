#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int primes[1000005] = {2, 3, 5};
int primes_size = 3;

bool isPrime(int x) {
    for (int i = 0; i < primes_size; i++) {
        if (x % primes[i] == 0)
            return false;

        if (primes[i] * primes[i] >= x)
            return true;
    }

    return true;
}

int main(void) {
    int Q;
    scanf("%d", &Q);

    while (primes_size <= 1000000) {
        int current = primes[primes_size - 1] + 2;

        while (!isPrime(current)) {
            current += 2;
        }

        primes[primes_size] = current;
        primes_size++;
    }

    for (int i = 0; i < Q; i++) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", (int64_t)primes[n - 1] * (int64_t)primes[n - 1]);
    }
}
