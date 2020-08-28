/*
 ============================================================================
 Name        : clase_01_suma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int resultado;
	int resultadoScan;

	printf("Ingrese numero 1:");
	fflush(stdin);
	resultadoScan=scanf("%d",&numero1);
	while(resultadoScan==0)
	{
		printf("Reingrese numero 1:");
		fflush(stdin);
		resultadoScan=scanf("%d",&numero1);
	}
	printf("\nIngrese numero 2:");
		fflush(stdin);
		resultadoScan=scanf("%d",&numero2);
		while(resultadoScan==0)
		{
			printf("\nReingrese numero 2:");
			fflush(stdin);
			resultadoScan=scanf("%d",&numero2);
		}

	resultado=numero1+numero2;
	printf("\nEl resultado es %d", resultado);

}
