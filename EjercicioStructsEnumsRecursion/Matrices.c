#include "Matrices.h"

/*Llenan los datos de las personas*/
struct Persona llenarPersonaTypeDef(){
	persona_t persona;
	printf("Ingrese el nombre \n");
	fflush(stdin);
	scanf("%s",&persona.nombre);//fgets(persona.nombre,25,stdin); 
	printf("Ingrese el dia de nacimiento\n");
	scanf("%d", &persona.diaNacimiento);
	printf("Ingrese el mes de nacimiento en numero\n");
	scanf("%d", &persona.mesNacimiento);
	printf("Ingrese el anio de nacimiento\n");
	scanf("%d", &persona.anioNacimiento);
	//persona.ocupado=0;
	return persona;
}

/*Procedimiento que muestra las personas que cumplen aaños en el mes 
ingresado por el usuario*/
void mostrarMatriz(persona_t matriz [][5],int capacidad[12], int mes) {
	int i;
	if (capacidad[mes]>0){
		printf("   CUMPLEANIEROS MES %d \n\n",mes);
		for (i = 0; i < capacidad[mes]; i++) {
		printf("--> %s   %d / %d / %d \n",matriz[mes][i].nombre,matriz[mes][i].diaNacimiento,
		matriz[mes][i].mesNacimiento,matriz[mes][i].anioNacimiento);
		}	
	}else{
		printf("** No hay personas ingresadas en este mes ** \n");
	}
	printf("\n");
}

/*Procedimiento que retorna la ubicación de la columna en la que puede ubicar a 
la persona segun el mes indicado o -1 si no hay espacio disponible para almacenar a una persona mas*/
int ubicarPersona(int capacidad[12], int mes){
	int i;
	if (capacidad[mes]<5){
		capacidad[mes]++;
		//printf("DISPONIBLE UBICAR EN %d %d \n",mes,capacidad[mes]-1);
		return capacidad[mes]-1;
	}else{
		return -1; //Indica que no hay espacio disponible
	}
}

/*Procedimiento que permite ubicar a la persona en el mes de nacimiento siempre y
cuando el mes ingresado sea valido y tenga capacidad de almacenar una persona*/
void llenarMatriz(persona_t matriz [][5],  int fil, int col, int capacidad[5]) {
	int i, mes, ubicar;
	persona_t persona;
	persona = llenarPersonaTypeDef();
	mes = persona.mesNacimiento;

	if (mes>0 && mes<13){
		ubicar = ubicarPersona(capacidad,mes-1);
		if (ubicar==-1){
			printf("\n ** Almacenamiento lleno ** \n");
		}else{
			matriz[mes-1][ubicar]=persona;
			//printf("<< %d \n",matriz[mes-1][ubicar].diaNacimiento);
		}
	}else{
		printf("\n ** Numero de mes no valido ** \n");
	}
	
}

/*Función recursiva que permite hallar la suma de las edades de las 
personas almacenadas en un mes en especifico*/
int sumarEdades(persona_t matriz [][5],int capacidad[12], int mes, int cap){
	
	//Variable que permite calcular la edad de la persona, restandole el año actual (2020)
	int edades=0;
	//Acumulador que almacena todas las edad de las personas del mes dado
	int sumaEdades=0;
	
	persona_t persona;
	persona = matriz[mes][cap];
	edades = (2020-persona.anioNacimiento);

	if (cap==-1){
		return 0;
	}else{
		sumaEdades=sumaEdades+edades;
		return sumaEdades + sumarEdades(matriz,capacidad, mes,cap-1);
	}
}

/*Procedimiento con enums, ciclo y condicional switch, en donde se muestra las fechas especiales
dependiendo del mes ingresado por el usuario. Para finalizar la busqueda de fechas especiales,
se debe marcar el numero -1*/
void mostrarFechasEspeciales(){
	meses_anio_e mesesAnio = 0;
	system("cls");
	do{
		printf("\nDigite un mes (en numero) para conocer las fechas especiales (-1 SALIR) \n");
		scanf("%d", &mesesAnio);
		switch (mesesAnio-1){
		case ENERO: printf("\n---- ENERO -----\n7. Dia de los Reyes Magos\n4. Dia Mundial del Braille\n");
						break;
		case FEBRERO: printf("\n---- FEBRERO -----\n3. Dia Internacional de Abogado\n");
					  printf("14. Dia de San Valentin\n15. Dia Internacional Contra el Cancer Infantil\n");
						break;
		case MARZO: printf("\n---- MARZO -----\n8. Dia Internacional de la Mujer\n");
					printf("19. Dia del Hombre\n23. Dia del Optometra\n");
						break;
		case ABRIL: printf("\n---- ABRIL -----\n7. Dia mundial de la Salud\n");
					printf("23. Dia del Idioma\n29. Dia del Arbol\n");
						break;
		case MAYO: printf("\n---- MAYO -----\n8. Dia de la Madre\n");
				   printf("15. Dia del Maestro\n21. Dia de la Afrocolombianidad\n");
						break;
		case JUNIO: printf("\n---- JUNIO -----\n1. Dia Internacional del Niño\n");
					printf("5. Dia Mundia del Medio Ambiente\n19. Dia del Padre\n");
						break;
		case JULIO: printf("\n---- JULIO -----\n3. Dia del Economista\n");
					printf("18. Dia Internacional de Nelson Mandela\n");
						break;
		case AGOSTO: printf("\n---- AGOSTO -----\n4. Dia del Bombero\n");
					 printf("13. Dia del Humorista\n17. Dia del Ingeniero\n");
						break;
		case SEPTIEMBRE: printf("\n---- SEPTIEMBRE -----\n15. Dia Internacional de la Democracia\n");
					     printf("17. Dia del Amor y la Amistad\n");
						break;
		case OCTUBRE: printf("\n---- OCTUBRE -----\n5. Dia Mundial de los Docentes\n");
					  printf("12. Dia de la Raza\n31. Dia de Halloween\n");
						break;
		case NOVIEMBRE: printf("\n---- NOVIEMBRE -----\n12. Dia Mundial contra la Obesidad\n");
					    printf("20. Dia del Psicologo\n4to Jueves del mes Black Friday\n");
						break;
		case DICIEMBRE: printf("\n---- DICIEMBRE -----\n7. Dia de las Velitas\n");
					    printf("28. Dia de los Inocentes\n31. Año Nuevo\n");
						break;
		}

	}while(mesesAnio!=-1);

}