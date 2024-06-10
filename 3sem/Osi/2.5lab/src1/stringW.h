// Gamov Pavel
// м80-207б-18
// https://github.com/pagamov/Osi.git
// stringW.h
int charToInt(char * string) {
    int i = 0, res = 0;
    if (string[i] == '-') i++;
    while (string[i] != '\0') {
        res *= 10;
        res += string[i] - '0';
        i++;
    }
    return res;
}

char * revers(char * c) {
    char * v = (char *)malloc(sizeof(char) * 32);
    int i = 0, size = 0;
    while (c[size] != '\0') {
        size++;
    }
    size--;
    while (size != -1) {
        v[i++] = c[size--];
    }
    v[i] = '\0';
    return v;
}

char * intToChar(int number) {
    if (number == 0)
        return "0\0";
    char c[32];
    int sign = 0, piv = number, i = 0;
    if (number < 0) {
        sign = 1;   piv *= -1;
    }
    while (piv != 0) {
        c[i++] = '0' + piv % 10;    piv /= 10;
    }
    if (sign)   c[i++] = '-';
    c[i] = '\0';
    return revers(c);
}

int isNumber(char * mess) {
    if (mess == NULL) return 0;
    int i = 0;
    while (mess[i] != '\0') {
        if (mess[i] > '9' || mess[i] < '0') {
            return 0;
        }
        i++;
    }
    return 1;
}
