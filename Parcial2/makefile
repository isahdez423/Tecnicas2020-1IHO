all: programa
programa: Main FuncionesCC
	gcc -o FuncionesCC Main.o FuncionesCC.o
Main: Main.c FuncionesCC.h
	gcc -c Main.c
FuncionesCC: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c