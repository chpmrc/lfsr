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

#define BIN_SEQ "000101010110011111010011110010100011101010110111101000111111101010010111011101011001110101110101001010010111111101101000011110110011100101100011111010000000010101101000100011100110101111010000000100110101111010010010101011111011011011100100101001011001111011111101101011110111101101000101000101011010000010011000000001000100001001001001111101100001101110001100010101001101100101111000101101110010011000001100000001100101111111001000000100000100111000100011010000011111111111010101011110010001011011101001110001010011100101011011011111100101000000101110101001101110011011110010111111001000101000100111110010001110001011001001011100101111100010000111100101101101010010110100101010110101011110001010010000111000110101000110010101111010001100001110"

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

	// char test_str[] = "AGREE";
	// char seq_str[MAX_SIZE] = BIN_SEQ;
	// int seq_int[MAX_SIZE];
	// int sub_seq_int[MAX_SIZE];
	// int test_desc[MAX_SIZE];
	// int i, j, len;

	// memset(seq_int, 0, MAX_SIZE);
	// memset(test_desc, 0, MAX_SIZE);

	// for (i = 0; i < strlen(seq_str); i++) {
	// 	seq_int[i] = c2b(seq_str[i]);
	// }
	// // Advance by one bit at a time
	// for (i = 0; i < strlen(seq_str); i++) {
	// 	for (j = i; j < i + strlen(test_str); j++) {
	// 		sub_seq_int[j] = seq_int[j];
	// 		len = bma(sub_seq_int, strlen(test_str), test_desc);
			
	// 	}
	// }

	return 0;
}