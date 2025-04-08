#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[30], str1[30], str2[30], str3[30], str4[30];
char sub[30], mayor[30];
int i, j, k, longi, max=0;

main(){
    printf("Ingrese la primer palabra: ");
    fgets(str, sizeof(str), stdin);
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }

    printf("Ingrese la segunda palabra: ");
    fgets(str1, sizeof(str1), stdin);
    if(str1[strlen(str1) - 1] == '\n'){
        str1[strlen(str1) - 1] = '\0';
    }

    printf("Ingrese la tercer palabra: ");
    fgets(str2, sizeof(str2), stdin);
    if(str2[strlen(str2) - 1] == '\n'){
        str2[strlen(str2) - 1] = '\0';
    }

    printf("Ingrese la cuarta palabra: ");
    fgets(str3, sizeof(str3), stdin);
    if(str3[strlen(str3) - 1] == '\n'){
        str3[strlen(str3) - 1] = '\0';
    }

    printf("Ingrese la quinta palabra: ");
    fgets(str4, sizeof(str4), stdin);
    if(str4[strlen(str4) - 1] == '\n'){
        str4[strlen(str4) - 1] = '\0';
    }

    longi = strlen(str);

    for(i=0; i < longi; i++){
        k = 0;
        for(j=i; j < longi; j++){
            sub[k] = str[j];
            k++;
            sub[k] = '\0';
            
            if(strstr(str1, sub) != NULL &&
               strstr(str2, sub) != NULL &&
               strstr(str3, sub) != NULL &&
               strstr(str4, sub) != NULL
			   ){
			   	
                if(strlen(sub) > max){
                    max = strlen(sub);
                    strcpy(mayor, sub);
                }
                
            }
        }
    }

    printf("\n\nLa subcadena mas larga repetida es: %s\n", mayor);
}
