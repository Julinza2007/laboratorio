#include <stdio.h>
#include <string.h>

char string[100];
int i, N, contPalabra=1;


main(){
	
	printf("Ingrese una cadena de caracteres: ");
	scanf("%s", string);
	
	N = strlen(string) - 1;
	
	for(i=0; i <= N; i++){
		if(string[i] == ' '){
			contPalabra++;
		}
	}
	
	printf("La cantidad de palabras ingresada es de: %d", contPalabra);
	
}