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

#define BIN_SEQ {0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0}
#define SEQ_LEN 744
#define TEST_LEN 40

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

	// char test_str[10] = "AGREE";
	int test_bits[TEST_LEN] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0};
	int seq_int[SEQ_LEN*TEST_LEN] = BIN_SEQ;
	int test_key_stream[TEST_LEN];
	int test_desc[MAX_SIZE];
	int test_init_state[MAX_SIZE];
	int lfsr_output[MAX_SIZE];
	int i, j, k, test_len, seq_len, lfsr_len, how_many;
	int plaintex_candidate[MAX_SIZE];
	// char plaintext_str[MAX_SIZE];

	test_len = TEST_LEN;
	seq_len = SEQ_LEN;

	// printf("Sequence: ");
	// print_array(seq_int, seq_len);
	// printf("\n");

	// Advance one byte at a time
	for (i = 0; i < seq_len; i += 1) {
		// Xor them with the plaintext to find the candidate key stream
		for (j = 0; j < test_len; ++j)
		{
			test_key_stream[j] = test_bits[j] ^ seq_int[i + j]; // kc_i = test_i XOR c_i (bits)
		}
		// print_array(test_key_stream, test_len);
		// Run BMA on the given key stream and find the LFSR that generates it (discard the too long ones)
		lfsr_len = bma(test_key_stream, test_desc, test_len);
		// if (lfsr_len <= 20	) {
		// 	printf("Length: %d\n", lfsr_len);
		// 	print_array(test_desc, lfsr_len);
		// 	print_array(test_key_stream, test_len);
		// }
		// Use the last lfsr_len bits as initial state for the LFSR and see if we can
		// generate the remainder of the ciphertext
		// print_array(test_key_stream, test_len);
		if (lfsr_len == 8) {
			// printf("Descriptor: ");
			// print_array(test_desc, lfsr_len);
			// printf("\n");
			memset(test_init_state, 0, lfsr_len);
			memset(lfsr_output, 0, MAX_SIZE);
			printf("Trying key stream: ");
			print_array(test_key_stream, test_len);
			for (k = 0; k < lfsr_len; k++) {
				test_init_state[k] = test_key_stream[k + (test_len - lfsr_len)];
			}
			printf("Taking the last %d bits: ", lfsr_len);
			print_array(test_init_state, lfsr_len);
			// Create the LFSR
			LFSR test_lfsr;
			memcpy(test_lfsr.descriptor, test_desc, lfsr_len * sizeof(int));
			memcpy(test_lfsr.initial_state, test_init_state, lfsr_len * sizeof(int));
			test_lfsr.len = lfsr_len;
			// Run the LFSR
			how_many = 40; // seq_len - i - test_len;
			if (how_many > 0 && lfsr_len == 8) {
				printf("LFSR                 : ");
				print_array(test_lfsr.descriptor, lfsr_len);
				printf("Testing initial state: ");
				print_array(test_lfsr.initial_state, lfsr_len);
				get_lfsr_output(&test_lfsr, lfsr_output, how_many);
				// XOR with the ciphertext and print the result
				// Start from the current position in the sequence
				for (k = 0; k < how_many; k++) {
					// printf("Xoring %d and %d: %d\n", seq_int[k], lfsr_output[k - i], seq_int[k] ^ lfsr_output[k - i - test_len]);
					plaintex_candidate[k] = seq_int[i + how_many] ^ lfsr_output[k];
				}
				printf("i: %d, seq_len: %d, how_many: %d\n", i, seq_len, how_many);
				printf("LFSR output: "); print_array(lfsr_output, how_many);
				printf("Plaintext  : "); print_array(plaintex_candidate, how_many);
				// printf("%s\n", plaintext_str);
				printf("Test bits  : "); print_array(test_bits, test_len);
			}
		}
	}

	return 0;
}