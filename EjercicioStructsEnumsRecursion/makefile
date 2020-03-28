all: programa
programa: Main Matrices
	gcc -o Matrices Main.o Matrices.o
Main: Main.c Matrices.h
	gcc -c Main.c
Matrices: Matrices.c Matrices.h
	gcc -c Matrices.c