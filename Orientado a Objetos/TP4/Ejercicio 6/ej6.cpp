/*
Realizar un programa que realice las siguientes acciones:
1) Guarde el registro del nombre y el puntaje de un jugador (solicitando el ingreso de los datos del usuario)
2) Muestre el resultado de los 10 mejores jugadores ordenados por mayor puntaje.
3) Realice y muestre una busqueda de un Nombre y devuelva sus resultados
NOTA: el registro debe permanecer aunque se apague la PC.
*/
#include <stdio.h>
#include <string.h>

int validarArchivo(FILE *ar);
void ingresarJugador(FILE *ar);
void mostrarMejores(FILE *ar);
void buscarPorNombre(FILE *ar);

int main(){
	FILE *archivo;
	int opc;
	
do{
	printf("Ingrese 1 para ingresar jugador con sus puntos.\nIngrese 2 para mostrar los 10 mejores jugadores en base a puntos.\nIngrese 3 para buscar jugador.\nIngrese 0 para salir.\nIngrese opcion: ");
	scanf("%d", &opc);
	while(opc < 0 || opc > 3){
		printf("\nError, ingrese de nuevo: ");
		scanf("%d", &opc);
	}
	
	switch(opc){
			case 1:	
				archivo = fopen("datos.txt", "a+");	
			
				if(validarArchivo(archivo) != 1){
					ingresarJugador(archivo);
				}
				
				fclose(archivo);
		
			break;
		
		
		
			case 2:
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					rewind(archivo);
					mostrarMejores(archivo);
				}
				
				fclose(archivo);		
			
			break;
		
		
			case 3:
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					buscarPorNombre(archivo);
				}
				
				fclose(archivo);			
		
			break;
		
		
			case 0:
				printf("\n\nSaliendo...");
			break;
		
		
		}	
	}while(opc != 0);	
		
	return 0;
}

int validarArchivo(FILE *ar){
	if(ar == NULL){
		printf("\nError al abrir el archivo\n\n");
		return 1;
	}
	else{
		return 0;
	}
}

void ingresarJugador(FILE *ar){
	char nombre[50];
	int puntaje;
	
	printf("\nIngrese el nombre del jugador: ");
	scanf("%s", nombre);
	
	printf("Ingrese el puntaje de %s: ", nombre);
	scanf("%d", &puntaje);
	
	printf("\n\n");
	
	rewind(ar);
	
	fprintf(ar, "Nombre: %s ", nombre);
	fprintf(ar, "Puntaje: %d\n", puntaje);
}


void mostrarMejores(FILE *ar){
	int i=0, j=0, N=0, puntaje;
	char tempNom[50];
	char nombre[50];
	char nombres[256][50];
	int puntajes[256];
	
	
		while(fscanf(ar, "Nombre: %s Puntaje: %d\n", nombre, &puntaje) == 2){
			strcpy(nombres[i], nombre);
			puntajes[i] = puntaje;			
			i++;
			N++;
		}
		
		for(i=0; i < N - 1; i++){
			for(j=0; j < N - i - 1; j++){			
				if(puntajes[j] < puntajes[j + 1]){
					int tempPunt = puntajes[j];
					puntajes[j] = puntajes[j + 1];
					puntajes[j + 1] = tempPunt;				
							
					strcpy(tempNom, nombres[j]);
					strcpy(nombres[j], nombres[j + 1]);
					strcpy(nombres[j + 1], tempNom);
				}
			
			}
		}
		
		printf("\n\nLos 10 mejores jugadores son:\n");
		for(i=0; i < 10; i++){
			printf("\n%d. %s con %d puntos", i + 1, nombres[i], puntajes[i]);
		}
		printf("\n\n");
}

void buscarPorNombre(FILE *ar){
	char nombre[50], nomBuscado[50];
	int puntaje, encontrado=0;
	
	printf("\n\nIngrese el nombre de un jugador para mostrar resultados: ");
	scanf("%s", nomBuscado);
	
	while(fscanf(ar, "Nombre: %s Puntaje: %d\n", nombre, &puntaje) == 2 && encontrado != 1){
		
		if(strcmp(nombre, nomBuscado) == 0){
			encontrado = 1;
			printf("\n%s tiene %d puntos\n\n", nombre, puntaje);
		}
	}
	if(encontrado == 0){
		printf("\n%s no fue encontrado.\n\n", nomBuscado);
	}
}