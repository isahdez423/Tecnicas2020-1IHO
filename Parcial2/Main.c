#include "FuncionesCC.h"
#include <stdio.h>

//Funcion con el menu para el administrador con diferentes funcionalidades que retorna la opcion ingresada.
int menu2()
{
    int option = 0;
    printf(" Opciones  \n\n");
    printf("1. Ingresar un nuevo local \n");
	printf("2. Buscar local en especifico \n");
	printf("3. Buscar locales por piso \n");
    printf("4. Modificar nombre de un local \n");
    printf("5. Eliminar un local\n");
	printf("6. Cantidad de locales disponibles en un piso \n");
    printf("7. Visualizar calificaciones del Centro Comercial\n");
    printf("8. Salir\n");
    scanf("%d", &option);
    return option;
}

//El programa tiene un menu para el administrador y visitantes del centro comercial que retorna la opcion ingresada.
int menu(){
    int option;
    printf(" Opciones  \n\n");
    printf("1. Administrador \n");
	printf("2. Visitante \n");
    printf("3. Salir\n");
    scanf("%d", &option);
    return option;
}

int main(){
    //Se definen las variables a utilizar
    int numPisos, numLocalesxPiso, numPiso, disponibles;
    int option, option2;
    /*Se define la lista que almacena la cantidad de personas que califican la 
    visita al centro comercial*/
    int calificacionUsuarios[4]={0,0,0,0};
    setbuf(stdout,NULL);
    //Apuntador doble a la dirección de memoria que se reserva para ubicar la matriz
    local_t ** centroComercial=NULL; //Matriz de structs que almcanena los locales

    //Informacion de los pisos y locales que tiene el centro comercial
    printf("Digite el numero de pisos del Centro Comercial ");
    scanf("%d",&numPisos);
    printf("Digite el numero de locales por piso ");
    scanf("%d",&numLocalesxPiso);

    //Reserva el espacio para las filas y las columnas de la matriz
    centroComercial = reservarMemoriaMatriz(numPisos,numLocalesxPiso);
    //Se libera la memoria
    free(centroComercial);
    
    do
    {
        option = menu();
        if (option==1){
            option2=menu2();
            switch (option2)
            {
                case 1:
                    if (centroComercial != NULL){
                    agregarLocal(centroComercial, numPisos,numLocalesxPiso);
                    }else{
                        printf("Error de asignacion de memoria");
                    }              
                    break;
                case 2:
                    mostrarLocal(centroComercial, numPisos, numLocalesxPiso);
                    break;
                case 3:
                    mostrarLocalPiso(centroComercial,numPisos, numLocalesxPiso);
                    break;
                case 4:
                    modificarLocal(centroComercial,numPisos,numLocalesxPiso);
                    break;
                case 5:
                    eliminarLocal(centroComercial,numPisos,numLocalesxPiso);
                    break;
                case 6:
                    printf("Locales disponibles en el piso --> ");
	                scanf("%d",&numPiso);
                    disponibles=cantidadLocalesDisponible(centroComercial, numPiso-1, numLocalesxPiso-1);
                    printf("\n %d locales disponibles en el piso %d \n",disponibles,numPiso);
                    break;
                case 7:
	                visualizarCalificaciones(calificacionUsuarios);
                    break;
            }
        }else if (option==2){
           calificarCentroComercial(calificacionUsuarios);
        }
    } while (option!=3);
	return 0;
}

