#include <stdio.h>
float suma(float *ptr1, float *ptr2);
float promedio(float *ptr1, float *ptr2);

main(){
	float num1, num2, resultSuma, resultPromedio;
	
	printf("Ingrese el primer numero: ");
	scanf("%f", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%f", &num2);

	resultSuma = suma(&num1, &num2);
	resultPromedio = promedio(&num1, &num2);
	
	printf("\n\nSuma %f + %f es igual a %f\n", num1, num2, resultSuma);
	printf("El promedio es igual a %f", resultPromedio);
}

float suma(float *ptr1, float *ptr2){
	return *ptr1 + *ptr2;
}

float promedio(float *ptr1, float *ptr2){
	float acum = suma(ptr1, ptr2);
	return acum / 2;
}





