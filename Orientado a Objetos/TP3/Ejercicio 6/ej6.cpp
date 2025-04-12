#include <stdio.h>
#include <string.h>

char string[100];

void contarOcurrencias(char *ptr);
int repetido(char *array, char letra, int N);

int main(){
    printf("Ingrese una string: ");
    fgets(string, sizeof(string), stdin);
    if(string[strlen(string) - 1] == '\n'){
        string[strlen(string) - 1] = '\0';
    }

    contarOcurrencias(&string[0]);

    return 0;
}

void contarOcurrencias(char *ptr){
	int k=0;
	int longi = strlen(ptr);
	char contado[longi];
	
	for(int i=0; i < longi; i++){
		
		if(repetido(contado, ptr[i], k) == 0){
		 	int cont = 1;
		
			for(int j= i+1; j < longi; j++){
		 	 	if(ptr[i] == ptr[j]){
		 	 		cont++;
				}
		 	}
		
			contado[k] = ptr[i];
			k++;
		
			printf("\nEl elemento |%c| aparece %d.\n", ptr[i], cont);
		}
	}
	
}

int repetido(char *array, char letra, int N){
	for(int i=0; i < N; i++){
		if(array[i] == letra){
			return 1;
		}
	}
	
	return 0;
}