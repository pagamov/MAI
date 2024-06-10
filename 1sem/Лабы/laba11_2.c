#include <stdio.h>

int main(void)
{
    int ch;
    int state = 0;
    int wordCount = 0;
    while ((ch = getchar()) != EOF) {
        if (state == 11 && ch != '*') {
            state = 0;
        }
        if (state == 14 && ch == ')') {
            state = 0;
        } else if (state == 14 && ch != ')') {
            wordCount += 1;
            state = 13;
        }
        if (state == 15 && ch == ')') {
            state = 0;
        } else if (state == 15 && ch != ')') {
            state = 13;
        }
        switch (ch) {
            case '{':
                if (state == 0) {
                    state = 2;
                }
                break;
            case ' ':
                if (state == 3) {
                    state = 2;
                } else if (state == 13) {
                    state = 12;
                }
                break;
            case '\n':
                if (state == 3) {
                    state = 2;
                } else if (state == 13) {
                    state = 12;
                }
                break;
            case '\t':
                if (state == 3) {
                    state = 2;
                } else if (state == 13) {
                    state = 12;
                }
                break;
            case '}':
                if (state == 3 || state == 2) {
                    state = 0;
                }
                break;
            case '(':
                if (state == 0) {
                    state = 11;
                }
                break;
            case '*':
                if (state == 2) {
                    state = 3;
                    wordCount += 1;
                }
                if (state == 11) {
                    state = 12;
                } else if (state == 12) {
                    state = 14;
                } else if (state == 13) {
                    state = 15;
                }
                break;
            default:
                if (state == 2) {
                    wordCount += 1;
                    state = 3;
                } else if (state == 12) {
                    state = 13;
                    wordCount += 1;
                }
                break;
        }
    }
    printf("\n%d\n", wordCount);
    return 0;
}
