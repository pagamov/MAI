#include <stdio.h>
int main(void)
{
    int a;
    int b;
    int c = 0;
    scanf("%d", &a);

    while (a) {
        scanf("%d", &b);
        c = c + b;
        a--;
    }

    printf("%d\n", c);
    return (0);
}
