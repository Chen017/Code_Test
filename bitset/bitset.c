#include "bitset.h"

#define REP_SIZE 64

struct bitset_s {
    long * array;
    int starting_value;
    int capacity;
    int elems;
};

bitset create_bitset(int starting_value, int initial_size) {
    //TODO: complete
}

static int calculate_capacity(int initial_size, int rep_size) {
    return (initial_size / rep_size) + (initial_size % rep_size != 0?1:0);
}

void add(bitset set, int v) {
    //TODO: complete
}

void remove(bitset set, int v) {
    //TODO: complete
}

long contains(bitset set, int v) {
    //TODO: complete
}