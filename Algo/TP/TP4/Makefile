CC=gcc
OPTS=-Wall -Werror
PROG=prg
LIBS=meo_ab_tp2.o

all: ${PROG} ${LIBS}

${PROG}: tp_franceadministrative.c ${LIBS}
	${CC} tp_franceadministrative.c ${LIBS} ${OPTS} -o ${PROG}

meo_ab_tp2.o: meo_ab_tp2.c meo_ab_tp2.h
	${CC} -c meo_ab_tp2.c ${OPTS}

clean:
	rm -f ${LIBS} ${PROG}

