#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int Q;
    char id[15];

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf("%s", id);

        printf(rand() < RAND_MAX / 2 ? "Y\n" : "N\n");
    }
}