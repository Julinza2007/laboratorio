#include <stdio.h>
#include <ctype.h>
char nombre[100];

main(){
	
	printf("Ingrese el nombre del usuario: ");
	fgets(nombre, sizeof(nombre), stdin);
	
	printf("El nombre del usuario es: %s", nombre);	
	
}