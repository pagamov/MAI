#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int c = 0;
    scanf("%d", &a);
    while (a) {
        scanf("%d", &b);
        if (b >= 10) {
            c += b;
        }
        a--;
    }
    printf("%d\n", c);
    return (0);
}