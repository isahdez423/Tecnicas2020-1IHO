#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Struct del local
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int estado; // Completelo con lo que quiera
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

#endif /* FUNCIONESCC_H_ */
