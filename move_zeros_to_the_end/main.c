#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
    // mutate arr in place

    int zero_count = 0;

    for (int i = 0; i < len; ++i) {
        if (arr[i] == 0) {
            ++zero_count;
        }
        else {
            arr[i - zero_count] = arr[i];
        }
    }

    for (int i = len - zero_count; i < len; ++i) {
        arr[i] = 0;
    }
}

int main(int argc, char* argv[]) 
{
    int* arr;
    move_zeros(8, arr = ((int []) {0, 1, 0, 2, 0, 3, 4, 5})); // ((int []) {1, 2, 3, 4, 5, 0, 0, 0});
    // move_zeros(20, arr = ((int []) {9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9}), ((int []) {9, 9, 1, 2, 1, 1, 3, 1, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    // move_zeros(2, arr = ((int []) {0, 0}), ((int []) {0, 0}));
    // move_zeros(1, arr = ((int []) {0}), ((int []) {0}));
    // move_zeros(0, arr = ((int []) {}), ((int []) {}));

    return 0;
}
