#include "FuncionesCC.h"
#include <string.h> /*Libreria para usar strcpy*/
#include <time.h>   /*Libreria para el numero random y*/
#include <stdlib.h>
#include <stdio.h>

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
	local.estado=OCUPADO;
	printf("Ingrese el valor de alquiler del local ");
	scanf("%d",&local.valorLocal);
	printf("Ingrese la cantidad de empleados del local ");
	scanf("%d",&local.cantidadEmpleados);
	printf("Ingrese las ventas realizadas por el local ");
	scanf("%d",&local.valorVentas);
	printf("Ingrese el consumo de servicios de este mes ");
	scanf("%d",&local.consumoServicios);
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
		if(numPiso<=numPisos && numLocalxPiso<= numLocalesxPiso){
			if (centroComercial[numPiso-1][numLocalxPiso-1].estado!=OCUPADO && reserva==0){
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
		if(centroComercial[numPiso-1][numLocalxPiso-1].estado==OCUPADO){
			printf("\nNombre local : %s \n", centroComercial[numPiso-1][numLocalxPiso-1].nombreLocal);
			printf("Piso del local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].pisoLocal+1);
			printf("Numero local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].numLocalxPiso+1);
			printf("Valor del local : $%d \n", centroComercial[numPiso-1][numLocalxPiso-1].valorLocal);
			printf("ID local : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].idLocal);
			printf("Valor de ventas realizadas : $%d \n", centroComercial[numPiso-1][numLocalxPiso-1].valorVentas);
			printf("Numero empleados : %d \n", centroComercial[numPiso-1][numLocalxPiso-1].cantidadEmpleados);
			printf("Valor de consumo de servicios : $%d \n", centroComercial[numPiso-1][numLocalxPiso-1].consumoServicios);
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
			if (centroComercial[numPiso-1][j].estado==OCUPADO){
				printf("\nNombre local : %s \n", centroComercial[numPiso-1][j].nombreLocal);
				printf("Piso del local : %d \n", centroComercial[numPiso-1][j].pisoLocal+1);
				printf("Numero local : %d \n", centroComercial[numPiso-1][j].numLocalxPiso+1);
				printf("Valor del local : %d \n", centroComercial[numPiso-1][j].valorLocal);
				printf("ID local : %d \n", centroComercial[numPiso-1][j].idLocal);
				/*Para mostrar los locales del un piso en especifico anteriormente valido que el estado=1
				por lo que de una vez digo que esta ocupado*/
				printf("Estado del local : Ocupado \n");
				printf("Valor de ventas realizadas : $%d \n", centroComercial[numPiso-1][j].valorVentas);
				printf("Numero empleados : %d \n", centroComercial[numPiso-1][j].cantidadEmpleados);
				printf("Valor de consumo de servicios : $%d \n", centroComercial[numPiso-1][j].consumoServicios);

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
	int id,control=1, bandera=0,opcion,valorVentas,consumoServicios,cantidadEmpleados;
	char nuevoNombre [35];
	//Es necesario el ID del Local para realizarle modificaciones al
	printf("Para modificar es importante que ingreses el ID del local\n");
	printf("Digite el ID del local que desea modificar ");
	scanf("%d",&id);
	//Recorre los locales de cada piso del centro comercial hasta encontrar uno que tenga el ID
	for (int i=0; i<numPisos && control!=-1; i++){
		for (int j=0; j<numLocalesxPiso && control!=-1; j++){
			printf("%d",centroComercial[i][j].idLocal);
			if ( centroComercial[i][j].idLocal == id && bandera!=1){
				printf("Modificar:\n1. Nombre\n2. Valor de ventas\n3. Consumo servicios\n4. Cantidad empleados\n");
				scanf("%d",&opcion);
				control=0;
				switch (opcion)
				{
				case 1:
					printf("Escribe el nuevo nombre del local ");
					scanf("%35s",&nuevoNombre);
					strcpy(centroComercial[i][j].nombreLocal, nuevoNombre);
					printf("** NOMBRE DEL LOCAL ACTUALIZADO ** \n");
					control=-1;
					break;
				case 2:
					printf("Actualizar valor de ventas por ");
					scanf("%d",&valorVentas);
					centroComercial[i][j].valorVentas=valorVentas;
					printf("** CAMPO ACTUALIZADO ** \n");
					control=-1;
					break;
				case 3:
					printf("Actualizar valor del consumo de servicios por ");
					scanf("%d",&consumoServicios);
					centroComercial[i][j].consumoServicios=consumoServicios;
					printf("** CAMPO ACTUALIZADO ** \n");
					control=-1;
					break;
				case 4:
					printf("Actualizar cantidad de empleados por ");
					scanf("%d",&cantidadEmpleados);
					centroComercial[i][j].cantidadEmpleados=cantidadEmpleados;
					printf("** CAMPO ACTUALIZADO ** \n");
					control=-1;
					break;
				
				}
				printf("%d \n",control);
			}
		}
	}
	printf("%d  \n",control);
	if (control!=-1){
		printf("** ID no valido ** ");
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
		centroComercial[numPiso -1][numLocalxPiso -1].estado=DISPONIBLE;
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
		if(centroComercial[numPiso][numLocalesxPiso].estado!=OCUPADO){
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

/*Procedimiento que le permite a un cliente buscar informacion de un local por medio del
nombre de este*/ /*Implementar try except en char*/
void buscarLocalNombre(local_t ** centroComercial, int numPisos, int numLocalesxPiso){
	int localEncontrado=0;
	char nombreLocal[35];
	printf("Digite el nombre del local \n");
	scanf("%34s",nombreLocal);
	printf("%s \n",nombreLocal);
	for(int i=0; i< numPisos; i++){
		for(int j=0; j< numLocalesxPiso && localEncontrado==0; j++){
			if (centroComercial[i][j].estado==OCUPADO && (strcmp(centroComercial[i][j].nombreLocal,nombreLocal)==0)){
				printf("Informacion del local: %s \n",nombreLocal);
				printf("Ubicacion Piso:%d Local:%d \n",centroComercial[i][j].pisoLocal+1,centroComercial[i][j].numLocalxPiso+1);
				localEncontrado=1;
			}
		}
	}
	if(localEncontrado==0){
		printf("Visitante, no se ha encontrado locales con ese nombre");
	}
}


FILE* abrirArchivo(char path[], char modo[]) {
	if (path != NULL) {
		FILE* pFile = fopen(path, modo);
		return pFile;
	}
	return NULL;
}


/*Calcula la cantidad de locales ocupados en un piso*/
int calcularOcupados(local_t ** centroComercial,int numPiso, int numLocalesxPiso){
	int arr_size=0;
	for (int i=0; i<numLocalesxPiso; i++){
		if (centroComercial[numPiso][i].estado==OCUPADO){
			arr_size=arr_size+1;
		}
	}	
	return arr_size;
}

/*Calcula la cantidad de locales ocupados en todo el Centro Comercial*/
int calcularOcupadosCC(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int arr_size=0;
	for(int i=0; i< numPisos; i++){
		for(int j=0; j< numLocalesxPiso; j++){
			if (centroComercial[i][j].estado==OCUPADO){
				arr_size=arr_size+1;
			}
		}		
	}
	return arr_size;		
}

/*Procedimiento que se encarga de imprimir la lista ordenada despues de hacer
uso de los diferente ordenamientos iterativos y recursivos para ordenar por 
piso o por todo el Centro Comercial*/
void imprimirOrdenados(local_t arr[], int arr_size, int opcion){
	switch (opcion)
	{
	case 1:
		printf("\nLocales ordenados de menor a mayor por numero de ventas \n");
		for (int i=0; i<arr_size; i++){
			printf("Nombre del local: %s ",arr[i].nombreLocal);
			printf("Valor de ventas: %d \n",arr[i].valorVentas);
		}	
		break;
	case 2:
		printf("\nLocales ordenados de menor a mayor por cantidad de empleados \n");
		for (int i=0; i<arr_size; i++){
			printf("Nombre del local: %s ",arr[i].nombreLocal);
			printf("Numero de empleados: %d \n",arr[i].cantidadEmpleados);
		}	
		break;
	case 3:
		printf("\nLocales ordenados de menor a mayor por valor del local \n");
		for (int i=0; i<arr_size; i++){
			printf("Nombre del local: %s ",arr[i].nombreLocal);
			printf("Valor del local: $%d \n",arr[i].valorLocal);
		}	
		break;
	case 4:
		printf("\nLocales ordenados de mayor a menor por valor de consumo \n");
		for (int i=0; i<arr_size; i++){
			printf("Nombre del local: %s ",arr[i].nombreLocal);
			printf("Valor del local: $%d \n",arr[i].consumoServicios);
		}	
		break;
	}
}

/*Ordenamiento recursivo mergeSort que permite ordenar por piso (ingresado por el usuario), los locales 
de menor a mayor teniendo en cuenta el valor de ventas realizadas por estos locales*/
void merge(local_t arr[], int l, int m, int r) {
    //Encuentra el tamaño de los sub-listas para unirlos.
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    //Crea las listas con su tamaño
    local_t L[n1], R[n2]; 
  
    // Se copian los datos en las listas temporales L[] y R[] 
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j]; 
    }
    
    //Índices iniciales de la primera y segunda sublista.
    i = 0;
    j = 0;
    //Indice inicial de la sublista arr[]  
    k = l; 

    //Se lleva a cabo el ordenamiento 
    while (i < n1 && j < n2) { 
        //comparaciones++;
        if (L[i].valorVentas <= R[j].valorVentas){ 
            //intercambios++;
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            //intercambios++;
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Si quedan elementos por ordenar */
    //Copiar los elementos restantes de L[].
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    //Copiar los elementos restantes de R[].
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

/* l es para el indice izquierdo y r es el indice derecho del sub arreglo
de arr que se ordenara*/
void mergeSort(local_t arr[], int l, int r) {
    if (l < r) { 
        int m = l+(r-l)/2; 
        // Se orden las primeras y segundas mitades
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
} 
  
void ordenarVentas(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int arr_size=0, j=0,numPiso;
	printf("\nOrdenar por valor de alquiler los locales del piso --> ");
	scanf("%d",&numPiso);
	if (numPiso<=numPisos){
		arr_size=calcularOcupados(centroComercial,numPiso-1,numLocalesxPiso);
	}
	
	local_t arr[arr_size];
	
	for (int i=0; i<numLocalesxPiso; i++){
		if (centroComercial[numPiso-1][i].estado==OCUPADO){
			arr[j]=centroComercial[numPiso-1][i];
			j++;
		}
	}

	mergeSort(arr, 0, arr_size - 1); 
	imprimirOrdenados(arr, arr_size, 1);

	
	/*FILE* pFile = abrirArchivo("ReporteVentas.txt","w");
	printf("pFile  %p \n",pFile);
	if(pFile!=NULL){
		printf("YEP");
		for (int i=0; i<arr_size;i++){
			printf("ENTRE");
			fprintf(pFile, "%s\t%d\n", arr[i].nombreLocal, arr[i].valorLocal);
		}	
		fclose(pFile);
	}else{
		printf("No se pudo abrir correctamente el archivo\n");
	}*/
	
}

/*Ordenamiento recursivo quickSort que permite ordenar por piso (ingresado por el usuario), los locales de menor
a mayor numero de trabajadores*/
void qs(local_t arr[],int limite_izq,int limite_der){
    int izq,der;
	local_t pivote;
	local_t temporal; 
    izq=limite_izq;
    der = limite_der;
    pivote = arr[(izq+der)/2];

    do{
        while(arr[izq].cantidadEmpleados<pivote.cantidadEmpleados && izq<limite_der)izq++;
        while(pivote.cantidadEmpleados<arr[der].cantidadEmpleados && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= arr[izq];
            arr[izq]=arr[der];
            arr[der]=temporal;
            izq++;
            der--;
        }

    }while(izq<=der);
    if(limite_izq<der){qs(arr,limite_izq,der);}
    if(limite_der>izq){qs(arr,izq,limite_der);}

}

void quicksort(local_t arr[],int n){
    qs(arr,0,n-1);
}

void ordenarNumeroTrabajadores(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int arr_size=0, j=0,numPiso;
	printf("\nOrdenar por valor de alquiler los locales del piso --> ");
	scanf("%d",&numPiso);
	if (numPiso<=numPisos){
		arr_size=calcularOcupados(centroComercial,numPiso-1,numLocalesxPiso);
	}
	
	local_t arr[arr_size];
	
	/*Copiando los locales ocupados del piso ingresado por el usuario a una lista de struct*/
	for (int i=0; i<numLocalesxPiso; i++){
		if (centroComercial[numPiso-1][i].estado==OCUPADO){
			arr[j]=centroComercial[numPiso-1][i];
			j++;
		}
	}

	quicksort(arr,arr_size);
	imprimirOrdenados(arr, arr_size, 2);	

}

/*Algoritmo iterativo que permite ordenar de mayor a menor todos los locales del Centro 
Comercial teniendo en cuenta el valor de alquiler del local*/
void selectionSort(local_t arr[],int arr_size){
	int min;
	local_t aux;
    for (int i=0; i<=arr_size-1; i++){
        min=i;
        for (int j=i+1; j<=arr_size-1; j++){
            if (arr[j].valorLocal > arr[min].valorLocal){
                min=j;
            }
        }
        aux=arr[i];
        arr[i]=arr[min];
        arr[min]=aux;
    }
}

void ordenarValorAlquiler(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int arr_size,y=0;
	arr_size=calcularOcupadosCC(centroComercial,numPisos,numLocalesxPiso);
	local_t arr[arr_size];

	for(int i=0; i< numPisos; i++){
		for(int j=0; j< numLocalesxPiso; j++){
			if (centroComercial[i][j].estado==OCUPADO){
				arr[y]=centroComercial[i][j];
				y++;
			}	
		}		
	}
	selectionSort(arr, arr_size);
	imprimirOrdenados(arr, arr_size, 3);
}

/*Algoritmo iterativo que permite ordenar de mayor a menor todos los locales del Centro 
Comercial teniendo en cuenta su promedio de consumo de servicios*/
void insercion(local_t arr[], int arr_size) {
	int i, j;
	local_t temp;
	for (i = 1; i < arr_size; i++) {
		temp = arr[i];
		j = i;
		while (temp.consumoServicios > arr[j - 1].consumoServicios && j > 0) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

void ordenarLocalesConsumo(local_t ** centroComercial,int numPisos, int numLocalesxPiso){
	int arr_size,y=0;
	arr_size=calcularOcupadosCC(centroComercial,numPisos,numLocalesxPiso);
	local_t arr[arr_size];

	for(int i=0; i< numPisos; i++){
		for(int j=0; j< numLocalesxPiso; j++){
			if (centroComercial[i][j].estado==OCUPADO){
				arr[y]=centroComercial[i][j];
				y++;
			}
		}		
	}
	insercion(arr, arr_size);
	imprimirOrdenados(arr, arr_size, 4);
}