/*
 ============================================================================
 Name        : clase_04.c
 Author      : Torres Andres
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, int minimo, int maximo, char* mensaje, char* mensajeError, int reintentos);

int main(void) {
	/*
	char* variable = "Ingresame algo che:";
	printf("%s",variable);
	return 0;
	*/
	setbuf(stdout,NULL);


	int edad;


	if(utn_getNumero(&edad,1,120,"Ingresame edad:","NAHHHHHH",3)==0)
	{
		printf("ingresaste:%d",edad);
	}



	return EXIT_SUCCESS;
}

/*
int​ utn_getNumero(​int​* pResultado, char​* mensaje,
					char​* mensajeError,
					int​ minimo,
					int​ maximo,
					int​ reintentos)
{
*/



/**
 * \brief utn_getNumero : Pide al usuario un numero
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param min: valor minimo valido (inclusive)
 * \param max: valor maximo valido (no inclusive)
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: mensaje que imprime si el rango no es valido
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumero(int* pResultado, int minimo, int maximo, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	int numero;
	int retornoScanf;

	while(reintentos > 0)
	{
		printf("%s\n", mensaje);
		//__fpurge(stdin); // linussss
		fflush(stdin); // windorrrr

		retornoScanf = scanf("%d", &numero);

		if(retornoScanf==1 && numero>=minimo && numero<maximo)
		{
			//escribir "numero" en la dire que tiene pResultado
			*pResultado = numero;
			retorno = 0;
			break;
		}
		else
		{
			printf("%s\n", mensajeError);
			reintentos--;
		}
	}
	if(reintentos == 0)
	{
		printf("Se quedo sin intentos");
	}
	return retorno;
}
