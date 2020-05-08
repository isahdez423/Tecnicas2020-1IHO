#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h> 
#define ARR_SIZE 100000 //Modificar cada vez que se intente leer una lista de tamaño n


FILE* abrirArchivo(char path[], char modo[]) {
	if (path != NULL) {
		FILE* pFile = fopen(path, modo);
		return pFile;
	}
	return NULL;
}

void printArray(int arr[]) { 
    int i; 
    for (i=0; i < ARR_SIZE; i++) {
		//printf ("El valor en la posicion %d es %d \n",i,lista[i]);
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
} 


void merge(int arr[], int l, int m, int r) 
{
    //Encuentra el tamaño de los sub-listas para unirlos.
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    //Crea las listas con su tamaño
    int L[n1], R[n2]; 
  
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
    while (i < n1 && j < n2) 
    { 
        //comparaciones++;
        if (L[i] <= R[j]) 
        { 
            //intercambios++;
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            //intercambios++;
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Si quedan elementos por ordenar */
   //Copiar los elementos restantes de L[].
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
     //Copiar los elementos restantes de R[].
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


/* l es para el indice izquierdo y r es el indice derecho del sub arreglo
de arr que se ordenara*/
void mergeSort(int arr[], int l, int r) 
{   
   
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        // Se orden las primeras y segundas mitades
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
} 
  

int main(){
   
    int arr[ARR_SIZE];
    //Cambiar path para leer cualquier lista de n elementos
	FILE* pFile = fopen("numerosAleatoriosCienMil.dat","rb");
	if(pFile != NULL) {
		fread(arr,sizeof(int),ARR_SIZE,pFile);
		fclose(pFile);		
	} else {
		printf("No se pudo abrir correctamente el archivo\n");
	}

    
    time_t tiempoahora;
	time(&tiempoahora);
	
    clock_t inicio;
	inicio = clock(); 
    clock_t final;

	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	FILE * pFileConsolidado = abrirArchivo("ConsolidadoMergeSort.txt", "a");
	if(pFileConsolidado!=NULL){
        fprintf(pFileConsolidado,"----------------------------------------\n");
		fprintf(pFileConsolidado,"MERGE SORT 100000 NÚMEROS DESORDENADOS\n");
        fprintf(pFileConsolidado,"Fecha: %s",ctime(&tiempoahora));
		fprintf(pFileConsolidado,"Inicio: %d \n",inicio);
		fclose(pFileConsolidado);
	} else {
		printf("No se pudo abrir correctamente el archivo\n");
	}
    
    mergeSort(arr, 0, ARR_SIZE - 1); 
    
	final=clock();

    pFileConsolidado = abrirArchivo("ConsolidadoMergeSort.txt", "a");
    if(pFileConsolidado!=NULL){
		fprintf(pFileConsolidado,"Fin: %d\n",final);
		fprintf(pFileConsolidado,"Tiempo de ejecucion: %f\n",(float)(final-inicio));
        //fprintf(pFileConsolidado, "Comparaciones %d\n",comparaciones );
        //fprintf(pFileConsolidado, "Intercambios %d\n",intercambios );
        fclose(pFileConsolidado);
    }

    printf("\nLa lista organizada es \n"); 
    printArray(arr);    
}