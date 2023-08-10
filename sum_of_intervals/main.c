#include <stdlib.h>
#include <assert.h>

struct interval {
    int first;
    int second;
};

int sum_intervals(const struct interval *v, size_t n)
{
    struct interval t = v[0];
    int offset = 0;

    for (int i = 1; i < n; ++i) {
        const struct interval* left = 0;
        const struct interval* right = 0;

        if (t.first <= v[i].first) {
            left = &t;
            right = &v[i];
        }
        else {
            left = &v[i];
            right = &t;
        }
        
        if (left->first <= right->first && left->second >= right->second)
            continue;
        
        int len = (right->second + offset) - left->first - (right->first - left->second);
        offset += right->first > left->second ? right->first - left->second : 0;
        t.second = t.first + len;
    }

    return t.second - t.first;
}

int main(int argc, char* argv[]) {
    //assert(sum_intervals((const struct interval[]){{1, 5}, {6, 10}}, 2) == 8);
    //assert(sum_intervals((const struct interval[]){{-5, -1}, {1, 5}}, 2) == 8);
    //assert(sum_intervals((const struct interval[]){{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}}, 5ul) == 19);

    assert(sum_intervals((const struct interval[]){{1, 5}, {10, 20}, {1, 6}, {16, 19}}, 4) == 17);

    return 0;
}