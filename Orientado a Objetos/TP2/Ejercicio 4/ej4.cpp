#include <stdio.h>
#include <string.h>

char string[100], cambio[100], letra, reemplazo;
int i, N, comp;

main(){
	printf("Ingrese una palabra: ");
	scanf("%s", string);
	N= strlen(string) - 1;
	
	strcpy(cambio, string);
	
	printf("Cambio: %s\n", cambio);
	
	printf("Ingrese un caracter de reemplazo: ");
	scanf(" %c", &reemplazo);
	
	printf("Ingrese un caracter de |%s| a reemplazar: ", string);
	scanf(" %c", &letra);
	
	for(i=0; i <= N; i++){
		if(string[i] == letra){
			cambio[i] = reemplazo; 
		}
	}
	
	comp= strcmp(string, cambio);
	
	if(comp == 0){
		printf("No se encontro el caracter |%c| en |%s|.", letra, string);
	}
	
	else{
		printf("\nPalabra |%s| reemplazada a ----> |%s|", string, cambio);	
	}	
	
	
	
}