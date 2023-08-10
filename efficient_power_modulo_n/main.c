#include <inttypes.h>
#include <assert.h>

// https://www.codewars.com/kata/52fe629e48970ad2bd0007e6
//
// Your task is to create a new implementation of modpow so that it computes (x^y)%n for large y.
// The problem with the current implementation is that the output of Math.pow is so large on our
// inputs that it won't fit in a 64-bit float.
// You're also going to need to be efficient, because we'll be testing some pretty big numbers.

typedef uint64_t u64;

u64 modpow(u64 x, u64 e, u64 n)
{
    if (n == 0)
        assert(1 == 0);
    if (x == 1)
        return 1;
    if (e == 0)
        return 1;
    if (e == 1)
        return x % n;
    if (x == n)
        return 0;
    
    if (x > n) {
        return modpow(x % n, e, n);
    }
    else {
        return ((e % 2 ? x : 1) * modpow(x * x, e / 2, n)) % n;
    }
}

int main(int argc, char* argv[]) {
    assert(modpow(2, 3, 5) == 3);
    assert(modpow(8, 4, 3) == 1);
    assert(modpow(9, 3, 4) == 1);
    assert(modpow(10, 3, 4) == 0);
    assert(modpow(17, 8, 5) == 1);
    assert(modpow(11, 10, 12) == 1);
    assert(modpow(11, 11, 12) == 11);
    assert(modpow(11, 10, 300) == 1);
    assert(modpow(11, 100000, 49) == 32);
    assert(modpow(5, 100000000, 19) == 5);
    assert(modpow(200, 3000, 10) == 0);
	assert(modpow(8132, 21302, 5) == 4);
	assert(modpow(8132, 21302, 1) == 0);
	assert(modpow(9, 193125, 37) == 26);
	assert(modpow(13, 81230123, 22) == 19);
	assert(modpow(29, 1013293125, 492) == 161);
	assert(modpow(31, 902938423012, 1023) == 961);

    return 0;
}