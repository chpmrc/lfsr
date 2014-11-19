CS 507 - HW3
--------

Programs:
- q1.c : solves the first exercises. It generates an output sequence given the LFSR descriptor (coefficients of the connection polynomial) and the initial state. MAKE SURE YOU INVERT THE POLYNOMIAL FOR THE 3RD QUESTION.
- q2.c : solves the second exercise. Given an output sequence it returns the shortest LFSR that generates it (with its linear complexity).
- q3.c : finds the shortest LFSR that generates the key stream candidate for the first block of N bits in the ciphertext (where N is the length of the known plaintext, AGREE in this case). It also returns the initial state to use (last L bits of the key stream candidate, where L is the length of the LFSR) and the first 40 bits of the key stream. Use the binary of q1 to find more bits of the keystream. In the end I used a simple Python script (test.py) to decrypt the ciphertext (I was fed up with segmentation faults...).

Additionals:
- lfsr.(h|c) : implementation of the common algorithms used in the homework (LFSR, BMA, etc.).

Compile with make.

Usage: for q1 and q1 just run them without arguments, usage is printed. q3 has takes no arguments.

------
Marco Chiappetta