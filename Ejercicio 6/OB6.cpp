#include <stdio.h>
#include <math.h>

int i=0, N, numeros, esPrimo=1, contPrimo=0, contNoPrimo=0, opc;

main(){
	
	do{
		printf("\nIngrese del espacio de memoria %d, un numero: ", i);
		scanf("%d", &numeros);
		
			if(numeros <= 1){
		contNoPrimo++;
	}
	
	else if(numeros == 2 || numeros == 3){
		contPrimo++;
	}
	
	else if(numeros % 2 == 0){
		contNoPrimo++;
	}
	
	
	else{
		for(N=3; N <= sqrt(numeros); N+=2){
			if(numeros % N == 0){
				esPrimo=0;
			}
		}

		if(esPrimo == 1){
			contPrimo++;
		}	
		else if(esPrimo == 0){
			contNoPrimo++;
		}
	
	}
	
	i++;
	esPrimo= 1;
	
	printf("\n\nSi desea continuar ingrese 1. Si no ingrese 0.\n");
	scanf("%d", &opc);				
			
	}	
	while(opc != 0);
	
	printf("\n\nLa cantidad de numeros es de: %d", i);
	printf("\nLa cantidad de numeros primos es de: %d.", contPrimo);
	printf("\nLa cantidad de numeros que no son primos es de: %d.", contNoPrimo);
	
}