#include <stdio.h>

typedef char boolean;

#define TRUE 1
#define FALSE 0

extern boolean isEven(int value);
extern boolean isOdd(int value);
extern int max(int a, int b);

extern boolean not(boolean a);
extern boolean and(boolean a, boolean b);
extern boolean or(boolean a, boolean b);
extern boolean xor(boolean a, boolean b);

int main() {
    int a = 5;
    boolean a_is_even = isEven(a); 
    printf("is a (%d) an even number? %d\n", a, a_is_even);
    boolean a_is_odd = isOdd(a);
    printf("is a (%d) an odd number? %d\n", a, a_is_odd);
    int b = 3;
    boolean max_of_a_and_b = max(a, b);
    boolean c = TRUE;
    boolean d = FALSE;
    boolean not_c = not(c);
    boolean not_d = not(d);
    boolean and_c_d = and(c, d);
    boolean or_c_d = or(c, d);
    boolean xor_c_d = xor(c, d);
    printf("c %d, d %d, not_c %d, not_d %d\n", c, d, not_c, not_d);
    printf("and_c_d %d, or_c_d %d, xor_c_d %d\n", and_c_d, or_c_d, xor_c_d);
    return 0;
}