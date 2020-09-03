/*
 ============================================================================
 Name        : clase_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Pedir 2 floats y realizar:
1 - sumar
2 - restar
3 - multiplicar
4 - dividir
si salieron bien  --> return 0
caso contrario 	--> return -1
 */

#include <stdio.h>
#include <stdlib.h>

float sumaEnteros(int operador1, int operador2, float *pResultado);
float restaEnteros(int operador1, int operador2, float *pResultado);
float multiplicacionEnteros(int operador1, int operador2, float *pResultado);
float divisionEnteros(int operador1, int operador2, float *pResultado);

int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int respuestaScan;
	float resultado;

	printf("Ingrese numero 1:\n");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero1);
		while(respuestaScan==0)
		{
			printf("Reingrese numero 1:\n");
			fflush(stdin);
			respuestaScan=scanf("%d",&numero1);
		}
		printf("Ingrese numero 2:\n");
		fflush(stdin);
		respuestaScan=scanf("%d",&numero2);
		while(respuestaScan==0)
		{
			printf("Reingrese numero 2:\n");
			fflush(stdin);
			respuestaScan=scanf("%d",&numero2);
		}

		sumaEnteros(numero1,numero2,&resultado);
		printf("\nEl resultado de la suma es:%.2f", resultado);
		restaEnteros(numero1,numero2,&resultado);
		printf("\nEl resultado de la resta es:%.2f", resultado);
		multiplicacionEnteros(numero1,numero2,&resultado);
		printf("\nEl resultado de la multiplicacion es:%.2f", resultado);
		if(divisionEnteros(numero1,numero2,&resultado)==0)
		{
			printf("\nEl resultado de la division es: %.2f", resultado);
		}
		else
		{
			printf("\nNo se puede dividir por 0");
		}

		return EXIT_SUCCESS;
}

float sumaEnteros(int operador1, int operador2, float *pResultado)
{

	*pResultado= (float)operador1+operador2;
	return 0;
}

float restaEnteros(int operador1, int operador2, float *pResultado)
{

	*pResultado= (float)operador1-operador2;
	return 0;
}
float multiplicacionEnteros(int operador1, int operador2, float *pResultado)
{

	*pResultado= (float)operador1*operador2;
	return 0;
}
float divisionEnteros(int operador1, int operador2, float *pResultado)
{
	int retorno;
	if(operador2!= 0)
	{
		*pResultado = (float)operador1 / operador2;
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;

}
