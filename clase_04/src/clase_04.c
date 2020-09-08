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

	if(utn_getNumero(&edad,"Ingrese edad:","Error Reingrese edad (1-120)",1,120,3)==0)
	{
		printf("Ingresaste:%d",edad);
	}

	if(utn_getCaracter(&letra,"Ingrese letra:","Error Reingrese letra (A-J)",'A','J',3)==0)
		{
			printf("Ingresaste:%c",letra);
		}


	return EXIT_SUCCESS;
}

