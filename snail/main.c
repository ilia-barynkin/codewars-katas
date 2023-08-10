#include <stdlib.h>
#include <stdio.h>

// https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1
//
// Snail Sort
//
// Given an n x n array, return the array elements arranged from outermost elements 
// to the middle element, traveling clockwise.
//
// array = [[1,2,3],
//          [4,5,6],
//          [7,8,9]]
// snail(array) #=> [1,2,3,6,9,8,7,4,5]
//
// For better understanding, please follow the numbers of the next array consecutively:
//
// array = [[1,2,3],
//          [8,9,4],
//          [7,6,5]]
// snail(array) #=> [1,2,3,4,5,6,7,8,9]

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
    *outsz = cols*rows;
    if (cols==rows==0) return 0;

    int* res = calloc(rows*cols, sizeof(int));
    int trn = 0;
    int offset = 0;
    size_t k = 0;
    
    while(k < cols * rows) {
        switch (trn % 4) {
            case 0: {
                for (int i = offset; i < cols - offset; ++i)
                    res[k++] = mx[offset][i];
                
                break;
            }
            case 1: {
                for (int j = offset + 1; j < rows - offset; ++j)
                    res[k++] = mx[j][cols - 1 - offset];
                
                break;
            }
            case 2: {
                for (int i = cols - offset - 2; i >= offset; --i)
                    res[k++] = mx[rows - offset - 1][i];
                
                break;
            }
            case 3: {
                for (int j = rows - offset - 2; j > offset; --j)
                    res[k++] = mx[j][offset];
                
                ++offset;

                break;
            }
        }

        ++trn;
    }
    
    return res;
}

int main(int argc, char *argv[]) {
    
    int **m = calloc(3, sizeof(int*));
    for (int i = 0; i < 3; ++i) {
        m[i] = calloc(3, sizeof(int));
        for (int j = 0; j < 3; j++) {
            m[i][j] = i * 3 + j + 1;
        }
    }
    size_t out = 0;
    int* res1 = snail(&out, m, 3, 3);

    for (int i = 0; i < out; ++i) {
        printf("%d ", res1[i]);
    }
}