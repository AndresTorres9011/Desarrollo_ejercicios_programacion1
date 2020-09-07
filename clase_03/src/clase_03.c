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

float sumaEnteros(float operador1, float operador2, float *pResultado);
float restaEnteros(float operador1, float operador2, float *pResultado);
float multiplicacionEnteros(float operador1, float operador2, float *pResultado);
float divisionEnteros(float operador1, float operador2, float *pResultado);
int getFloat(char *mensaje,char *mensajeError,int reintentos,float *pResultado);

int main(void) {
	setbuf(stdout,NULL);
	float numero1;
	float numero2;
	//int respuestaScan;
	float resultado;

	/*printf("Ingrese numero 1:\n");
		fflush(stdin);
		respuestaScan=scanf("%f",&numero1);
		while(respuestaScan==0)
		{
			printf("Reingrese numero 1:\n");
			fflush(stdin);
			respuestaScan=scanf("%f",&numero1);
		}
		printf("Ingrese numero 2:\n");
		fflush(stdin);
		respuestaScan=scanf("%f",&numero2);
		while(respuestaScan==0)
		{
			printf("Reingrese numero 2:\n");
			fflush(stdin);
			respuestaScan=scanf("%f",&numero2);
		}
		*/
	if(getFloat("\nIngrese numero 1: ","\nError, Reingrese un numero: ",2,&numero1) == 0)
	{
		 if(getFloat("\nIngrese numero 2: ","\nError, Reingrese un numero: ",2,&numero2) == 0)
		 {

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
		  }
	 }

		return EXIT_SUCCESS;
}

float sumaEnteros(float operador1, float operador2, float *pResultado)
{

	*pResultado= operador1+operador2;
	return 0;
}

float restaEnteros(float operador1, float operador2, float *pResultado)
{

	*pResultado= operador1-operador2;
	return 0;
}
float multiplicacionEnteros(float operador1, float operador2, float *pResultado)
{

	*pResultado= operador1*operador2;
	return 0;
}
float divisionEnteros(float operador1, float operador2, float *pResultado)
{
	int retorno = -1;
	if(pResultado!= NULL && operador2!= 0)
	{
		*pResultado = operador1 / operador2;
		retorno = 0;
	}

	return retorno;

}
int getFloat(char *mensaje,char *mensajeError,int reintentos,float *pResultado)
{
	int retorno = -1;
	int respuestaScan;
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	respuestaScan = scanf("%f", &bufferFloat);
	while (respuestaScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		respuestaScan = scanf("%f", &bufferFloat);
	}
	if(respuestaScan != 0)
	{ //TODO OK
		*pResultado = bufferFloat;
		retorno = 0;
	}
	return retorno;
}
