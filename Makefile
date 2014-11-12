CCFLAGS=-Wunused -g
LDFLAGS=-lm

all: lfsr.o
	-gcc ${CCFLAGS} -o q1.bin q1.c lfsr.o ${LDFLAGS}
	-gcc ${CCFLAGS} -o q2.bin q2.c lfsr.o ${LDFLAGS}

lfsr.o:
	gcc ${CCFLAGS} -c lfsr.c

clean:
	-rm *.o *.bin