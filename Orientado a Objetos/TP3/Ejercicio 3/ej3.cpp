#include <stdio.h>
int numeros[10], i, N=10, i_max, i_min, menor, mayor;

void buscarMayor(int i, int *ptr);
void buscarMenor(int i, int *ptr);

main(){
	for(i=0; i < N; i++){
		printf("Ingrese para la posicion %d, el numero: ", i);
		scanf("%d", &numeros[i]);
	}
	
	for(i=0; i < N; i++){
		buscarMayor(i, &numeros[i]);
		buscarMenor(i, &numeros[i]);
	}

	printf("\n\nEl numero mayor es %d y corresponde a la posicion de memoria %d", mayor, i_max);
	printf("\nEl numero menor es %d y corresponde a la posicion de memoria %d", menor, i_min);

}

void buscarMayor(int i, int *ptr){
	if(i==0 || *ptr > mayor){
		i_max = i;
		mayor = *ptr;
	}
}

void buscarMenor(int i, int *ptr){
	if(i==0 || *ptr < menor){
		i_min = i;
		menor = *ptr;
	}
}