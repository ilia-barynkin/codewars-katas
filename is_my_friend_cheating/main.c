#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>

// https://www.codewars.com/kata/5547cc7dcad755e480000004
//
// A friend of mine takes the sequence of all numbers from 1 to n (where n > 0).
// Within that sequence, he chooses two numbers, a and b.
// He says that the product of a and b should be equal to the sum of all numbers in the sequence, 
// excluding a and b.
// Given a number n, could you tell me the numbers he excluded from the sequence?
//
// The function takes the parameter: n (n is always strictly greater than 0) and returns an 
// array or a string (depending on the language) of the form:
//
// [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or or [{a, b}, ...]
//
// with all (a, b) which are the possible removed numbers in the sequence 1 to n.
//
// [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ... will be sorted in increasing order of the "a".
//
// It happens that there are several possible (a, b). The function returns 
// an empty array (or an empty string) if no possible numbers are found which
// will prove that my friend has not told the truth! (Go: in this case return nil).
//
// removNb(26) should return  {{15, 21}{21, 15}} tested by way of strings.
// Function removNb should return a pointer to an allocated array of Pair pointers, 
// each one also allocated. 

typedef long long u64;
typedef struct pair pair;

struct pair {
    u64 first;
    u64 snd;
};

pair** removNb(u64 n, int* length) {
    u64* res_f = calloc(n, sizeof(u64));
    u64* res_s = calloc(n, sizeof(u64));
    u64 N = (n + n * n) / 2 + 1;
    int l = 0;
    u64 upper_bound = sqrt(N);
    
    for (u64 i = N / (n + 1); i <= upper_bound; ++i) {
        if (N % i == 0) {
            res_f[l] = i - 1; 
            res_s[l++] = (N / i) - 1;
        }
    }

    *length = l*2;

    pair** res_pairs = malloc((*length) * sizeof(pair*));

    for (int i = 0; i < l; ++i) {
        res_pairs[i] = malloc(sizeof(pair));
        *res_pairs[i] = (pair) {
            .first = res_f[i],
            .snd = res_s[i]
        };

        res_pairs[l * 2 - i - 1] = malloc(sizeof(pair));
        *res_pairs[l * 2 - i - 1] = (pair) {
            .first = res_s[i],
            .snd = res_f[i]
        };
    }

    return res_pairs;
}

void test_print(u64 n) {
    int length = 0;
    pair **res = removNb(n, &length);

    for (int i = 0; i < length; ++i) {
        printf("{%lld, %lld} ", res[i]->first, res[i]->snd);
        free(res[i]);
    }

    printf("\r\n");

    free(res);
}

int main(int argc, char* argv) {

    test_print(26);
    test_print(100);
    test_print(37);
    test_print(101);

    return 0;
}