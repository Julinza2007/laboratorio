#include <stdio.h>
char letra, letra1;

void intercambiar(char *l, char *l1); // Esto es un prototipo de la funcion

main(){
	printf("Ingrese la primer letra: ");
	scanf(" %c", &letra);
	
	printf("Ingrese la segunda letra: ");
	scanf(" %c", &letra1);

	intercambiar(&letra, &letra1);
	
	printf("\nLa primer letra ahora es: %c\n", letra);
	printf("La segunda letra ahora es: %c", letra1);
	
}

void intercambiar(char *l, char *l1){
	char temp = *l;
	*l = *l1;
	*l1 = temp;
}

