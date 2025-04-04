#include <stdio.h>
#include <string.h>
#include <ctype.h>
char string[100], alrevez[20][100];
int i, N, contPalabras=0, contLetras= 0;

main(){
    printf("Ingrese una string para darla vuelta: ");
	scanf(" %[^\n]s", string);
    N = strlen(string);

    for (i = 0; i < N; i++) {
        if(string[i] == ' ' && string[i + 1] != ' ' && string[i + 2] != '\0'){
            if(contLetras > 0) {  
                contPalabras++;  
            }
            contLetras = 0;
        }
		 
		else{
            alrevez[contPalabras][contLetras] = string[i];  
            contLetras++;
        }
    
	}
	
	if(contLetras > 0){
		contPalabras++;
	}

    

    printf("\nCantidad de palabras: %d\n", contPalabras);

    for(i = (contPalabras - 1); i >= 0; i--){
        printf("%s", alrevez[i]);
        printf(" ");
    }

}