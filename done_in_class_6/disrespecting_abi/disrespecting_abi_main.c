#include <stdio.h>

extern void bad_1(int a, int b);
extern int bad_2(int a, int b);

int main() {
    bad_1(1, 2);
    int bad_2_res = bad_2(1, 2);
    printf("from main, bad_2 of 1 and 2 is %d\n", bad_2_res);
    return 0;
}