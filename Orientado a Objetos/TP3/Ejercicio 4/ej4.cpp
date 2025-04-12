//Copiar un arreglo en otro arreglo usando punteros y funciones. Mostrando el resultado final.

#include <stdio.h>
int lista[10], copia[10], i, N=10;

void copiarArray(int i, int *ptr);

main(){	
	for(i=0; i < N; i++){
		printf("Ingrese en la posicion %d, un numero: ", i);
		scanf("%d", &lista[i]);
	}

	for(i=0; i < N; i++){
		copiarArray(i, &lista[i]);
	}
	
	printf("\n\nListado copia:\n");
	
	for(i=0; i < N; i++){
        printf("\nposicion %d es: %d\n", i, copia[i]);
	}
	
}

void copiarArray(int i, int *ptr){
	copia[i] = *ptr;
}