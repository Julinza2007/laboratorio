#include <stdio.h>
#include <string.h>

char string[100], subcadena[100], *ptr;

main(){
	printf("Ingrese una string: ");
	fgets(string, sizeof(string), stdin);
    if(string[strlen(string) - 1] == '\n'){
        string[strlen(string) - 1] = '\0';
    }
	printf("Ingrese una subcadena para saber si se encuentra o no: ");
	fgets(subcadena, sizeof(subcadena), stdin);
    if(subcadena[strlen(subcadena) - 1] == '\n'){
        subcadena[strlen(subcadena) - 1] = '\0';
    }
	
	ptr = strstr(string, subcadena);
	
	if(ptr != NULL){
		printf("La subcadena |%s| se encuentra en la cadena |%s| en la posicion numero %d\n", subcadena, string, ptr - string);
	}
	else{
		printf("La subcadena |%s| no se ha encontrado en la cadena |%s|", subcadena, string);
	}
	
	
}
