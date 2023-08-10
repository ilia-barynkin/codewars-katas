#include <stdlib.h>
#include <string.h>
#include <assert.h>

int last_digit(const char *a, const char *b)
{
    if (!strcmp(b, "0")) return 1;

    int base = a[strlen(a) - 1] - '0';
    int period = 1;
    int product_last_digit = base;

    for (;;++period)
    {
        product_last_digit = product_last_digit * base % 10;
        if (product_last_digit == base) break;
    }

    if (period == 1) return base;

    int power = 0;

    if (period == 2) power = b[strlen()]

    int remainder = power % period;
    if (remainder == 0) remainder = period;
    int res = base;

    for (int i = 1; i < remainder; ++i) {
        res = res * base % 10;
    }
    
    return res;
}

int main(int argc, int **argv) {
    int res = last_digit("18252", "300552066198");
}