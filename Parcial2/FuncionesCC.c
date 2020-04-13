#include "FuncionesCC.h"
#include <string.h> /*Libreria para usar strcpy*/
#include <time.h>   /*Libreria para el numero random y*/

/*Reserva el espacio para las filas y columnas de la matriz centroComercial */
local_t ** reservarMemoriaMatriz(int numPisos, int numLocalesxPiso){
    
    local_t **centroComercial = calloc(numPisos, sizeof(local_t*));
    if (centroComercial != NULL){
        for (int i=0; i< numPisos; i++){
            centroComercial[i] = calloc(numLocalesxPiso, sizeof(local_t*));
            if (centroComercial[i] == NULL) {
                printf("Error reservando memoria");
                break;            
            }
            //printf("Reservado espacio para la fila %d \n", (i+1));

        }
    } else {
        printf("Error reservando memoria");
    }
    return centroComercial;
}

/*Funcion que genera el ID del local */
int calcularId(){
	int aleatorio;
	srand(time(NULL));
	aleatorio = rand()%1000;
	return aleatorio;
}

/*Llena el struct con la informacion de los locales*/
struct Local llenarLocalTypeDef(int numPiso, int numLocalxPiso){
	int idLocal;
	local_t local;
	idLocal = calcularId();
	printf("Ingrese el nombre del local ");
	scanf("%35s",&local.nombreLocal);
	local.pisoLocal=numPiso;
	local.numLocalxPiso=numLocalxPiso;
	local.idLocal=idLocal;
	local.estado=1;  
	return local;
}

/*Procedimiento que agregara un nuevo local*/
void agregarLocal (local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	
	int numPiso, numLocalxPiso, reserva=0; 
	local_t local;
	/*Utiliza un while para preguntarle al usuario las veces que sean necesarias para que
	pueda crear un local en una ubicacion del centro comercial*/
	while (reserva==0){
		printf("Piso donde quiere agregar el local: ");
		scanf("%d",&numPiso);
		printf("Numero Local que quiere agregar: ");
		scanf("%d",&numLocalxPiso);
		/*Se valida que los datos ingresados esten entre el rango de pisos y locales que 
		hay en el centro comercial*/
		if(numPiso<=numPisos && numLocalxPiso <= numLocalesxPiso){
			if (centroComercial[numPiso-1][numLocalxPiso-1].estado!=1 && reserva==0){
				local = llenarLocalTypeDef(numPiso-1, numLocalxPiso-1);
				centroComercial[numPiso-1][numLocalxPiso-1]=local;
				printf("Recuerde el codigo ID del local es : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].idLocal);
				reserva=1;
			}else{
				printf("<< Local %d del piso %d se encuentra ocupado >>\n ",numPiso,numLocalxPiso);
				printf("        << Ingresa otra ubicacion >>\n ");
			}
		}else{
			printf("*** Numero del local no valido *** \n");
			printf("");
		}
	}	
	
}

/* Procedimiento que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso) {
	int numLocalxPiso, numPiso;
	printf("Piso del local a buscar: ");
	scanf("%d",&numPiso);
	printf("Numero del local a buscar: ");
	scanf("%d",&numLocalxPiso);
	//Se valida si los datos ingresados se encuentran en el rango de pisos y locales del centro comercial
	if(numPiso-1<=numLocalxPiso && numLocalxPiso-1 <= numLocalesxPiso)
	{	
		//Solo se muestra la informacion de los locales ocupados, se valida que se cumpla la condicion
		if(centroComercial[numPiso-1][numLocalxPiso-1].estado==1){
			printf("\nNombre local : %s \n", centroComercial[numPiso-1][numLocalxPiso-1].nombreLocal);
			printf("Piso del local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].pisoLocal+1);
			printf("Numero local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].numLocalxPiso+1);
			printf("ID local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].idLocal);
			
			/*Para mostrar el local de la ubicacion dada por el usuario, primero valide que el 
			estado de este local fuera diferente de cero, por lo tanto de una vez puedo decir
			que se encuentra Ocupado*/
			printf("Estado del local : Ocupado  \n");
		}else{

			/*Si el local esta libre no muestra informacion */
			printf("** Local sin informacion ** \n");
		}
			
	}else{
		printf("** Numero de piso o local no valido **");
	}
}

/*Procedimiento que muestra los locales por un piso dado */
void mostrarLocalPiso(local_t ** centroComercial, int numPisos,int numLocalesxPiso){
	int numPiso;
	printf("\nMostrar los locales del piso: ");
	scanf("%d",&numPiso);
	//Se valida que el piso ingresado este dentro del rango
	if (numPiso<=numPisos){
		for (int j=0; j<numLocalesxPiso; j++){
			/*Dentro del recorrido de cada uno de los locales se valida que estos esten ocupados 
			para imprimir su informacion*/
			if (centroComercial[numPiso-1][j].estado==1){
				printf("\nNombre local : %s \n", centroComercial[numPiso-1][j].nombreLocal);
				printf("Piso del local : %d \n", centroComercial[numPiso-1][j].pisoLocal+1);
				printf("Numero local : %d \n", centroComercial[numPiso-1][j].numLocalxPiso+1);
				printf("ID local : %d \n", centroComercial[numPiso-1][j].idLocal);
				/*Para mostrar los locales del un piso en especifico anteriormente valido que el estado=1
				por lo que de una vez digo que esta ocupado*/
				printf("Estado del local : Ocupado \n");	
			}
		}
		printf("\n");
	}else
	{
		printf("Piso no valido \n");
	}
	
}

