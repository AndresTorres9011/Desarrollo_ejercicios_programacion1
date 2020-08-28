/*
 ============================================================================
 Name        : clase_01_promedio.c
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
	int numero;
	int respuestaScan;
	int acumulador=0;
	float promedio;
	int i;

	for(i=0;i<5;i=i+1)
	{
		printf("Ingrese numero");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero);
		while(respuestaScan==0)
		{
			printf("Reingrese numero");
			fflush(stdin);
			respuestaScan=scanf("%d",&numero);
		}
		acumulador=acumulador+numero;
	}
	promedio=(float)acumulador/i;
	printf("\nEl promedio es: %.2f", promedio);
}
