/*
 * utn.c
 *
 *  Created on: 8/09/2020
 *      Author: Torres Andres
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief utn_getNumero : Pide al usuario un numero
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido (no inclusive)
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int numero;
	int respuestaScanF;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			respuestaScanF=scanf("%d",&numero);
			if((respuestaScanF==1) && numero>=minimo && numero<maximo)
			{
				*pResultado = numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}
		if(reintentos==0)
			{
				printf("Se quedo sin intentos");
			}
	}


	return retorno;
}

/**
 * \brief utn_getCaracter : Pide al usuario una letra
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje: El mensaje que imprime para pedir una letra
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido (no inclusive)
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
char utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char letra;
	int respuestaScanF;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("\n%s",mensaje);
			fflush(stdin);
			respuestaScanF=scanf("%c",&letra);
			if((respuestaScanF==1) && letra>=minimo && letra<maximo)
			{
				*pResultado = letra;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}
		if(reintentos==0)
			{
				printf("Se quedo sin intentos");
			}
	}


	return retorno;
}
