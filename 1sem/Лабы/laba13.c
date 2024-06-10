#include <stdio.h>

int checkForIn(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 1u << (ch - 'A');
    } else if (ch >= 'a' && ch <= 'z') {
        return 1u << (ch - 'a');
    }
    return 0;
}

int main(void)
{
    int ch;
    int fond = 0;
    int state = 0;
    int record = 0;
    unsigned int sat = 0;
    unsigned int sit = ((1u << ('a' - 'a')) | (1u << ('i' - 'a')) | (1u << ('e' - 'a')) | (1u << ('o' - 'a')) | (1u << ('u' - 'a')));
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '\r') {
            if (state == 1 && record == 0) {
                sit = sit & sat;
                sat = 0;
                record = 1;
            }
        } else if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'I' || ch == 'E' || ch == 'O' || ch == 'U') {
            sat = sat | checkForIn(ch);
            if (state == 0) {
                state = 1;
            }
            record = 0;
        }
    }
    if (state == 1 && (sit != 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
