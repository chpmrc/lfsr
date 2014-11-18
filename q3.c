/**
 * Let's break this LFSR!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "lfsr.h"

#define MAX_SIZE 1024 * 1023

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

	char test_str[10] = "AGREE";
	int test_bits[40] = {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
	char seq_str[MAX_SIZE] = BIN_SEQ;
	int seq_int[MAX_SIZE];
	int sub_seq_int[MAX_SIZE];
	int test_key_stream[MAX_SIZE];
	int test_desc[MAX_SIZE];
	int test_init_state[MAX_SIZE];
	int lfsr_output[MAX_SIZE];
	int i, j, test_num_bits, seq_len, lfsr_len;

	memset(seq_int, 0, MAX_SIZE);
	memset(test_desc, 0, MAX_SIZE);
	test_num_bits = (sizeof(test_str) - 1) * 8; // Number of bits, exclude trailing 0
	seq_len = strlen(seq_str);

	// Convert seq from string to int[]
	for (i = 0; i < seq_len; i++) {
		seq_int[i] = c2b(seq_str[i]);
	}
	// Advance by one bit at a time
	for (i = 0; i < seq_len; i++) {
		// Get a subsequence of bits to test
		for (j = i; j < i + test_num_bits; j++) {
			sub_seq_int[j - i] = seq_int[j];
		}
		// Xor them with the plaintext to find the candidate key stream
		for (j = 0; j < test_num_bits; ++j)
		{
			test_key_stream[j] = test_bits[j] ^ sub_seq_int[j]; // kc_i = test_i XOR c_i (bits)
		}
		// Run BMA on the given key stream and find the LFSR that generates it (discard the too long ones)
		lfsr_len = bma(test_key_stream, test_desc, test_num_bits);
		if (lfsr_len <= 20) {
			LFSR test_lfsr;
			// Generate a non-null initial state
			memset(test_init_state, 0, lfsr_len);
			test_init_state[lfsr_len - 1] = 1;
			memcpy(test_lfsr.descriptor, test_desc, lfsr_len * sizeof(int));
			memcpy(test_lfsr.initial_state, test_init_state, lfsr_len * sizeof(int));
			test_lfsr.len = lfsr_len;
			// Run the LFSR
			get_lfsr_output(&test_lfsr, lfsr_output, pow(2, lfsr_len - 1)); // Get the whole damn period and let's brute force this thing!
			print_array(lfsr_output, pow(2, lfsr_len - 1));
		}
	}

	return 0;
}