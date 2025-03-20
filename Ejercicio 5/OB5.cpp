#include <stdio.h>
#include <math.h>
int numero, i, esPrimo=1;

main(){
	printf("Ingrese un numero para saber si es primo o no: ");
	scanf("%d", &numero);
	
	if(numero <= 1){
		printf("El numero %d no es primo debido a que es uno negativo.", numero);
	}
	
	else if(numero == 2 || numero == 3){
		printf("El numero %d es primo.", numero);
	}
	
	else if(numero % 2 == 0){
		printf("El numero %d no es primo.", numero);
	}
	
	
	else{
		for(i=3; i <= sqrt(numero); i+=2){
			if(numero % i == 0){
				esPrimo=0;
			}
		}

		if(esPrimo == 1){
			printf("El numero %d es primo.", numero);
		}	
		else if(esPrimo == 0){
			printf("El numero %d no es primo.", numero);
		}
	
	}
	
	
}