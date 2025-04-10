#include <stdio.h>
char letra, letra1, temp;

void intercambiar(char *l, char *l1);

main(){
	printf("Ingrese la primer letra: ");
	scanf(" %c", &letra);
	
	printf("Ingrese la segunda letra: ");
	scanf(" %c", &letra1);
	
	
	intercambiar(*l, *l1){
	temp = *l;
	*l = *l1;
	*l1 = temp;
}

	intercambiar(&letra, &letra1);
	
	printf("\nLa primer letra es: %c\n", letra);
	printf("La segunda letra es: %c", letra1);
	
}

