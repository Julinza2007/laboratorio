#include <stdio.h>
#include <string.h>
#include <ctype.h>

char string[100];
int i, N, contPalabra=1;


main(){
	
	printf("Ingrese unas cadenas de caracteres: ");
	fgets(string, sizeof(string), stdin);
	
	N = strlen(string);	
	for(i=0; i < N; i++){		
		if(string[i] == ' ' && string[i + 1] != ' ' && string[i + 2] != '\0'){
			contPalabra++;
		}
	}
	
	printf("\nLa cantidad de palabras existentes es de: %d", contPalabra);


	
		
}