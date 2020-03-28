#include "Matrices.h"

void mostrarMenu() {

	int opcion = 0;
	int resultado, promedio;
	int filas=12, columnas=5;
	/*Matriz que almacena Structs de 12x5*/
	persona_t matriz[filas][columnas];
	/*Arreglo de tamaño 12 que se usa para almacenar la cantidad de personas ingresadas
	en cada mes*/
	int capacidad[12]={};
	int mes;

	do {
		
		printf(" Opciones  \n\n");
		printf("1. Agregar persona\n");
		printf("2. Mostrar cumpleaneros del mes\n");
		printf("3. Calcular promedio de las edades de las personas de un mes\n");
		printf("4. Fechas especiales por mes\n");
		printf("0. Salir\n\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
		printf("\n");
		switch (opcion) {
			case 1:
				llenarMatriz(matriz, filas, columnas, capacidad );
				printf("\n");
				break;

			case 2:
				printf("Digite el mes (en numero) para mostrar los datos de las personas: ");
				scanf("%d",&mes);
				mes=mes-1;
				printf("\n");
				mostrarMatriz(matriz, capacidad, mes );
				break;

			case 3:
				printf("\nDigite el mes (en numero) para calcular el promedio de las edades: ");
				scanf("%d",&mes);
				resultado = sumarEdades(matriz, capacidad, mes-1, capacidad[mes-1]-1);

				if (resultado>0){
					promedio = resultado/capacidad[mes-1];
					printf("\n El promedio de las edades del mes %d es %d \n ", mes, promedio);
					printf("\n");
				}else{
					printf("\n ** No hay personas ingresadas en este mes ** \n\n");
				}
				break;

			case 4:
				mostrarFechasEspeciales();
				break;
		}
	//Cuando el usuario ingrese 0 se terminará el while y se terminará el menu
	} while(opcion!=0);
}

int main(){
	mostrarMenu ();
	return 0;
}