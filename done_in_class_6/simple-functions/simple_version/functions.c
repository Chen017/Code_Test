typedef unsigned char boolean;

#define TRUE 1
#define FALSE 0

boolean isEven(int value) {
    return value % 2 == 0;
}

boolean isOdd(int value) {
    return value % 2 == 1;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

boolean not(boolean a) {
    return !a;
}

boolean and(boolean a, boolean b) {
    return a && b;
}

boolean or(boolean a, boolean b) {
    return a || b;
}

boolean xor(boolean a, boolean b) {
    return a ^ b;
}