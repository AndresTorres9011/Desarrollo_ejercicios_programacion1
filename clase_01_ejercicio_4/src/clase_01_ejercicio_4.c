/*
 ============================================================================
 Name        : clase_01_ejercicio_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 *Escribir un programa que realice las siguientes acciones:
    - Solicite al usuario 10 números
    - Calcule cuántos son negativos y cuantos son positivos
    - Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int respuestaScan;
	int contadorPositivos=0;
	int contadorNegativos=0;

	for(int i=0;i<10;i=i+1)
	{
		printf("\nIngrese Numero:");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero);
		while(respuestaScan==0)
		{
			printf("\nReingrese numero:");
			fflush(stdin);
			respuestaScan=scanf("%d",&numero);
		}
		if(numero>0)
		{
			contadorPositivos=contadorPositivos+1;
		}
		if(numero<0)
		{
			contadorNegativos=contadorNegativos+1;
		}
	}

	printf("\nLos numeros positivos ingresados son: %d", contadorPositivos);
	printf("\nLos numeros negativos ingresados son: %d", contadorNegativos);
}
