/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int myGets(char *cadena, int len);

/**
 * \brief utn_getFloat : Pide al usuario un numero.
 * \param mensaje: El mensaje que imprime para pedir un numero.
 * \param mensajeError: mensaje que imprime si no ingreso un numero.
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario.
 * \param reintentos: Cantidad de veces que se le volver� a pedir al usuario que ingrese un dato en caso de error.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos)
{
	int retorno = -1;
	int respuestaScan;
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	respuestaScan = scanf("%f",&bufferFloat);
	while (respuestaScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		respuestaScan = scanf("%f",&bufferFloat);

	}
	if(respuestaScan != 0)
	{ //TODO OK
		*pResultado = bufferFloat;
		retorno = 0;
	}

	if(reintentos==0)
	{
		printf("   Se quedo sin intentos\n");
		retorno = -1;
		system("PAUSE");
	}
	return retorno;
}

/**
 * \brief utn_sumaFloat : Suma dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la suma de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

float utn_sumaFloat(float operador1, float operador2, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado= operador1+operador2;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_restaFloat : Resta dos numeros..
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la resta de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
float utn_restaFloat(float operador1, float operador2, float *pResultado)
{
	int retorno=-1;

	if (pResultado != NULL)
	{
		*pResultado= operador1-operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief utn_multiplicacionFloat : Multiplica dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la multiplicacion de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado)
{
	int retorno=-1;

	if (pResultado != NULL)
	{
		*pResultado= operador1*operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief utn_divisionFloat : Divide dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la multiplicacion de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error (No se puede dividir por 0)
 */
