#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <memory.h>
#include <assert.h>

// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/train/c
// 
// The Fibonacci numbers are the numbers in the following integer sequence (Fn):
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
// such as
// F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.
// Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying
// F(n) * F(n+1) = prod.
// Your function productFib takes an integer (prod) and returns an array:
// [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
// depending on the language if F(n) * F(n+1) = prod.
// If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return
// [F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
// F(n) being the smallest one such as F(n) * F(n+1) > prod.

typedef unsigned long long ull;

ull* productFib(ull prod) {
    ull* res = malloc(sizeof(ull) * 3);
    memcpy(res, (ull []){0,0,0}, 3 * sizeof(ull));
    ull prev = 0;
    ull nth = 1;
    int i = 1;
    bool w_rem = false; // if prod devides with F(n) without a reminder

    while (true) {
        ull nth_t = prev + nth;

        if (prod % nth_t == 0) {
            if (prod == nth_t * nth) {
                memcpy(res, (ull []){nth, nth_t, 1}, 3 * sizeof(ull));
                return res;
            }
            w_rem = true;
        }

        if (nth_t * nth > prod) {
            memcpy(res, (ull []){nth, nth_t, 0}, 3 * sizeof(ull));
                return res;
        }

        prev = nth;
        nth = nth_t;
        ++i;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    ull* res = productFib(74049690);
    assert(res[0] == 6765 && res[1] == 10946 && res[2]);

    return 0;
}