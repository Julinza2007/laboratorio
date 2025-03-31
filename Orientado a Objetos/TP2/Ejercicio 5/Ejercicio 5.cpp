#include <stdio.h>
#include <string.h>

char string[100];
int i, N, contPalabra=1;


main(){
	
	printf("Ingrese unas cadenas de caracteres: ");
	scanf(" %[^\n]s", string);
	
	N = strlen(string);
	printf("Cantidad de caracteres: %d\n\n", N);
	
	for(i=0; i < N; i++){
		printf("%c\n", string[i]);
		
		if(string[i] == ' ' && string[i + 1] != ' ' && string[i + 1] != '\0'){
			contPalabra++;
		}
	}
	
	printf("\nLa cantidad de palabras existentes es de: %d", contPalabra);


	
		
}