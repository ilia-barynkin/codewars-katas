#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// https://www.codewars.com/kata/55983863da40caa2c900004e/train/c
//
// Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:
//
// 12 ==> 21
// 513 ==> 531
// 2017 ==> 2071
//
// nextBigger(num: 12)   // returns 21
// nextBigger(num: 513)  // returns 531
// nextBigger(num: 2017) // returns 2071
//
// If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift):
//
// 9 ==> -1
// 111 ==> -1
// 531 ==> -1

#define MAX_LEN 21

long long next_bigger_number(long long n) {
    char* ts = calloc(MAX_LEN, sizeof(char));
    size_t l = 0;
    size_t sec_least_ind = -1;
    
    while (n > 0 && sec_least_ind == -1) {
        int rem = n % 10;
        
        for (int i = 0; i < l; ++i) {
            if (ts[i] - '0' > rem && (ts[i] < ts[sec_least_ind] || sec_least_ind == -1)) {
                sec_least_ind = i;
            }
        }

        ts[l++] = '0' + rem;
        n /= 10;
    }

    if (sec_least_ind == -1) {
        free(ts);
        return -1;
    }

    char mem = ts[l-1];
    ts[l-1] = ts[sec_least_ind];
    ts[sec_least_ind] = mem;

    for (int i = 0; i < l - 1; ++i) {
        for (int j = i + 1; j < l - 1; ++j) {
            if (ts[j] > ts[i]) {
                char swap = ts[i];
                ts[i] = ts[j];
                ts[j] = swap;
            }
        }
    }

    for (int i = 0; i < l; ++i) {
        n = n * 10 + (ts[l - i - 1] - '0');
    }

    free(ts);

    return n;
}

int main(int argc, char* argv[]) {
    assert(next_bigger_number(12) == 21);
    assert(next_bigger_number(513) == 531);
    assert(next_bigger_number(2017) == 2071);
    assert(next_bigger_number(414) == 441);
    assert(next_bigger_number(144) == 414);
    assert(next_bigger_number(10990) == 19009);

    return 0;
}