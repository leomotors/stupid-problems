#include <stdint.h>
#include <stdio.h>

int main(void) {
    int64_t x;
    scanf("%lld", &x);

    switch (x) {
    case 1:
        printf("Chipi Chipi\n");
        break;
    case 2:
        printf("Chapa Chapa\n");
        break;
    case 3:
        printf("Dubi Dubi\n");
        break;
    case 4:
        printf("Daba Daba\n");
        break;
    case 25:
        printf("asahina senpai, wonderhoy\n");
        break;
    case 1983:
        printf("is that the bite of 87\n");
        break;
    case 1987:
        printf("freddy fazbear\n");
        break;
    default:
        printf("CEO entrepreneur\n");
    }
}
