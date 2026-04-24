#ifndef BITSET_H
#define BITSET_H

struct bitset_s;

typedef struct bitset_s * bitset;

bitset create_bitset(int starting_value, int initial_size);
void add(bitset set, int v);
void remove(bitset set, int v);
char contains(bitset set, int v);


#endif