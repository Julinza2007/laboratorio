#include <stdio.h>
#include <string.h>

//Para mostrar todos los registros segun nombre, apellido o DNI usaria un fscanf y almacenaria un array de cada dato y luego lo muestro.


int validarArchivo(FILE *ar);
void ingresarPersona(FILE *ar);
int validarPersona(FILE *ar, int dniIngreso);
void buscarPorDni(FILE *ar);
void buscarPersona(FILE *ar);
void mostrarOrdenado(FILE *ar, int opc);


int main(){
	FILE *archivo;
	int opc, opcOrdenado;
	
	do{
		printf("\nIngrese 1 para ingresar datos\nIngrese 2 para buscar por DNI\nIngrese 3 para buscar por nombre y apellido\nIngrese 4 para mostrar todos los datos.\nIngrese 0 para salir.\n\nIngrese opcion: ");
		scanf("%d", &opc);
		while(opc < 0 || opc > 4){
			printf("Error, ingrese de nuevo: ");
			scanf("%d", &opc);
		}
		
		switch(opc){
			case 1:
				archivo = fopen("datos.txt", "a+"); // a+ lo que hace es leer y escribir acoplando.	
				rewind(archivo); // va hacia al principio porque el a+ lo requiere.
				
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
				archivo = fopen("datos.txt", "r");
				
				if(validarArchivo(archivo) != 1){
					printf("\tIngrese 5 para ordenar por nombre primero.\n\tIngrese 6 para ordenar por apellido primero.\n\tIngrese 7 para ordenar por DNI primero.\n\tIngrese opcion: ");
					scanf("%d", &opcOrdenado);
					mostrarOrdenado(archivo, opcOrdenado);
				}
				
				fclose(archivo);
				
			break;
		
			case 0:
				printf("\n\nSaliendo.");
			break;
		}
	} while(opc != 0);
	
	
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

void mostrarOrdenado(FILE *ar, int opc){
	char nombre[50], apellido[50];
	int DNI, DNIs[50];	
	char nombres[25][50], apellidos[25][50];
	int N=0, i=0, j=0;
	
	
	while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) == 3){
		strcpy(nombres[i], nombre);
		strcpy(apellidos[i], apellido);
		DNIs[i] = DNI;
		i++;
		N++;
	}
	
	for(i=0; i < N - 1; i++){
		for(j=0; j < N - i - 1; j++){
			int cmp = 0;
			
			if(opc == 5){
				cmp = strcmp(nombres[j], nombres[j + 1]) > 0;
			}
			else if(opc == 6){
				cmp = strcmp(apellidos[j], apellidos[j + 1]) > 0;
			}
			else if(opc == 7){
				cmp = DNIs[j] > DNIs[j + 1];
			}
			
			if(cmp == 1){
				char temp[50];
				strcpy(temp, nombres[j]);
				strcpy(nombres[j], nombres[j + 1]);
				strcpy(nombres[j + 1], temp);
				
				strcpy(temp, apellidos[j]);
				strcpy(apellidos[j], apellidos[j + 1]);
				strcpy(apellidos[j + 1], temp);

				int tempDNIs = DNIs[j];
				DNIs[j] = DNIs[j + 1];
				DNIs[j + 1] = tempDNIs;
			}
			
			
		}
	}	
	
	for(i=0; i < N; i++){
		printf("\nPersona numero %d:\n", i + 1);
		printf("Nombre: %s\nApellido: %s\nDNI: %d\n\n", nombres[i], apellidos[i], DNIs[i]);
	}	
	
}