#include <stdio.h>
#include <string.h>
//Hay que crear un archivo paralelo a datos.txt que se llame cambios.txt.
//Y en cambios.txt se añaden los nuevos registros.
//datos.txt tiene que tener datos fijos que no pueden ser modificados.
//las opciones se ejecutan en cambios.txt ahora.
//Tengo que copiar el contenido fijo de datos.txt en cambios.txt, no quiero que se dupliquen los registros copiados.
//Por lo tanto debo validar que la copia ya está hecha con algun booleano antes, pero debe estar en el archivo ese booleano.

void copiarDatos(FILE *ar, FILE *cmb);
int validarArchivo(FILE *ar);
void saltarMarca(FILE *ar);
void ingresarPersona(FILE *ar);
int validarPersona(FILE *ar, int dniIngreso);
void buscarPorDni(FILE *ar);
void busc
arPersona(FILE *ar);
void mostrarOrdenado(FILE *ar, int opc);


int main(){
	
	FILE *archivo, *cambios;
	int opc, opcOrdenado;
	
	
	archivo = fopen("datos.txt", "r");
	cambios = fopen("cambios.txt", "a+");
	
	copiarDatos(archivo, cambios);
	
	fclose(archivo);
	fclose(cambios);
	
	do{
		printf("\nIngrese 1 para ingresar datos\nIngrese 2 para buscar por DNI\nIngrese 3 para buscar por nombre y apellido\nIngrese 4 para mostrar todos los datos.\nIngrese 0 para salir.\n\nIngrese opcion: ");
		scanf("%d", &opc);
		while(opc < 0 || opc > 4){
			printf("Error, ingrese de nuevo: ");
			scanf("%d", &opc);
		}
		
		switch(opc){
			case 1:
				cambios = fopen("cambios.txt", "a+");
				
				 if(validarArchivo(cambios) != 1){
                    ingresarPersona(cambios);
                }
			
				fclose(cambios);
				
			break;
			
			
			case 2:
				cambios = fopen("cambios.txt", "r");
				
				if(validarArchivo(cambios) != 1){
					buscarPorDni(cambios);
				}							
			
				fclose(cambios);
			
			break;
			
			
			case 3:
				cambios = fopen("cambios.txt", "r");
				
				if(validarArchivo(cambios) != 1){
					buscarPersona(cambios);
				}
				
				fclose(cambios);				
			
			break;
		
			case 4:
				cambios = fopen("cambios.txt", "r");
				
				if(validarArchivo(cambios) != 1){
					printf("\tIngrese 5 para ordenar por nombre primero.\n\tIngrese 6 para ordenar por apellido primero.\n\tIngrese 7 para ordenar por DNI primero.\n\tIngrese opcion: ");
					scanf("%d", &opcOrdenado);
					while(opcOrdenado < 5 || opcOrdenado > 7){
						printf("Opción invalida para ordenar, ingrese de nuevo: ");
						scanf("%d", &opcOrdenado);
					}
					
					
					mostrarOrdenado(cambios, opcOrdenado);
				}
				
				fclose(cambios);
				
			break;
		
			case 0:
				printf("\n\nSaliendo.");
			break;
		}
	} while(opc != 0);
	
	
	return 0;
}



void copiarDatos(FILE *ar, FILE *cmb){
	char marca[20] = "COPIA_REALIZADA";
    char marcaCopia[50];
    char nomArchivo[50], apeArchivo[50];
    int dniArchivo;
    int boolCopia = 0;

	
	if(validarArchivo(ar) != 1 && validarArchivo(cmb) != 1){
		//tengo que poner la marca para saber si ya esta hecha la copia o no.
		//para eso tengo que buscar si esta hecha esa marca, lo haria con un fscanf.
		rewind(cmb); // Creo que casi siempre que se usa el a+ se usa el rewind para ir al inicio del archivo.
		while(fscanf(cmb, "%s", marcaCopia) == 1 && boolCopia != 1){
			
			if(strcmp(marca, marcaCopia) == 0){
				boolCopia = 1;
			}
						
		}
		
		if(boolCopia == 0){
			fprintf(cmb, "COPIA_REALIZADA\n");
			
			while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nomArchivo, apeArchivo, &dniArchivo) == 3){
				fprintf(cmb, "Nombre: %s Apellido: %s DNI: %d\n", nomArchivo, apeArchivo, dniArchivo);
			}
		}
		
	}
	
	
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

void saltarMarca(FILE *ar){
// Quiero que me detecte la linea que dice COPIA_REALIZADA y cuando la detecte quiero que se la saltee.
   char palabra[20];
   
   if(fscanf(ar, "%s", palabra) == 1 && strcmp(palabra, "COPIA_REALIZADA") == 0){
   	fgets(palabra, sizeof(palabra), ar); //Utilizo el fgets para saltearme la linea asi en la proxima lectura no aparece COPIA_REALIZADA
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
			
			rewind(ar);
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
	
	saltarMarca(ar);
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
	
	saltarMarca(ar);
	
		while(fscanf(ar, "Nombre: %s Apellido: %s DNI: %d\n", nombre, apellido, &DNI) == 3 && encontrado != 1){
				if(DNI == dniBuscado){
					printf("\nNombre: %s\nApellido: %s\n", nombre, apellido);
					encontrado = 1;
				}
		}
		
		if(encontrado == 0){
		   printf("\nDNI no encontrado.\n");
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
		
		saltarMarca(ar);
		
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
	
	
	saltarMarca(ar);
	
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
	
	for(i = 0; i < N; i++){
    printf("\nNombre: %s Apellido: %s DNI: %d\n", nombres[i], apellidos[i], DNIs[i]);
	}
	
}