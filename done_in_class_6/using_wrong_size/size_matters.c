#include <stdio.h>

extern int dumb();

int main() {
    int a = dumb();
    printf("a is %d\n", a);
    return 0;
}