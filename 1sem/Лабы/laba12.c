#include <stdio.h>

int detect1st(int* number1, int number2)
{
    if (number2 >= 8) {
        *number1 = -1;
    } else {
        *number1 += number2 * 100;
        //printf("1st : %d, %d \n", *number1, number2);
    }
    return 0;
}

int detect2nd(int* number1, int number2)
{   
    if (*number1 == -1) {
        return 0;
    }

    int i = *number1;
    

    if ((i / 10) / 10 < number2) {
        *number1 += number2 * 10;
    } else {
        *number1 = -1;
    }
    return 0;
}

int detect3rd(int* number1, int number2)
{   
    if (*number1 == -1) {
        return 0;
    }

    int i = *number1;

    if ((i / 10) % 10 < number2) {
        *number1 += number2;
    } else {
        *number1 = -1;
    }
    return 0;

}

int Iteration(int* iteration)
{
    *iteration += 1;
    return 0;
}

int Delete(int* pair_1, int  pair_2, int* pair_3, int* pair_4, int* pair_5, int* pair_6, int* pair_7, int* pair_8)
{
    *pair_1 = 0; *pair_2 = 0; *pair_3 = 0; *pair_4 = 0;
    *pair_5 = 0; *pair_6 = 0; *pair_7 = 0; *pair_8 = 0;
    return 0;
}

int checkLeft(int* pair_1, int* pair_2, int* pair_3, int* pair_4, int* pair_5, int* pair_6, int* pair_7, int* pair_8)
{
    if (*pair_1 != -1 || *pair_2 != -1 || *pair_3 != -1 || *pair_4 != -1 || *pair_5 != -1 || *pair_6 != -1 || *pair_7 != -1 || *pair_8 != -1) {
        return 1;
    } else {
        return 0;
    }
}

int checkMax(int* pivet, int a, int b, int c, int d, int e, int f, int g)
{   
    if (*pivet != -1) {
        if ((*pivet >= a) && (*pivet >= b) && (*pivet >= c) && (*pivet >= d) 
         && (*pivet >= e) && (*pivet >= f) && (*pivet >= g)) {
            int t = *pivet;
            if ((t / 10) / 10 == 0) {
                printf("%d%d ", 0, *pivet);
            } else {
                printf("%d ", *pivet);
            }
            *pivet = -1;
        }
    }
    return 0; 
}

int main(void)
{
    char ch;
    int pair_1 = 0, pair_2 = 0, pair_3 = 0, pair_4 = 0;
    int pair_5 = 0, pair_6 = 0, pair_7 = 0, pair_8 = 0;

    int iteration = 0;

    while ((ch = getchar()) != EOF) {
        switch ( ch ) {
            case '+':
                break;
            case '-':
                break;
            case '\n':
                switch ( iteration ) {
                    case 0:
                        pair_1 = -1;
                        pair_2 = -1;
                        pair_3 = -1;
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 1:
                        pair_1 = -1;
                        pair_2 = -1;
                        pair_3 = -1;
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 2:
                        pair_1 = -1;
                        pair_2 = -1;
                        pair_3 = -1;
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 3:
                        pair_2 = -1;
                        pair_3 = -1;
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 4:
                        pair_3 = -1;
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 5:
                        pair_4 = -1;
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 6:
                        pair_5 = -1;
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 7:
                        pair_6 = -1;
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 8:
                        pair_7 = -1;
                        pair_8 = -1;
                        break;
                    case 9:
                        pair_8 = -1;
                        break;
                }

                while (checkLeft(&pair_1, &pair_2, &pair_3, &pair_4, &pair_5, &pair_6, &pair_7, &pair_8)) {
                    checkMax(&pair_1, pair_2, pair_3, pair_4, pair_5, pair_6, pair_7, pair_8);
                    checkMax(&pair_2, pair_1, pair_3, pair_4, pair_5, pair_6, pair_7, pair_8);
                    checkMax(&pair_3, pair_2, pair_1, pair_4, pair_5, pair_6, pair_7, pair_8);
                    checkMax(&pair_4, pair_2, pair_3, pair_1, pair_5, pair_6, pair_7, pair_8);
                    checkMax(&pair_5, pair_2, pair_3, pair_4, pair_1, pair_6, pair_7, pair_8);
                    checkMax(&pair_6, pair_2, pair_3, pair_4, pair_5, pair_1, pair_7, pair_8);
                    checkMax(&pair_7, pair_2, pair_3, pair_4, pair_5, pair_6, pair_1, pair_8);
                    checkMax(&pair_8, pair_2, pair_3, pair_4, pair_5, pair_6, pair_7, pair_1);
                }
                iteration = 0;
                Delete(&pair_1, &pair_2, &pair_3, &pair_4, &pair_5, &pair_6, &pair_7, &pair_8);
                printf("\n");
                break;
            default:
                ch -= 48;
                switch ( iteration ) {
                    case 0:
                        detect1st(&pair_1, ch);
                        Iteration(&iteration);
                        break;
                    case 1:
                        detect1st(&pair_2, ch);
                        detect2nd(&pair_1, ch);
                        Iteration(&iteration);
                        break;
                    case 2:
                        detect1st(&pair_3, ch);
                        detect2nd(&pair_2, ch);
                        detect3rd(&pair_1, ch);
                        Iteration(&iteration);
                        break;
                    case 3:
                        detect1st(&pair_4, ch);
                        detect2nd(&pair_3, ch);
                        detect3rd(&pair_2, ch);
                        Iteration(&iteration);
                        break;
                    case 4:
                        detect1st(&pair_5, ch);
                        detect2nd(&pair_4, ch);
                        detect3rd(&pair_3, ch);
                        Iteration(&iteration);
                        break;
                    case 5:
                        detect1st(&pair_6, ch);
                        detect2nd(&pair_5, ch);
                        detect3rd(&pair_4, ch);
                        Iteration(&iteration);
                        break;
                    case 6:
                        detect1st(&pair_7, ch);
                        detect2nd(&pair_6, ch);
                        detect3rd(&pair_5, ch);
                        Iteration(&iteration);
                        break;
                    case 7:
                        detect1st(&pair_8, ch);
                        detect2nd(&pair_7, ch);
                        detect3rd(&pair_6, ch);
                        Iteration(&iteration);
                        break;
                    case 8:
                        detect2nd(&pair_8, ch);
                        detect3rd(&pair_7, ch);
                        Iteration(&iteration);
                        break;
                    case 9:
                        detect3rd(&pair_8, ch);
                        Iteration(&iteration);
                        break;
                }
        }
    }
    return 0;
}
