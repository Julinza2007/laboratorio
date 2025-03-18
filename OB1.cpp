#include <stdio.h>
char nombre[12], apellido[12];
int dia_nac, mes_nac, anio_nac, DNI, dia_elec= 30, mes_elec= 9, anio_elec= 2025;

main(){
	
	printf("Ingrese el nombre: ");
	scanf("%s", &nombre);
	printf("Ingrese el apellido: ");
	scanf("%s", &apellido);
	printf("Ingrese el DNI: ");
	scanf("%d", &DNI);
	printf("Ingrese el dia de nacimiento: ");
	scanf("%d", &dia_nac);
	printf("Ingrese el mes de nacimiento: ");
	scanf("%d", &mes_nac);
	printf("Ingrese el anio de nacimiento: ");
	scanf("%d", &anio_nac);
	
	if(((anio_elec - anio_nac) >= 16) && (mes_nac <= mes_elec) && (dia_nac <= dia_elec)){
		printf("\n\n%s %s con DNI: %d.\nEsta empadronado para votar. ", nombre, apellido, DNI);
		if(((anio_elec - anio_nac) >= 16 && (anio_elec - anio_nac) < 18) || (anio_elec - anio_nac) >= 80 ){
			printf("\nUsted esta en el rango opcional. Desea votar, ingrese 1. Si no, ingrese 0.\n");
		}
	}
		else{
			printf("\n\n%s %s con DNI: %d.\nNo esta empadronado para votar.", nombre, apellido, DNI);	
		}
}
	
