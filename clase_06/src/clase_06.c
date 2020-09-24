/*
 ============================================================================
 Name        : clase_06.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int utn_imprimirArrayLetras(char pArray[]);

int main(void) {
	setbuf(stdout,NULL);

	char texto[8];//CADENAS DE CARACTERES ARRAY DE CHARS

	texto[0]='F';
	texto[1]='l';
	texto[2]='a';
	texto[3]='c';
	texto[4]='o';
	texto[5]='\0';//caracter terminador de string.

	//utn_imprimirArrayLetras(texto);
	printf("%s",texto);

	texto[0]='H';
	texto[1]='A';
	texto[2]='!';
	texto[3]='\0';
	//utn_imprimirArrayLetras(texto);
	printf("%s",texto);
	return EXIT_SUCCESS;
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
