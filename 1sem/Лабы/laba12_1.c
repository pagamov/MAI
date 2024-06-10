#include <stdio.h>

int main(void)
{
    int ch;
    while ((scanf("%d", &ch)) != -1) {
        if (ch == -2147483648) {
            printf("147\n");
            continue;
        } else {
            if (ch < 0) {
                ch = -ch;
            }
        }
        while (ch > 0) {
            int input = ch % 1000;
            if (((input / 10) / 10) == 0) {
                if (ch > 100) {
                    if (((input % 10) > ((input / 10) % 10)) && (((input / 10) % 10) > (((input / 10) / 10) % 10))) {
                        printf("0%d ", input);
                    }
                    ch = ch / 10;
                } else {
                    ch = ch / 10;
                }
            } else if ((input / 10) / 10 != 0) {
                if (((input % 10) > ((input / 10) % 10)) && (((input / 10) % 10) > (((input / 10) / 10) % 10))) {
                    printf("%d ", input);
                }
                ch = ch / 10;
            }
        }
        printf("\n");
    }
    return 0;
}
