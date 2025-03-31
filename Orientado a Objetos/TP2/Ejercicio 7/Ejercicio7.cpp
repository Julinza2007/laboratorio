#include <stdio.h>
#include <string.h>
#include <ctype.h>

char string[100], string1[100];
int i, long0, long1, contIgual=0;

main(){
	printf("Ingrese la primer cadena de caracteres: ");
	fgets(string, sizeof(string), stdin);
	printf("Ingrese la segunda cadena de caracteres: ");
	fgets(string1, sizeof(string1), stdin);
	
	long0 = strlen(string) - 1;
	long1 = strlen(string1) - 1;
	
	if(long0 == long1){
		if(strcmp(string, string1) == 0){
			printf("Palabras iguales.");
		}
		else{
			for(i=0; i < (long0 * long1); i++){
				printf("Posicion: |%d| Caracter: |%c|\n", i, string1[i]);
				if(string1[i] == string[i]){
					contIgual++;
				}
			}
			if(contIgual == long1){
				printf("Es un anagrama.");
			}
		}
	}
	
	
}