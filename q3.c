/**
 * Let's break this LFSR!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "lfsr.h"

#define MAX_SIZE 1024

void usage(char *name) {
	// TODO
}

int main(int argc, char *argv[]) {
	/**
	 * Steps:
	 * 1) Get 40 bits
	 * 2) XOR them with "AGREE"
	 * 3) Use the candidate key stream to generate the LFSR
	 * 4) Use the candidate key to generate a sequence and see if it contains "AGREE"
	 * 5) If so you found the key and the LFSR
	 */

	return 0;
}