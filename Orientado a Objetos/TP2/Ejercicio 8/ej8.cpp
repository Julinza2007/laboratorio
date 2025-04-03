#include <stdio.h>
#include <string.h>
#include <ctype.h>
char string[30], string1[30], string2[30], string3[30], string4[30];
int longi, longi1, longi2, longi3, longi4;

main(){
	printf("Ingrese la primer palabra: ");
	fgets(string, sizeof(string), stdin);
	printf("Ingrese la segunda palabra: ");
	fgets(string1, sizeof(string1), stdin);
	printf("Ingrese la tercer palabra: ");
	fgets(string2, sizeof(string2), stdin);
	printf("Ingrese la cuarta palabra: ");
	fgets(string3, sizeof(string3), stdin);
	printf("Ingrese la quinta palabra: ");
	fgets(string4, sizeof(string4), stdin);

	longi  = strlen(string);
	longi1 = strlen(string1);
	longi2 = strlen(string2);
	longi3 = strlen(string3);
	longi4 = strlen(string4);

	for(i=0; i < longi; i++){
				
	}
	
	
}