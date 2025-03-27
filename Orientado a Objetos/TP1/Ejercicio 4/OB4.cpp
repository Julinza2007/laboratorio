#include <stdio.h>
#include <math.h>
float cateto1=0, cateto2=0, hipotenusa=0;
int contCeros=0;

main(){
	printf("Calculadora de lados de triangulo rectangulo. Ingrese 0 en el lado que se desea calcular.\n\n");
	printf("Ingrese el valor numerico del cateto opuesto: ");
	scanf("%f", &cateto1);
		while(cateto1 < 0){
			printf("\nError, numero invalido.\nIngrese de nuevo: ");
			scanf("%f", &cateto1);
		}
		if(cateto1 == 0){
			contCeros++;
		}
		
	printf("Ingrese el valor numerico del cateto adyacente: ");
	scanf("%f", &cateto2);
		while(cateto2 < 0){
			printf("\nError, numero invalido.\nIngrese de nuevo: ");
			scanf("%f", &cateto2);
		}
		if(cateto2 == 0){
			contCeros++;
		}
		
	printf("Ingrese el valor de la hipotenusa: ");
	scanf("%f", &hipotenusa);
		while(hipotenusa < 0){
			printf("\nError, numero invalido.\nIngrese de nuevo: ");
			scanf("%f", &hipotenusa);
		}
		if(hipotenusa == 0){
			contCeros++;
		}
		
		
	if(cateto1 == 0){
		cateto1= (hipotenusa * hipotenusa) - (cateto2 * cateto2);
		cateto1= sqrt(cateto1);
	}		
		
	else if(cateto2 == 0){
		cateto2 = (hipotenusa * hipotenusa) - (cateto1 * cateto1);
		cateto2 = sqrt(cateto2);
	}
		
	else if(hipotenusa == 0){
		hipotenusa= (cateto1 * cateto1) + (cateto2 * cateto2);
		hipotenusa= sqrt(hipotenusa);
	}
	
	
	if(contCeros == 0){
		printf("\n\nError, se requiere incognita.");
	}
	
	else if(contCeros >= 2){
		printf("\n\nError, se requieren mas de dos datos para calcular.");
	}
	
	else if(cateto1 >= hipotenusa || cateto2 >= hipotenusa){
		printf("\n\nError, Segun la formula, la hipotenusa siempre es mayor que cada cateto.");
	}
	
	
	else{
		printf("\nDel triangulo rectangulo se sabe que:\nEl cateto opuesto es igual a %f.\nEl cateto adyacente es igual a %f.\nY la hipotenusa es igual a %f.", cateto1, cateto2, hipotenusa);
	}
	
}
