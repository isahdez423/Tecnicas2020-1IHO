#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

typedef enum Estado{
	OCUPADO=1, DISPONIBLE=0
} estado_t;

//Struct del local
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	//int estado; // Completelo con lo que quiera
	estado_t estado;
	//int numTrabajadores;
	int valorLocal;
	int valorVentas;
	int cantidadEmpleados;
	int consumoServicios;
} local_t;

//Se define el enum
typedef enum calificaciones{
	EXCELENTE, BUENO, REGULAR, MALO
}calificacion_e;

//Reserva el espacio para las filas y las columnas de la matriz
local_t ** reservarMemoriaMatriz(int numPisos, int numLocalesxPiso); 

/*Permite agregar un local*/
void agregarLocal (local_t ** centroComercial,int numPisos, int numLocalesxPiso );

/*Muestra un local en especifico */
void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso);

/*Muestra los locales de un piso en especifico*/
void mostrarLocalPiso(local_t ** centroComercial, int numPisos, int numLocalesxPiso);

/*Modifica el nombre de un local, por seguridad debe conocer el ID de este*/
void modificarLocal(local_t ** centroComercial,int numPisos,int numLocalesxPiso);

/*Pone un local nuevamente en estado libre*/
void eliminarLocal(local_t ** centroComercial,int numPisos, int numLocalesxPiso);

/*Funcion recursiva que retorna la cantidad de locales disponibles en un piso*/
int cantidadLocalesDisponible(local_t ** centroComercial, int numPiso, int numLocalesxPiso);

/*Le permite al administrador visualizar las calificaciones de los visitantes
del centro comercal*/
void visualizarCalificaciones(int calificacionUsuarios []);

/*Le permite al usuario calificar su experiencia en el centro comercial*/
void calificarCentroComercial(int  calificacionUsuarios[]);

/*Le permite al cliente encontrar informacion de un local por su nombre*/
void buscarLocalNombre(local_t ** centroComercial, int numPisos, int numLocalesxPiso);

/*MERGE SORT: Ordenamiento recursivo mergeSort que permite ordenar por piso (ingresado por el usuario),
los locales de menor a mayor teniendo en cuenta el valor de ventas realizadas por estos locales*/
void ordenarVentas(local_t ** centroComercial, int numPisos, int numLocalesxPiso);
/*QUICKSORT:Ordenamiento recursivo quickSort que permite ordenar por piso (ingresado por el usuario), 
los locales de menor a mayor numero de trabajadores*/
void ordenarNumeroTrabajadores(local_t ** centroComercial,int numPisos, int numLocalesxPiso);
/*SELECCION: Algoritmo iterativo que permite ordenar de mayor a menor todos los locales del Centro 
Comercial teniendo en cuenta el valor de alquiler del local*/
void ordenarValorAlquiler(local_t ** centroComercial,int numPisos, int numLocalesxPiso);
/*INSERCION: Algoritmo iterativo que permite ordenar de mayor a menor todos los locales del Centro 
Comercial teniendo en cuenta su promedio de consumo de servicios*/
void ordenarLocalesConsumo(local_t ** centroComercial,int numPisos, int numLocalesxPiso);

#endif /* FUNCIONESCC_H_ */
