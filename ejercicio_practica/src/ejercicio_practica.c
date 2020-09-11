/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Programaci�n I � Laboratorio I - Trabajo Practico 1
1 Enunciado
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>

void utn_printMenuCalculadora(void);
int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);
float utn_sumaFloat(float operador1, float operador2, float* pResultado);
float utn_restaFloat(float operador1, float operador2, float *pResultado);
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado);
float utn_divisionFloat(float operador1, float operador2, float *pResultado);
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
float utn_getFactorial(float operador,float *pResultado);

int main(void) {
	setbuf(stdout,NULL);
	float numero1;
	float numero2;
	float resultado;
	int opcion;

	while(opcion!=6)
	{
		utn_printMenuCalculadora();

		if(utn_getInt("\nIngrese opcion: ","\nError, Reingrese opcion valida (1-6): ",&opcion,2,1,7)==0)
		{
		  if(opcion>0 && opcion<6)
		  {
			  if(utn_getFloat("Ingrese numero 1: ","\nError, Reingrese un numero: ",&numero1,2) == 0)
				{
					if(utn_getFloat("Ingrese numero 2: ","\nError, Reingrese un numero: ",&numero2,2) == 0)
					{
						switch(opcion)
						{
						  case 1:
							if(utn_sumaFloat(numero1,numero2,&resultado)==0)
							{
								printf("\nEl resultado de la suma es: %.2f", resultado);
							}
							else
							{
								printf("\nERROR");
							}
						   break;
						   case 2:
							if(utn_restaFloat(numero1,numero2,&resultado)==0)
							{
								printf("\nEl resultado de la resta es: %.2f", resultado);
							}
							else
							{
								printf("\nERROR");
							}
							break;
						   case 3:
							if(utn_multiplicacionFloat(numero1,numero2,&resultado)==0)
							{
								printf("\nEl resultado de la multiplicacion es: %.2f", resultado);
							}
							else
							{
								printf("\nERROR");
							}
							break;
							case 4:
							if(utn_divisionFloat(numero1,numero2,&resultado)==0)
							{
								printf("\nEl resultado de la division es: %.2f", resultado);
							}
							else
							{
								printf("\nNo se puede dividir por 0");
							}
							break;
							case 5:
							if(utn_getFactorial(numero1,&resultado)==0)
							{
								printf("\nEl factorial de %.2f es %.2f",numero1,resultado);
							}
							if(utn_getFactorial(numero2,&resultado)==0)
							{
								printf("\nEl factorial de %.2f es %.2f",numero2,resultado);
							}
							break;

						}
					}
				}
		   }
	  }
	}



	return EXIT_SUCCESS;
}

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
		printf("Se quedo sin intentos");
	}
	return retorno;
}

/**
 * \brief utn_sumaFloat : Suma dos numeros decimales.
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
 * \brief utn_restaFloat : Resta dos numeros decimales.
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
 * \brief utn_multiplicacionFloat : Multiplica dos numeros decimales.
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
 * \brief utn_divisionFloat : Divide dos numeros decimales.
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
/**
 * \brief utn_getNumero : Pide al usuario un numero entero.
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param reintentos: Cantidad de veces que se le volver� a pedir al usuario que ingrese un dato en caso de error.
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido ( no inclusive)
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	int numero;
	int respuestaScanF;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
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
/*
 * \brief utn_getFactorial : devuelve el factorial de un numero float.
 * \param operador: variable a calcularle su factorial.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor del factorial.
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo
 */

float utn_getFactorial(float operador,float *pResultado)
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

/*
 * \brief utn_printMenuCalculadora : Imprime en pantalla el menu de una calculadora.
  * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo
 */

void utn_printMenuCalculadora(void)
{
	printf( "\n   >>> MENU CALCULADORA <<<" );
	printf( "\n\n   1. Sumar dos n�meros.");
	printf( "\n   2. Restar dos n�meros.");
	printf( "\n   3. Multiplicar dos n�meros.");
	printf( "\n   4. Dividir dos n�meros.");
	printf( "\n   5. Factorial.");
	printf( "\n   6. Salir.\n");

}
