#include <math.h>

unsigned int sum_of_squares(unsigned int n){
    unsigned int nn = n;
    unsigned int res = 0;
    
    while(nn > 0) {
        while (nn % 4 == 0)
            nn /= 4;

        unsigned int sr = sqrt((double)nn);
        nn -= sr * sr;

        ++res;
    }

    return res;
}

int main(int argc, char* argv[]) {
    unsigned int r0 = sum_of_squares(661915700);

    return 0;

}