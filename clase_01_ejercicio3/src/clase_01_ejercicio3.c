/*
 ============================================================================
 Name        : clase_01_ejercicio3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 *  - Limpie la pantalla
    - Solicite dos valores numéricos al usuario distintos de cero *
    - Asigne a las variables numero1 y numero2 los valores obtenidos
    - Realice la resta de dichas variables
    - Muestre el resultado por pantalla
    - Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
    - Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int respuestaScan;
	int resta;

	printf("Ingrese numero 1:");
	fflush(stdin);
	respuestaScan=scanf("%d",&numero1);
	while(respuestaScan==0)
	{
		printf("Reingrese numero 1:");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero1);
	}
	printf("Ingrese numero 2:");
	fflush(stdin);
	respuestaScan=scanf("%d",&numero2);
	while(respuestaScan==0)
	{
		printf("Reingrese numero 2:");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero2);
	}
	resta=numero1-numero2;
	printf("La resta es: %d", resta);
	if(resta>0)
	{
		printf("\nResultado positivo");
	}
	if(resta<0)
	{
		printf("\nResultado negativo");
	}


}
