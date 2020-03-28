
#include <stdio.h>
#include <stdlib.h>   //malloc

/*Se define el struct */
struct Persona {
	char nombre[25];
	int diaNacimiento;
	int mesNacimiento;
	int anioNacimiento;
};

/*Facilita la definición del struct */
typedef struct Persona persona_t;

/*Se define el enum*/
typedef enum mesesAnio{
	ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
}meses_anio_e;

/* Procedimiento que llena la matriz de structs*/
void llenarMatriz(persona_t matriz [][5] , int fil, int col, int capacidad[12]); 

/* Procedimiento que muestra las personas almacenadas en un mes en especifico*/
void mostrarMatriz(persona_t matriz [][5], int capacidad[12], int mes);

/* Función recursiva que calcula el promedio de las edades de las personas ingresadas 
en un mes en especifico*/
int sumarEdades(persona_t matriz [][5], int capacidad[12], int mes, int cap);

/*Procedimiento que muestra las fechas especiales de cada uno de los meses*/
void mostrarFechasEspeciales();