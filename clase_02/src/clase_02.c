/*
 ============================================================================
 Name        : clase_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Solicitar al usuario que ingrese una serie de n�meros la cual finaliza al introducir el 999
 * (el 999 no debe ser tenido en cuenta para dicho c�lculo). Una vez finalizado el ingreso de n�meros el programa
 * deber� mostrar el promedio de dichos n�meros por pantalla.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int acumulador=0;
	int numero;
	int contador=0;
	float promedio;

	while(1)
	{
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%d",&numero);
		if(numero!=999)
		{
			acumulador=acumulador+numero;
			contador= contador+1;
		}
		else
		{
			break;
		}
	}
	promedio = (float)acumulador/contador;
	printf("\nEl promedio es : %.2f",promedio);
	return EXIT_SUCCESS;
}
