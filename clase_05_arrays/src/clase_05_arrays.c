/*
 ============================================================================
 Name        : clase_05_arrays.c
 Author      : Torres Andres
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Pedir 5 numeros
 - OP1 - Calcular Maximo
 - OP2 - Calcular Promedio
 - OP3 - Calcular Minimo
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

#define CANTIDAD_ELEMENTOS 4

int main(void) {
	setbuf(stdout,NULL);
	int variableInt;
	char aMensaje[200];
	int arrayInt[CANTIDAD_ELEMENTOS];
	int flagCargaCorrecta = 0;
	int numeroMaximo;
	int numeroMinimo;
	//int swap;
	//int flagEstadoDesordenado=1;
	int i;
	//int acumulador=0;
	float promedio;

	for( i=0; i < CANTIDAD_ELEMENTOS ; i++)
	{
		sprintf(aMensaje,"\nNumero %d: ",i+1);
		//if(getInt("Ingrese numero","Fuera de rango [0-1000]\n",&variableInt,3,0,1000)!=0)
		if(getInt(aMensaje,"Fuera de rango [0-1000]\n",&variableInt,3,0,1000) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;

		}
	}

	/*if(flagCargaCorrecta == 0)
	{
		for(int i=0; i < CANTIDAD_ELEMENTOS ; i++)
		{
			if(i==0 || arrayInt[i] > numeroMaximo)
			{
				numeroMaximo=arrayInt[i];
			}
			if(i==0 || arrayInt[i]<numeroMinimo)
			{
				numeroMinimo=arrayInt[i];
			}
			acumulador= acumulador + arrayInt[i];
		}
		promedio=(float)acumulador/CANTIDAD_ELEMENTOS;
		printf("El numero maximo ingresado es: %d\nEl numero minimo ingresado es: %d\nEl promedio es: %.2f",numeroMaximo,numeroMinimo,promedio);
	}*/

	if(flagCargaCorrecta==0)
	{
		if(utn_calcularMaximoArray(arrayInt,CANTIDAD_ELEMENTOS,&numeroMaximo)==0)
		{
			printf("\nEl numero maximo es: %d",numeroMaximo);
		}
		else
		{
			printf("Error");
		}
		if(utn_calcularMinimoArray(arrayInt,CANTIDAD_ELEMENTOS,&numeroMinimo)==0)
		{
			printf("\nEl numero minimo es: %d",numeroMinimo);
		}
		else
		{
			printf("Error");
		}
		if(utn_calculoPromedioArray(arrayInt,CANTIDAD_ELEMENTOS,&promedio)==0)
		{
			printf("\nEl promedio es: %.2f",promedio);
		}

		 printf("\nArray Desordenado: ");
		for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
		{
			printf("%d ",arrayInt[i]);
		}

		printf("\nArray Ordenado:");
		if(utn_ordenarArrayEnteros(arrayInt,CANTIDAD_ELEMENTOS)==0)
		{
			for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
			{
				printf("%d ",arrayInt[i]);
			}
		}
	}



		/*while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( i=0 ; i<(CANTIDAD_ELEMENTOS-1)  ; i++)
			{
				if(arrayInt[i] > arrayInt[i+1])
				{
					// intercambiar (swap)
					swap = arrayInt[i];
					arrayInt[i] = arrayInt[i+1];
					arrayInt[i+1] = swap;
					flagEstadoDesordenado=1;
				}
			}
		}*/

		/*if(utn_ordenarArrayEnteros(arrayInt,CANTIDAD_ELEMENTOS)==0)
		{
			for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
			{
				printf("%d ",arrayInt[i]);
			}
		*/
	return EXIT_SUCCESS;
}




/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush (stdin); // fflush // __fpurge
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

