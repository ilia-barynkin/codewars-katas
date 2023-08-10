#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

// https://www.codewars.com/kata/54eb33e5bc1a25440d000891/train/c
//
// Given a positive integral number n, return a strictly increasing sequence 
// (list/array/string depending on the language) of numbers, so that the sum of the squares 
// is equal to n².
//
// If there are multiple solutions (and there will be), return as far as possible the result 
// with the largest possible values:
// Examples
// decompose(11) must return [1,2,4,10]. Note that there are actually two ways to 
// decompose 11², 11² = 121 = 1 + 4 + 16 + 100 = 1² + 2² + 4² + 10² but don't return [2,6,9], 
// since 9 is smaller than 10.
// For decompose(50) don't return [1, 1, 4, 9, 49] but [1, 3, 5, 8, 49] since [1, 1, 4, 9, 49] 
// doesn't form a strictly increasing sequence.

#define RES_LEN 256
#define SQR(x) x * x
#define REM 2 * (n - 1) + 1

typedef long long u64;

char* decompose(u64 n) {
    char* res = malloc(RES_LEN * sizeof(char));
    strcpy(res, "[]");

    for (u64 x = sqrt(REM); x > 0; --x) {
        for (u64 y = sqrt(REM - SQR(x)); y >= 0 && x > y; --y) {
            for (u64 z = sqrt(REM - SQR(y) - SQR(x)); z >= 0 && y > z; --z) {
                for (u64 w = sqrt(REM - SQR(z) - SQR(y) - SQR(x)); w >= 0 && z > w; --w) {
                    if (REM - SQR(x) - SQR(y) - SQR(z) - SQR(w) == 0) {
                        sprintf(res, "[%llu, %llu, %llu, %llu, %llu]", w, z, y, x, n - 1);
                        return res;
                    }
                }
            }
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    assert(strcmp(decompose(5), "[1,3,5,8,49]") == 0);
    return 0;
}