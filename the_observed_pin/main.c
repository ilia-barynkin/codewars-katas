#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// https://www.codewars.com/kata/5263c6999e0f40dee200059d

// Alright, detective, one of our colleagues successfully observed our target person, 
// Robby the robber. We followed him to a secret warehouse, where we assume to find 
// all the stolen stuff. The door to this warehouse is secured by an electronic combination lock.
// Unfortunately our spy isn't sure about the PIN he saw, when Robby entered it.
//
// The keypad has the following layout:
//
// ┌───┬───┬───┐
// │ 1 │ 2 │ 3 │
// ├───┼───┼───┤
// │ 4 │ 5 │ 6 │
// ├───┼───┼───┤
// │ 7 │ 8 │ 9 │
// └───┼───┼───┘
//     │ 0 │
//     └───┘
//
// He noted the PIN 1357, but he also said, it is possible that each of the digits 
// he saw could actually be another adjacent digit (horizontally or vertically, but not diagonally). 
// E.g. instead of the 1 it could also be the 2 or 4. And instead of the 5 it could 
// also be the 2, 4, 6 or 8.
//
// He also mentioned, he knows this kind of locks. You can enter an unlimited amount of wrong PINs,
// they never finally lock the system or sound the alarm. That's why we can try 
// out all possible (*) variations.

// * possible in sense of: the observed PIN itself and all variations considering the adjacent digits

// Function should return an array of c-strings with all possible PINs.
// It must allocate all required meomry, but there are no requirements
// as to how it should be done. It must be possible to free
// allocated memo_adjry with a call to free_pins.
// Upon return, count should contain the amount of returned PINs.

const char** get_pins(const char* observed, size_t* count) {
    if (*observed == '\0')
    {
        *count = 0;
        return NULL;
    }

    static char* memo_adj[10];

    if (!memo_adj[0]) {
        memo_adj[0] = malloc(3 * sizeof(char));
        strcpy(memo_adj[0], "08");
    }
    
    int curr_num = *observed - '0';
    
    if (!memo_adj[curr_num]) {
        memo_adj[curr_num] = malloc(sizeof(char) * 6);
        int rn = (curr_num - 1) / 3;
        int cn = (curr_num - 1) % 3;
        int k = 0;

        for (int r = rn - 1; r <= rn + 1; ++r) {
            for (int c = cn - 1; c <= cn + 1; ++c) {
                if (c >= 0 && c < 3 && r >= 0 && r <= 3 // if on the panel
                    && abs(r - rn) + abs(c - cn) != 2) { // if not diagonal
                    char adj_num = (r * 3 + c + 1);
                    if (adj_num == 10 || adj_num == 12) continue;
                    memo_adj[curr_num][k++] = '0' + adj_num % 11;
                }
            }
        }
    }

    char **res;

    if (strlen(observed) == 1) {
        res = calloc(strlen(memo_adj[curr_num]), sizeof(char*));
        *count = strlen(memo_adj[curr_num]);
        
        for (int i = 0; i < strlen(memo_adj[curr_num]); ++i) {
            res[i] = calloc(2, sizeof(char));
            res[i][0] = memo_adj[curr_num][i];
        }

        return res;
    }

    size_t inner_count = 0;
    char **next_combinations = get_pins(observed + sizeof(char), &inner_count);
    *count = strlen(memo_adj[curr_num]) * (inner_count == 0 ? 1 : inner_count);
    res = calloc(*count, sizeof(char*));

    for (int i = 0; memo_adj[curr_num][i] != '\0'; ++i) 
    {
        for (int j = 0; j < inner_count; ++j) {
            res[i * inner_count + j] = calloc(strlen(observed) + 1, sizeof(char));
            sprintf(res[i * inner_count + j], "%c%s", memo_adj[curr_num][i], next_combinations[j]);
        }
    }

    if (next_combinations)
        free(next_combinations);

    return res;
}

// This function will be called once per every call to get_pins
// with a pointer value returned by such call.

void free_pins(const char ** pins) {
    free(pins);
}

int main(int argc, char* argv[]) 
{
    const char* observed = "369";
    size_t expected_count = 36;
    const char *const expected_pins3[] = { "236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699" };


    size_t count;
    char** actual_pins = get_pins(observed, &count);

    if (count != expected_count) {
        int a = 0;
    }

    for (int i = 0; i < count; ++i) {
        char* curr_pin = actual_pins[i];
        bool found = false;
        for (int j = 0; j < count; ++j) {
            if (strcmp(actual_pins[i], expected_pins3[j]) == 0) {
                found = true;
            }
        }

        if (!found) {
            int b = 0;
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("\"%s\"", actual_pins[i]);
        if (i != count -1) printf(", ");
    }

    printf("\n");

    free_pins(actual_pins);

    return 0;
}