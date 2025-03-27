#include <stdio.h>
#include <string.h>

char string[100], alrevez[100];
int i, N, resultado;
main(){
	printf("Ingrese una palabra para saber si es un palindromo o no: ");
	scanf("%s", string);
	
	N= strlen(string) - 1;
	
	for(i=0; i <= N; i++){
		alrevez[i] = string[N - i];
	}
		
	resultado = strcmp(string, alrevez);
	
	if(resultado == 0){
		printf("La palabra |%s| es un palindromo!!!!", string);
	}
	else{
		printf("La palabra |%s| no es un palindromo", string);
	}
}