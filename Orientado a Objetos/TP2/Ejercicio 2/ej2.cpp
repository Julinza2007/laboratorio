#include <stdio.h>
#include <string.h>

char string[100];
int i, longitud, contVocal;


main(){

printf("Ingrese un string para saber cuantas vocales tiene: ");
scanf("%s", string);

longitud = strlen(string);

for(i=0; i < longitud; i++){

	
	if(string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U'){
		contVocal++;
	}
	
}

	if(contVocal > 0){
		printf("La cantidad de vocales encontrada de la palabra |%s| es de: %d", string, contVocal);
	}
	else{
		printf("No se encontraron vocales.");
	}

}