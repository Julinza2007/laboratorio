/*Con opcion a elegir lo que quiero calcular*/
#include <stdio.h>
#include <math.h>
float cateto1=0, cateto2=0, hipotenusa=0;
int opc;

main(){
	printf("Calculadora de lados de triangulo rectangulo.\nIngrese 1 si desea calcular el cateto opuesto.\nIngrese 2 si desea calcular el adyacente.\nIngrese 3 si desea calcular la hipotenusa.\n");
	scanf("%d", &opc);

	if(opc == 1){
		printf("Ingrese el valor de la hipotenusa: ");
		scanf("%f", &hipotenusa);
			while(hipotenusa < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &hipotenusa);
			}
		printf("Ingrese el valor numerico del cateto adyacente: ");
		scanf("%f", &cateto2);
			while(cateto2 < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &cateto2);
			}
	}
	else if(opc == 2){
		printf("Ingrese el valor de la hipotenusa: ");
		scanf("%f", &hipotenusa);
			while(hipotenusa < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &hipotenusa);
			}
		printf("Ingrese el valor numerico del cateto opuesto: ");
		scanf("%f", &cateto1);
			while(cateto1 < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &cateto1);
			}		
	}
	else if(opc == 3){
		printf("Ingrese el valor numerico del cateto opuesto: ");
		scanf("%f", &cateto1);
			while(cateto1 < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &cateto1);
			}	
		printf("Ingrese el valor numerico del cateto adyacente: ");
		scanf("%f", &cateto2);
			while(cateto2 < 0){
				printf("\nError, numero invalido.\nIngrese de nuevo: ");
				scanf("%f", &cateto2);
			}
	}




}
