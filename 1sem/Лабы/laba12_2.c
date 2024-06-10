#include <stdio.h>

int WorkWithNumber(int ch)
{
    if (ch <= 0) {
        return 0;
    } else {
        int input = ch % 1000;
        if (((input / 10) / 10) == 0) {
            if (ch > 100) {
                if (((input % 10) > ((input / 10) % 10)) && (((input / 10) % 10) > (((input / 10) / 10) % 10))) {
                    printf("0%d ", input);
                }
                ch = ch / 10;
                WorkWithNumber(ch);
                
            } else {
                ch = ch / 10;
                WorkWithNumber(ch);
            }
        } else if ((input / 10) / 10 != 0) {
            if (((input % 10) > ((input / 10) % 10)) && (((input / 10) % 10) > (((input / 10) / 10) % 10))) {
                printf("%d ", input);
            }
            ch = ch / 10;
            WorkWithNumber(ch);
        }
    }
    return 0;
}

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
        WorkWithNumber(ch);
        printf("\n");
    }
    return 0;
}
