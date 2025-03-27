#include <stdio.h>

int i=0, numeros, contPar=0, contImpar=0, opc;

main(){
	
	do{
		printf("\nIngrese del espacio de memoria %d, un numero: ", i);
		scanf("%d", &numeros);
		
		if(numeros % 2 == 0){
			contPar++;
		}
		else if(numeros % 2 != 0){
			contImpar++;
		}
		
		i++;
		
		printf("\n\nSi desea continuar ingrese 1. Si no ingrese 0.\n");
		scanf("%d", &opc);	
		
	}
	while(opc != 0);
	
	printf("\n\nLa cantidad de numeros es de: %d", i);
	printf("\nLa cantidad de numeros pares es de: %d.", contPar);
	printf("\nLa cantidad de numeros impares es de: %d.", contImpar);
	
	
}
