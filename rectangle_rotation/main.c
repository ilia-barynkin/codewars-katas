#include <math.h>
#include <assert.h>

// https://www.codewars.com/kata/5886e082a836a691340000c3
//
// Task
//
// A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. 
// Its center (the intersection point of its diagonals) coincides with the point (0, 0), 
// but the sides of the rectangle are not parallel to the axes; instead, they are forming 
// 45 degree angles with the axes.
//
// How many points with integer coordinates are located inside the given rectangle 
// (including on its sides)?
//
// Example
// For a = 6 and b = 4, the output should be 23
//
// The following picture illustrates the example, and the 23 points are marked green.

long long rectangle_rotation(int a, int b)
{
    long long main_a, sec_a, main_b, sec_b = 0;
    long long max_a = (double)a / sqrt(2.0);

    if (max_a % 2 == 0) {
        main_a = max_a + 1;
        sec_a = max_a;
    }
    else {
        sec_a = max_a + 1;
        main_a = max_a;
    }

    long long max_b = (double)b / sqrt(2.0);

    if (max_b % 2 == 0) {
        main_b = max_b + 1;
        sec_b = max_b;
    }
    else {
        sec_b = max_b + 1;
        main_b = max_b;
    }

    return main_a * main_b + sec_a * sec_b;
}

int main(int argc, char* argv[]) {
    assert(rectangle_rotation(6,4) == 23);
    assert(rectangle_rotation(30,2) == 65);
    assert(rectangle_rotation(8,6) == 49);
    assert(rectangle_rotation(16,20) == 333);

    return 0;
}