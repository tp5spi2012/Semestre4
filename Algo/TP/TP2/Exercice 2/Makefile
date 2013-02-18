CC=gcc
OPTS=-Wall -Werror
PROG=animaux
LIBS=meo_ab_tp2.o

all: ${PROG} ${LIBS}

${PROG}: animaux.c ${LIBS}
	${CC} animaux.c ${LIBS} ${OPTS} -o ${PROG}

meo_ab_tp2.o: meo_ab_tp2.c meo_ab_tp2.h
	${CC} -c meo_ab_tp2.c ${OPTS}

clean:
	rm -f ${LIBS} ${PROG}

