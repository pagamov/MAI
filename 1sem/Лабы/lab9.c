#include <stdio.h>

int ik;
int jk;
int lk;
int time;

int a_;
int b_;
int c_;

int mod_val(int a, int b)
{
    return (a % b + b) % b;
}

int div_val(int a, int b)
{
    return (a - mod_val(a, b)) / b;
}

int abs_val(int a)
{
    return (a < 0 ? -1 * a : a);
}

int sign_val(int a)
{
    return (a < 0 ? -1 : (a > 0 ? 1 : 0));
}

int min_val(int a, int b)
{
    return (a < b ? a : b);
}

int max_val(int a, int b)
{
    return (a > b ? a : b);
}

int i_next(int i, int j, int l, int k)
{
    return (mod_val((i * (min_val(j, l)) + j * min_val(i, l) + k * k), 20));
}

int j_next(int i, int j, int l, int k)
{
    return (mod_val(((mod_val(i, 10) - k) * (mod_val(j, 10) + k) * (mod_val(l, 10) - k)), 25));
}

int l_next(int i, int j, int l, int k)
{
    return (max_val(mod_val(min_val(i + j, i + l), 25), mod_val(max_val(i + l, j + k), 20)) + 10);
}

int f1(int i)
{
    return (-1 * i - 10);
}

int f2(int i)
{
    return (-1 * i - 20);
}

int main(void)
{
    scanf("%d%d%d", &ik, &jk, &lk);

    for (time = 0; time <= 50; time++) {
        
        if (f2(ik) <= jk && jk <= f1(ik)) {
            printf("%s\n", "Yes");
            printf("%d %d %d %d\n", ik, jk, lk, time);
            return 0;
        } else if (time == 50) {
            printf("%s\n", "No");
            printf("%d %d %d %d\n", ik, jk, lk, time);
            return 0;
        }
        a_ = i_next(ik, jk, lk, time);
        b_ = j_next(ik, jk, lk, time);
        c_ = l_next(ik, jk, lk, time);
        ik = a_;
        jk = b_;
        lk = c_;
    }
    return 0;
}
