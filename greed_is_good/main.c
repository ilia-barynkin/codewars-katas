#include <assert.h>

#define THROWS 5
#define DICE_SIDES 6
#define DICE_NOMINAL(i) i - 1

int score(const int dice[THROWS]) {
    int scores[DICE_SIDES] = {0};

    for (int i = 0; i < THROWS; ++i) {
        ++scores[DICE_NOMINAL(dice[i])];
    }
    
    int res = (scores[DICE_NOMINAL(1)] / 3) * 1000 +
        (scores[DICE_NOMINAL(6)] / 3) * 600 +
        (scores[DICE_NOMINAL(5)] / 3) * 500 +
        (scores[DICE_NOMINAL(4)] / 3) * 400 +
        (scores[DICE_NOMINAL(3)] / 3) * 300 +
        (scores[DICE_NOMINAL(2)] / 3) * 200 +
        (scores[DICE_NOMINAL(1)] % 3) * 100 + 
        (scores[DICE_NOMINAL(5)] % 3) * 50;
    
    return res;
}

int main(int argc, char* argv[]) {
    {
        const int dice[5] = {2, 3, 4, 6, 2};
        assert(score(dice) == 0);
    }
    {
        const int dice[5] = {4, 4, 4, 3, 3};
        assert(score(dice) == 400);
    }
    {
        const int dice[5] = {2, 4, 4, 5, 4};
        assert(score(dice) == 450);
    }

    return 0;
}