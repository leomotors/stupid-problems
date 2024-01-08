#include <stdio.h>

void s() {
    printf("#");
}

void endl() {
    printf("\n");
}

void t(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    s();
    t(2 * n - 3);
    s();
    endl();

    for (int i = 2; i <= 2 * n - 2; i++) {
        s();
        t(i - 2);
        s();
        t(2 * n - 2 - i);
        s();
        endl();
    }

    s();
    t(2 * n - 3);
    s();
    endl();
}
