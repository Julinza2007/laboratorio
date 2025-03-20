#include <stdio.h>
#include <math.h>

int i=0, N, J, esPrimo=1, auxPar, auxImpar, auxPrimo, numeros[100], numerosPar[100], numerosImpar[100], numerosPrimos[100],
contPar=0, contImpar=0, contPrimo=0, opc;

main(){
	
	do{
		printf("\nIngrese del espacio de memoria %d, un numero: ", i);
		scanf("%d", &numeros[i]);
		
		if(numeros[i] % 2 == 0){
			numerosPar[contPar] = numeros[i];
			contPar++;			
		}
		
		else{
			numerosImpar[contImpar] = numeros[i];
			contImpar++;
		}
		
		if(numeros[i] == 2 || numeros[i] == 3){
			esPrimo = 1;
		}
		
		else if(numeros[i] < 2 || numeros[i] % 2 == 0){
        	esPrimo = 0;
    	}
	
		else{
			for(N=3; N <= sqrt(numeros[i]); N+=2){
				if(numeros[i] % N == 0){
					esPrimo = 0;
				}
			}
		}
		
		if(esPrimo == 1){
			numerosPrimos[contPrimo] = numeros[i];
			contPrimo++;
		}
		
		i++;
		esPrimo=1;
		
		printf("\n\nSi desea continuar ingrese 1. Si no ingrese 0.\n");
		scanf("%d", &opc);	
		
	}
	while(opc != 0);
	
		
	for(J = 1; J < contPar; J++){ 
    	for(i = 0; i < contPar - J; i++){ 
        	if(numerosPar[i] > numerosPar[i + 1]){
           		auxPar = numerosPar[i];
            	numerosPar[i] = numerosPar[i + 1];
            	numerosPar[i + 1] = auxPar;
        	}
    	}	
	}


	for(J = 1; J < contImpar; J++){ 
    	for(i = 0; i < contImpar - J; i++){ 
        	if(numerosImpar[i] < numerosImpar[i + 1]){
         	   auxImpar = numerosImpar[i];
           	 numerosImpar[i] = numerosImpar[i + 1];
           	 numerosImpar[i + 1] = auxImpar;
        	}
   		}
	}


	for(J = 1; J < contPrimo; J++){ 
    	for(i = 0; i < contPrimo - J; i++){ 
        	if(numerosPrimos[i] > numerosPrimos[i + 1]){
            	auxPrimo = numerosPrimos[i];
            	numerosPrimos[i] = numerosPrimos[i + 1];
            	numerosPrimos[i + 1] = auxPrimo;
        	}
    	}
	}
	


	

	printf("\n\nPosiciones de menor a mayor de numeros Pares:");

	for(i= 0; i < contPar; i++){
    	printf("\n\nPosicion |%d|, numero Par |%d|", i + 1, numerosPar[i]);
	}

	printf("\n\nPosiciones de mayor a menor de numeros Impares:");

	for(i=0; i < contImpar; i++){
   	 printf("\n\nPosicion |%d|, numero impar |%d|", i + 1, numerosImpar[i]);
	}
	
	printf("\n\nPosiciones de menor a mayor de numeros Primos:");

	for(i=0; i < contPrimo; i++){
    	printf("\n\nPosicion |%d|, numero Primo |%d|", i + 1, numerosPrimos[i]);
	}	
	
	
}