float utn_divisionFloat(float operador1, float operador2, float *pResultado)
{
	int retorno = -1;

	if(pResultado!= NULL && operador2!= 0)
	{
		*pResultado = operador1 / operador2;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_factorial : devuelve el factorial de un numero float.
 * \param operador: variable a calcularle su factorial.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor del factorial.
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo.
 */
float utn_factorial(float operador,float *pResultado)
{
	int retorno = -1;
	int i;
	int factorial = 1;

	if(pResultado != NULL )
	{
		if(operador == 0)
		{
			*pResultado = 1;
			retorno = 0;
		}
		if(operador > 0)
		{
			for (i = 1;i <= operador;i++)
			{
				factorial = (float)factorial * i;
			}
			*pResultado = factorial;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief utn_getNumero : Pide al usuario un numero
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param reintentos: Cantidad de veces que se le volver� a pedir al usuario que ingrese un dato en caso de error.
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido ( no inclusive)
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumero(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo)
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
				printf("   Se quedo sin intentos");
				retorno=-1;
				system("\nPAUSE");
			}
	}
	return retorno;
}
/**
 * \brief utn_getCaracter : Pide al usuario una letra
 * \param mensaje: El mensaje que imprime para pedir una letra
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param reintentos: Cantidad de veces que se le volver� a pedir al usuario que ingrese un dato en caso de error.
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido (no inclusive)
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
char utn_getCaracter(char* mensaje, char* mensajeError,char* pResultado, int reintentos, char minimo, char maximo)
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

/*
 * \brief utn_printMenuCalculadora : Imprime en pantalla el menu de una calculadora.
 */
void utn_printMenuCalculadora(void)
{
	printf( "\n\n   >>> MENU CALCULADORA <<<" );
	printf( "\n\n   1. Ingresar 1er operando.");
	printf( "\n   2. Ingresar 2do operando.");
	printf( "\n   3. Calcular todas las operaciones.");
	printf( "\n   4. Informar resultados.");
	printf( "\n   5. Salir.\n");
}
/**
 * \brief utn_calcularMaximoArray: Calcula el numero maximo del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_calcularMaximoArray(int pArray[], int len,int *pResultado)
{
	int retorno=-1;
	int maximo;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		for(int i=0; i < len; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_calcularMinimoArray: Calcula el numero minimo del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesador.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_calcularMinimoArray(int pArray[], int len,int *pResultado)
{
	int retorno=-1;
	int minimo;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		for(int i=0; i < len; i++)
		{
			if(i==0 || pArray[i] < minimo)
			{
				minimo = pArray[i];
			}
		}
		*pResultado = minimo;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_calculoPromedioArray: Calcula el promedio del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 *
 */
int utn_calculoPromedioArray(int pArray[], int len, float *pResultado)
{
	int retorno=-1;
	int acumulador=0;
	float promedio;

	if(pArray!=NULL && pResultado!=NULL && len>0)
	{
		for( int i=0; i < len ; i++)
		{
			acumulador= acumulador + pArray[i];
		}
		promedio=(float)acumulador/len;
		*pResultado=promedio;
		retorno=0;
	}
	return retorno;
}
/**
 * \brief utn_ordenarArrayEnteros:Ordena el array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 *
 */
int utn_ordenarArrayEnteros(int pArray[], int len)
{
	int retorno=-1;
	int swap;
    int flagEstadoDesordenado=1;

    if(pArray!=NULL && len>0)
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if(pArray[i] > pArray[i+1])
				{
					// intercambiar (swap)
					swap = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = swap;
					flagEstadoDesordenado=1;
				}
			}
		}
    	retorno=0;
    }
	return retorno;
}
/**
 * \brief utn_imprimirArrayNumeros: Imprime el array numerico recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: Cantidad de elementos a ser procesados.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_imprimirArrayNumeros(int pArray[], int len)
{
	int retorno=-1;

	if(pArray!=NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			printf("%d ",pArray[i]);
		}
		retorno=0;
	}
	return retorno;
}
/**
 * \brief utn_contadorArrayNumeroRepetido: Cuenta un numero repetido en el array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: Cantidad de elementos a ser procesados.
 * \param int numero: Numero recibido para ser comparado dentro del array.
 * \param int *pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_contadorArrayNumeroRepetido(int pArray[], int len, int numero, int *pResultado)
{
	int retorno=-1;
	int contadorNumeroRepetido=0;

	if(pArray!=NULL && len>0 && pResultado!=NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(pArray[i]==numero)
			{
				contadorNumeroRepetido++;
				//*pResultado=contadorNumeroRepetido;
			}
		}
		*pResultado=contadorNumeroRepetido;
		retorno=0;
	}

	return retorno;
}
/**
 * \brief utn_contadorArrayLetraRepetido: Cuenta una letra repetida en el array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: Cantidad de elementos a ser procesados.
 * \param int numero: Letra recibida para ser comparada dentro del array.
 * \param int *pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_contadorArrayLetraRepetido(char pArray[], int len,char letra, int *pResultado)
{
	int retorno=-1;
	int contadorLetraRepetida=0;

	if(pArray!=NULL && len>0 && pResultado!=NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(pArray[i]==letra)
			{
				contadorLetraRepetida++;
				//*pResultado=contadorNumeroRepetido;
			}
		}
		*pResultado=contadorLetraRepetida;
		retorno=0;
	}
	return retorno;
}
/**
 * \brief utn_imprimirArrayLetras: Imprime el array de letras recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_imprimirArrayLetras(char pArray[])
{
	int retorno=-1;
	int i=0;

	if(pArray!=NULL)
	{
		while(pArray[i] != '\0')
		{
			printf("%c ",pArray[i]);
			i++;
		}
		retorno=0;
	}
	return retorno;
}
/**
 * \brief utn_validarArrayLetras: Verifica una cadena recibida como parametro para determinar si son letras validas.
 * \param char* cadena: Cadena a analizar
 * \param int limite: Indica la cantidad de letras maxima de la cadena.
 * \return (-1) Indicar que no es un nombre valido / (0) Indica que que es un nombre valido
 */
int utn_validarArrayLetras(char* cadena,int limite)
{
	int retorno = 0;

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}
/**
 * \brief 	Verifica una cadena recibida como parametro para determinir
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int utn_esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1; // TODO OK

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') )
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				utn_esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
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

static int myGets(char *cadena, int len)
{
	fflush(stdin);
	fgets (cadena, len, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}
