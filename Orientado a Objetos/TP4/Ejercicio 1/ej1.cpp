#include <stdio.h>

int main(){
	FILE *archivo;
	char nombre[50], apellido[50];
	int opc, DNI, dniBuscado, encontrado=0;
	
	
	do{
		printf("Ingrese opcion 1 para ingresar datos\nIngrese opcion 2 para buscar por DNI\nIngrese opcion 3 para salir.\n");
		scanf("%d", &opc);
		while(opc != 1 && opc != 2 && opc != 3){
			printf("Error, ingrese de nuevo: ");
			scanf("%d", &opc);
		}
		
		switch(opc){
			case 1:
				archivo = fopen("datos.txt", "a");
		
				if(archivo == NULL){
					printf("Error al abrir el archivo\n");
					return 1;
				}
	
				printf("\tIngrese datos\n");
				printf("\nIngrese nombre: ");
				scanf("%s", nombre);
				printf("\nIngrese apellido: ");
				scanf("%s", apellido);
				printf("\nIngrese DNI: ");
				scanf("%d", &DNI);
		
				//	printf("\n\nNombre: %s\nApellido: %s\nDNI: %d", nombre, apellido, DNI);	

				fprintf(archivo, "Nombre: %s\n", nombre);
				fprintf(archivo, "Apellido: %s\n", apellido);
				fprintf(archivo, "DNI: %d\n", DNI);
				fclose(archivo);
			
			break;
			
			case 2:
				archivo = fopen("datos.txt", "r");
				if(archivo == NULL){
					printf("No se pudo abrir el archivo\n.");
					return 1;
				}
			
				printf("\nIngrese el DNI a buscar: ");
				scanf("%d", &dniBuscado);
				
				encontrado=0;
				
				while(fscanf(archivo, "Nombre: %s\nApellido: %s\nDNI: %d\n", nombre, apellido, &DNI) == 3 && encontrado != 1){
					if (DNI == dniBuscado){
						printf("Nombre: %s\nApellido: %s\n", nombre, apellido);
						encontrado = 1;
					}
				}
				
				if(encontrado == 0){
					printf("\n\nNo se encontro a la persona.\n\n");
				}
				
				fclose(archivo);
			
			break;
		
			case 3:
					printf("Saliendo.");
			break;
		
			default:
					printf("Opcion invalida");
			break;
	
		}
	
	} while(opc != 3);
	
	return 0;
}
