#include <stdio.h>
char nombre[24], apellido[24];
int dia_nac, mes_nac, anio_nac, edad, DNI;
const int dia_elec= 30, mes_elec= 9, anio_elec= 2025;
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
	
	edad = anio_elec - anio_nac;
	
	if((edad >= 16) && (mes_nac <= mes_elec) && (dia_nac <= dia_elec)){
		
		printf("\n\n%s %s con DNI: %d.\nEsta empadronado para votar. ", nombre, apellido, DNI);
		
	}
		else{
			printf("\n\n%s %s con DNI: %d.\nNo cumple los requisitos para votar.", nombre, apellido, DNI);	
		}
}
	
