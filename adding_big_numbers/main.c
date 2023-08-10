#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

// https://www.codewars.com/kata/525f4206b73515bffb000b21

// We need to sum big numbers and we require your help.
// Write a function that returns the sum of two numbers. 
// The input numbers are strings and the function must return a string.

// Example
// add("123", "321"); // returns "444"
// add("11", "99");   // returns "110"
//
// Notes
// The input numbers are big.
// The input is a string of only digits
// The numbers are positives

char *add(const char *a, const char *b) 
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char* res = malloc(sizeof(char) * (max_len + 1));
    char mem = 0;

    for (int i = 0; i < max_len; ++i) {
        char term_a = len_a - 1 - i < 0 ? 0 : a[len_a - 1 - i] - '0';
        char term_b = len_b - 1 - i < 0 ? 0 : b[len_b - 1 - i] - '0';
        char sum = term_a + term_b + mem;
        res[max_len - 1 - i] = (sum % 10) + '0';
        mem = sum / 10;
    }

    res[max_len] = '\0';

    if (mem) {
        char* bigger_res = malloc((strlen(res) + 2) * sizeof(char));
        strcpy(bigger_res, "1");
        strcat(bigger_res, res);
        free(res);
        return bigger_res;
    }
    
    return res;
}

int main(int argc, char* argv[]) 
{
    assert(strcmp(add("36294500649", "5175666562665014609"), "5175666598959515258") == 0);
    return 0;
}