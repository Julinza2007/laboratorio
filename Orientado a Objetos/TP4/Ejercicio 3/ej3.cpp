#include <stdio.h>
#include <string.h>

// Para validar que no se repitan las personas me tengo que fijar en el DNI, y para eso tengo que hacer que sea unico.
// Si un DNI se repite se anula el ingreso de datos.
// Por lo que la validacion de la persona es parte de la entrada de datos.

int validarArchivo(FILE *ar);
void ingresarPersona(FILE *ar);
int validarPersona(FILE *ar, int dniIngreso);
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
				archivo = fopen("datos.txt", "a+"); // a+ lo que hace es leer y escribir acoplando.	
				rewind(archivo);
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
			
				fclose(archivo);
			
			break;
			
			
			case 3:
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					buscarPersona(archivo);
				}
				
				fclose(archivo);				
			
			break;
		
		
			case 4:
					printf("\n\nSaliendo.");
			break;
		}
	} while(opc != 4);
	
	
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
			printf("\n\nIngrese nombre: ");
			scanf("%s", n);
			printf("Ingrese apellido: ");
			scanf("%s", a);
			printf("Ingrese DNI: ");
			scanf("%d", &d);
			printf("\n");
			
			if(validarPersona(ar, d) != 1){
				fprintf(ar, "Nombre: %s ", n);
				fprintf(ar, "Apellido: %s ", a);
				fprintf(ar, "DNI: %d\n", d);
			}
			else{
				printf("\nError de ingreso, ya existe una persona con el mismo DNI.\n\n");
			}
	}
	
	
int validarPersona(FILE *ar, int dniIngreso){
	char nombre[50], apellido[50];
	int DNI, repetido=0;
	
	while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) == 3 && repetido != 1){
		if(DNI == dniIngreso){
			repetido = 1;
		}
	}
	
	return repetido;	
	
}	

	
	
void buscarPorDni(FILE *ar){
	char nombre[50], apellido[50];
	int	encontrado=0, DNI, dniBuscado;

	printf("\nIngrese un DNI: ");
	scanf("%d", &dniBuscado);
	
		while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) == 3 && encontrado != 1){
				if(DNI == dniBuscado){
					printf("\nNombre: %s\nApellido: %s\n", nombre, apellido);
					encontrado = 1;
				}
		}
}
	
	
void buscarPersona(FILE *ar){		
	char nomBuscado[50], apeBuscado[50], nombre[50], apellido[50];
	int DNI;		
		
			printf("\nIngrese el nombre a buscar: ");
			scanf("%s", nomBuscado);
			printf("Ingrese el apellido a buscar: ");
			scanf("%s", apeBuscado);
		
		int encontrado = 0;		
		
		while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) == 3 && encontrado != 1){
			if(strcmp(nombre, nomBuscado) == 0 && strcmp(apellido, apeBuscado) == 0){
				printf("\nPersona encontrada:\nNombre: %s\nApellido: %s\nDNI: %d\n", nombre, apellido, DNI);
				encontrado = 1;		
			}
		}
	
		if(encontrado == 0){
			printf("\nLa persona buscada no fue encontrada.\n");
		}
}