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
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	int edad;
	char letra;

	if(utn_getNumero("Ingrese edad:","Error Reingrese edad (1-120)",&edad,3,1,120)==0)
	{
		printf("Ingresaste:%d",edad);
	}

	if(utn_getCaracter("Ingrese letra:","Error Reingrese letra (A-J)",&letra,3,'A','J')==0)
		{
			printf("Ingresaste:%c",letra);
		}


	return EXIT_SUCCESS;
}