/*Procedimiento que modifica el nombre del local*/
void modificarLocal (local_t ** centroComercial,int numPisos,int numLocalesxPiso){
	int id;
	char nuevoNombre [35];
	//Es necesario el ID del Local para realizarle modificaciones al
	printf("Para modificar el nombre del local es importante que ingreses el ID del local\n");
	printf("Digite el ID del local que desea modificar ");
	scanf("%d",&id);
	//Recorre los locales de cada piso del centro comercial hasta encontrar uno que tenga el ID
	for (int i=0; i<numPisos; i++){
		for (int j=0; j<numLocalesxPiso; j++){
			if ( centroComercial[i][j].idLocal == id ){
				printf("Escribe el nuevo nombre del local ");
				scanf("%35s",&nuevoNombre);
				strcpy(centroComercial[i][j].nombreLocal, nuevoNombre);
				printf("** NOMBRE DEL LOCAL ACTUALIZADO ** \n");
				
			}else{
				printf("** ID no valido ** ");
			}
		}
	}
}

/*Procedimiento que elimina un local en especifico*/
void eliminarLocal(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int numLocalxPiso, numPiso;
	printf("Piso del local a eliminar: ");
	scanf("%d",&numPiso);
	printf("Numero del local a eliminar: ");
	scanf("%d",&numLocalxPiso);	
	/*Verifica que los datos ingresados esten el rango adecuado*/
	if(numPiso-1<=numLocalxPiso && numLocalxPiso-1 <= numLocalesxPiso){
		/*Como se va a eliminar el local, este pasa de estado ocupado (estado=1) a estado libre (estado=0)*/
		centroComercial[numPiso -1][numLocalxPiso -1].estado=0;
		printf("** Local eliminado **\n");
	}else{
		printf("El piso o el local no son validos");
	}
}

/*Funcion recursiva que permite calcular cuantos locales se encuentran disponibles en 
un piso en especifico*/
int cantidadLocalesDisponible(local_t ** centroComercial, int numPiso, int numLocalesxPiso){
	//Condicion de control
	if (numLocalesxPiso==-1){
		return 0;
	}else{
		if(centroComercial[numPiso][numLocalesxPiso].estado!=1){
			return 1 + cantidadLocalesDisponible(centroComercial,numPiso, numLocalesxPiso-1);
		}else{
			return 0 + cantidadLocalesDisponible(centroComercial,numPiso, numLocalesxPiso-1);
		}
		
	}
}
/*Procedimiento que le permite al administrador del centro comercial visualizar las calificaciones
dadas por los visitantes. Usa enums y ademas una lista de 4 posiciones en donde cada espacio
representa cada nivel de satisfaccion*/
void visualizarCalificaciones(int calificacionUsuarios []){
	calificacion_e tipoCalificacion = 0;
	printf("\nConocer la cantidad de personas que votaron por: \n");
	printf("\n1. Excelente");
	printf("\n2. Bueno");
	printf("\n3. Regular");
	printf("\n4. Malo");
	printf("\n5. Salir \n");
	scanf("%d", &tipoCalificacion);
	switch (tipoCalificacion-1)
	{
		case EXCELENTE:
			printf ("El centro comercial le parece excelente a %d personas \n",calificacionUsuarios[tipoCalificacion-1]);
			break;
		case BUENO:
			printf ("El centro comercial le parece bueno a %d personas \n",calificacionUsuarios[tipoCalificacion-1]);
			break;
		case REGULAR:
			printf ("El centro comercial le parece regular a %d personas \n",calificacionUsuarios[tipoCalificacion-1]);
			break;
		case MALO:
			printf ("El centro comercial le parece malo a %d personas \n",calificacionUsuarios[tipoCalificacion-1]);
			break;
	}
}

/*Procedimiento que le permite a los usuarios realizar una calificacion sobre su experiencia
en el centro comercial*/
void calificarCentroComercial(int calificacionUsuarios []){
	int calificacion;
	printf("\nRealice su calificacion \n");
	printf("\n1. Excelente");
	printf("\n2. Bueno");
	printf("\n3. Regular");
	printf("\n4. Malo");
	printf("\n5. Salir \n");
	scanf("%d", &calificacion);
	calificacionUsuarios[calificacion-1]=calificacionUsuarios[calificacion-1]+1;
}


