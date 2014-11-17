#ifndef LFSR_H
#define LFSR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define DSIZE 1024

typedef struct struct_LFSR {
	int descriptor[DSIZE];
	int initial_state[DSIZE];
	int len;
} LFSR;

void print_array(int arr[], int l);

void circular_shift_right(int arr[], int len);

void get_lfsr_output(LFSR *lfsr_in, int *lfsr_output, int howmany);

char c2b(char c);

void get_poly_str(int poly[], int n, char buffer[]);

int bma(int sequence[], int desc[], int n);


#endif