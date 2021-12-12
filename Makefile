# Makefile para os programas dos apontamentos
CC		= g++
FLAGS	= -lm

.PHONY: clean all

all: projMain1

clean: 
	-rm *.o projMain1

projMain1: projMain1.cpp  listaGenerica.o monomio.o polinomio.o
	${CC} -o $@ $@.cpp  listaGenerica.o monomio.o polinomio.o
