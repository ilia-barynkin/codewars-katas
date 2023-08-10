#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <memory.h>

int num_len(int num) {
    int res = 0;

    do {
        num /= 10;
        ++res;
    }
    while (num > 0);

    return res;
}

char *incrementString(const char *str)
{
    fprintf(stderr, "%s ", str);
    if (strlen(str) == 0) { 
        char* res = malloc(sizeof(char));
        strcpy(res, "1");
        fprintf(stderr, "%s\n", res);

        return res; 
    }

    int last_letter_ind = strlen(str) - 1;
    int prev_num = 0;
    int p = 1;

    while (last_letter_ind >= 0 && str[last_letter_ind] - '0' >= 0 && '9' - str[last_letter_ind] >= 0) {
        prev_num += p * (str[last_letter_ind] - '0');

        p *= 10;
        last_letter_ind--;
    }

    unsigned int res_num = prev_num + 1;
    char* res = calloc(sizeof(char), (last_letter_ind + 1) + num_len(res_num) + 1);
    memcpy(res, str, sizeof(char) * (last_letter_ind + 1));

    for (int i = last_letter_ind + 1; i < strlen(str) - num_len(res_num); ++i) {
        sprintf(res + i, "%d", 0);
    }

    sprintf(res + strlen(res), "%d", res_num);
    fprintf(stderr, "%s\n", res);
    
    return res;
}

int main(int argc, char* argv[]) {
    assert(strcmp(incrementString("foobar000"), "foobar001") == 0);
	assert(strcmp(incrementString("foobar999"), "foobar1000") == 0);
	assert(strcmp(incrementString("foobar001"), "foobar002") == 0);
	assert(strcmp(incrementString("foobar99"), "foobar100") == 0);
	assert(strcmp(incrementString("foobar099"), "foobar100") == 0);
	assert(strcmp(incrementString("foobar00999"), "foobar01000") == 0);
	assert(strcmp(incrementString("foo"), "foo1") == 0);
	assert(strcmp(incrementString("foobar001"), "foobar002") == 0);
	assert(strcmp(incrementString("foobar1"), "foobar2") == 0);
	assert(strcmp(incrementString("1"), "2") == 0);
	assert(strcmp(incrementString("009"), "010") == 0);
	assert(strcmp(incrementString(""), "1") == 0);
	assert(strcmp(incrementString("fo99obar99"), "fo99obar100") == 0);
    assert(strcmp(incrementString("foobar11"), "foobar12") == 0);
}