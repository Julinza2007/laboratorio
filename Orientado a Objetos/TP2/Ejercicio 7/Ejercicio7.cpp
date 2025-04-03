#include <stdio.h>
#include <string.h>
#include <ctype.h>

char string[100], string1[100], aux, aux1;
int i, j, long0, long1, respuesta;

main(){
	printf("Ingrese la primer cadena de caracteres: ");
	fgets(string, sizeof(string), stdin);
	printf("Ingrese la segunda cadena de caracteres: ");
	fgets(string1, sizeof(string1), stdin);
	
	long0 = strlen(string);
	long1 = strlen(string1);
	
	if(long0 == long1){
		if(strcmp(string, string1) == 0){
			printf("Palabras iguales. No es anagrama.");
		}
		else{
			for(i=0; i < long0 - 1; i++){
				for(j=0; j < long0 - i - 1; j++){
					if(string[j] > string[j + 1]){
						aux = string[j];
						string[j] = string[j + 1];
						string[j + 1] = aux;
					}
				}
			}
			
			for(i=0; i < long1 - 1; i++){
				for(j=0; j < long1 - i - 1; j++){
						if(string1[j] > string1[j + 1]){
						aux1 = string1[j];
						string1[j] = string1[j + 1];
						string1[j + 1] = aux1;	
						}
				}
			}
			printf("\n\nString1: %s", string);
			printf("\nString2: %s", string1);
			
			
			respuesta = strcmp(string, string1);
				if(respuesta == 0){
					printf("\nEs un anagrama.");
				}
				else{
					printf("\nNo es un anagrama.");
				}
			}
		}
		else{
			printf("\n\nPalabras con la misma longitud.");
		}
	}
