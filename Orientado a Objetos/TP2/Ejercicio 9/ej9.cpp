#include <stdio.h>
#include <string.h>
#include <ctype.h>
char string[100], oracion[100], opc;
int i, N, alternar=0, boolInic=0;


main(){
	printf("Ingrese oracion: ");
	fgets(oracion, sizeof(oracion), stdin);
	strcmp(oracion, string);
	
	N = strlen(oracion);
	
	printf("\nOpcion A. mostrar toda la oracion en mayuscula.\nOpcion B. Mostrar la oracion todo en minusculas.\nOpcion C. Mostrar la oracion alternando una mayuscula y una minuscula.\nOpcion D. Mostrar la oracion comenzando con todas las palabras en mayuscula.\n\nIngrese opcion: ");
	scanf("%c", &opc);
	
	opc = tolower(opc);
	
	switch(opc){
		case 'a':
				for(i=0; i < N; i++){
					oracion[i] = toupper(oracion[i]);
				}
		break;
		
	
		
		case 'b':
				for(i=0; i < N; i++){
					oracion[i] = tolower(oracion[i]);
				}
		break;
		
		
		
		case 'c':
				for(i = 0; i < N; i++) {
        			if((oracion[i] >= 'A' && oracion[i] <= 'Z') || (oracion[i] >= 'a' && oracion[i] <= 'z')){
            			
						if(alternar % 2 == 0){
                			oracion[i] = toupper(oracion[i]);
            			}
						 			
						else{
                			oracion[i] = tolower(oracion[i]);
            			}
            			
            			alternar++;
        			}
   				}	
			
		break;
		
		case 'd':
				for(i=0; i < N; i++){
					if(boolInic == 0 && (oracion[i] != ' ' || oracion[i] != '\0')){
						boolInic = 1;
					 	oracion[i] = toupper(oracion[i]);
					}
					else if(oracion[i] == ' '){
						boolInic = 0;
					}
					
				}
				
		
		break;
		
		default: printf("Opcion no encontrada.");
		
		break;
	}
	
	printf("\nLa oracion es igual a: %s", oracion);

	

	
		
	
	
	
}