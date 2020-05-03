#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h> 
#define SIZE 500000 //Modificar cada vez que se intente leer una lista de tamaño n

FILE* abrirArchivo(char path[], char modo[]) {
	if (path != NULL) {
		FILE* pFile = fopen(path, modo);
		return pFile;
	}
	return NULL;
}

void printArray(int lista[]) { 
    int i; 
    for (i=0; i < SIZE; i++) {
		//printf ("El valor en la posicion %d es %d \n",i,lista[i]);
        printf("%d ", lista[i]); 
    }
    printf("\n"); 
} 

void burbuja(int lista[],int inicio){
    int i, j,min,aux,comparaciones=0,intercambios=0;
    int temp=0;             
    for (i=1;i<SIZE;i++){
        for (j=0; j < SIZE-i ;j++){
            comparaciones++;
            if (lista[j] > lista[j+1]){
                temp=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=temp;
                intercambios++;
            }
        }
    }
    clock_t final;
	final=clock();

    FILE * pFileConsolidado = abrirArchivo("ConsolidadoBurbuja.txt", "a");
    if(pFileConsolidado!=NULL){
        fprintf(pFileConsolidado,"Fin: %d\n",final);
		fprintf(pFileConsolidado,"Tiempo de ejecucion: %f\n",(float)(final-inicio));
        fprintf(pFileConsolidado, "Comparaciones %d\n",comparaciones );
        fprintf(pFileConsolidado, "Intercambios %d\n",intercambios );
        fclose(pFileConsolidado);
    }
    printArray(lista);
        
}

int main(){
	int lista[SIZE];
    //Cambiar path para leer cualquier lista de n elementos
	FILE* pFile = fopen("numerosQuinientosMil.dat","rb");
	if(pFile != NULL) {
		fread(lista,sizeof(int),SIZE,pFile);
		fclose(pFile);		
	} else {
		printf("No se pudo abrir correctamente el archivo\n");
	}

    time_t tiempoahora;
	time(&tiempoahora);
	
    clock_t inicio;
	inicio = clock();
		
	FILE * pFileConsolidado = abrirArchivo("ConsolidadoBurbuja.txt", "a");
	if(pFileConsolidado!=NULL){
        fprintf(pFileConsolidado,"-------------------------------\n");
		fprintf(pFileConsolidado,"BURBUJA 500000 NÚMEROS MAYOR A MENOR\n");
        fprintf(pFileConsolidado,"Fecha: %s",ctime(&tiempoahora));
		fprintf(pFileConsolidado,"Inicio: %d \n",inicio);
		fclose(pFileConsolidado);
	} else {
		printf("No se pudo abrir correctamente el archivo\n");
	}
	burbuja(lista,inicio);

}