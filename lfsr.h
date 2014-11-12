#ifndef LFSR_H
#define LFSR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define DSIZE 1000000

typedef struct struct_LFSR {
	char descriptor[DSIZE];
	char initial_state[DSIZE];
} LFSR;

void circular_shift_right(char arr[]);

void get_lfsr_output(LFSR *lfsr_in, char *lfsr_output, int howmany);

#endif