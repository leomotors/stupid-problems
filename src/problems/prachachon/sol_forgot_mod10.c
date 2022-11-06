#include <stdbool.h>
#include <stdio.h>

bool isValid(char *id) {
    int sum = 0;

    for (int i = 0; i < 12; i++) {
        sum += (id[i] - '0') * (13 - i);
    }

    sum %= 11;
    sum = 11 - sum;
    // sum %= 10;

    return sum == (id[12] - '0');
}

int main(void) {
    int Q;
    scanf("%d", &Q);

    char id[15];

    for (int i = 0; i < Q; i++) {
        scanf("%s", id);

        if (isValid(id)) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
}
