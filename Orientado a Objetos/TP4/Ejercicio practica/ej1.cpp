#include <stdio.h>


int main(){
	FILE *archivo;
	
	archivo = fopen("mensaje.txt", "r");
	if(archivo == NULL){
		printf("Error al abrir el archivo\n");
		return 1;
	}
	
char linea[100];

for(int i=1; fgets(linea, sizeof(linea), archivo) != NULL; i++){
	printf("Linea %d: %s", i, linea);
}

fclose(archivo);
return 0;

// int linea_deseada = 4;
//



//    for (int i = 1; i <= linea_deseada; i++) {
//        if (fgets(linea, sizeof(linea), archivo) == NULL) {
//            printf("No existe la línea %d\n", linea_deseada);
//            fclose(archivo);
//            return 1;
//        }
//    }

//    printf("Linea %d: %s", linea_deseada, linea);



    
}