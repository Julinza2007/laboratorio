#include <stdio.h>
#include <math.h>
float cateto1, cateto2, hipotenusa=0;

main(){
	printf("Ingrese el valor numerico del primer cateto: ");
	scanf("%f", &cateto1);
	printf("Ingrese el valor numerico del segundo cateto: ");
	scanf("%f", &cateto2);
	printf("Ingrese el valor de la hipotenusa: ");
	scanf("%f", &hipotenusa);
	
	hipotenusa= (cateto1 * cateto1) + (cateto2 * cateto2);
	hipotenusa = sqrt(hipotenusa);
	
	printf("\n\nLa hipotenusa vale: %f", hipotenusa);
}
