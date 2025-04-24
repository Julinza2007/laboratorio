#include <stdio.h>
#include <string.h>

int validarArchivo(FILE *ar);
void ingresarPersona(FILE *ar);
void buscarPorDni(FILE *ar);
void buscarPersona(FILE *ar);


int main(){
	FILE *archivo;
	int opc;
	
	do{
		printf("\nIngrese 1 para ingresar datos\nIngrese 2 para buscar por DNI\nIngrese 3 para buscar por nombre y apellido\nIngrese 4 para salir.\n\nIngrese opcion: ");
		scanf("%d", &opc);
		while(opc < 1 || opc > 4){
			printf("Error, ingrese de nuevo: ");
			scanf("%d", &opc);
		}
		
		switch(opc){
			case 1:
			archivo = fopen("datos.txt", "a");				
			if(validarArchivo(archivo) != 1){				
				ingresarPersona(archivo);	
			}
			
			fclose(archivo);
			
			break;
			
			case 2:
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					buscarPorDni(archivo);
				}							
			
			
			break;
			
			
			
			case 3:
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					buscarPersona(archivo);
				}				
			
			break;
		
			case 4:
					printf("Saliendo.");
			break;
		
			default:
					printf("Opcion invalida");
			break;
	
		}
	
	} while(opc != 3);
	
	
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

void ingresarPersona(FILE *ar){
	char n[50], a[50];
	int d;		
			printf("\nIngrese nombre: ");
			scanf("%s", n);
			printf("\nIngrese apellido: ");
			scanf("%s", a);
			printf("\nIngrese DNI: ");
			scanf("%d", &d);
			printf("\n");
			
			fprintf(ar, "Nombre: %s ", n);
			fprintf(ar, "Apellido: %s ", a);
			fprintf(ar, "DNI: %d\n", d);
	}
	
	
	
void buscarPorDni(FILE *ar){
	char nombre[50], apellido[50];
	int	encontrado=0, DNI, dniBuscado;

	printf("\nIngrese un DNI: ");
	scanf("%d", &dniBuscado);
	
		while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) && encontrado != 1){
				if(DNI == dniBuscado){
					printf("\nNombre: %s\nApellido: %s\n", nombre, apellido);
					encontrado = 1;
				}
		}
}
	
	
void buscarPersona(FILE *ar){		
	char nomBuscado[50], apeBuscado[50];		
		
			printf("\nIngrese el nombre a buscar: ");
			scanf("%s", nomBuscado);
			printf("Ingrese el apellido a buscar: ");
			scanf("%s", apeBuscado);
		
		char linea[100];
		int encontrado = 0;		
		
		while(fgets(linea, sizeof(linea), ar) != NULL && encontrado != 1){
			if(strstr(linea, nomBuscado) && strstr(linea, apeBuscado)){
				printf("\nPersona encontrada: %s", linea);
				encontrado = 1;		
			}
		}
	
		if(encontrado == 0){
			printf("\nLa persona buscada no fue encontrada.\n");
		}
}