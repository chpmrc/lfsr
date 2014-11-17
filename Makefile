CC=clang
CCFLAGS=-Wunused -g
LDFLAGS=-lm

all: clean lfsr.o
	-${CC} ${CCFLAGS} -o q1.bin q1.c lfsr.o ${LDFLAGS}
	-${CC} ${CCFLAGS} -o q2.bin q2.c lfsr.o ${LDFLAGS}
	-${CC} ${CCFLAGS} -o q3.bin q3.c lfsr.o ${LDFLAGS}

lfsr.o:
	${CC} ${CCFLAGS} -c lfsr.c

clean:
	-rm *.o *.bin