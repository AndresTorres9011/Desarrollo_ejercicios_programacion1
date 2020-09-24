/*
 ============================================================================
 Name        : clase_08_ejercicio.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1) Se tiene el siguiente array de variables del tipo int

int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};

Hacer una funcion que reciba el array y su tamaño, y lo imprima.
Escribir un programa para probar la funcion.
2) Hacer una funcion que reciba el array del punto 1 y su tamaño,
y cuente cuantas veces aparece el numero 7.
Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.
5) Hacer una funcion que reciba el array del punto 4, y verifique que las letras
dentro del mismo esten en el rango de 'a' a 'z' o de 'A' a 'Z'.
Si estan dentro del rango la funcion deberá devolver por valor(usando el return) un 0, de lo contrario devolverá -1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_ELEMENTOS 12



int main(void) {
	setbuf(stdout,NULL);
	int numeros[CANTIDAD_ELEMENTOS]={3,7,4,5,2,3,7,1,7,3,2,7};
	int contadoNumeroRepetido;
	//char nombre[8]={'p','e','p','e','1','2','3','\0'};
	char nombre[8]={'p','e','p','e','l','o','k','\0'};
	int cantidadLetraRepetida;
	utn_imprimirArrayNumeros(numeros,CANTIDAD_ELEMENTOS);
	if(utn_contadorArrayNumeroRepetido(numeros,CANTIDAD_ELEMENTOS,3,&contadoNumeroRepetido)==0)
	{
		printf("\nhay %d tres \n",contadoNumeroRepetido);
	}
	utn_imprimirArrayLetras(nombre);
	if(utn_contadorArrayLetraRepetido(nombre,8,'e',&cantidadLetraRepetida)==0)
	{
		printf("\nhay %d e ",cantidadLetraRepetida);
	}
	if(utn_validarArrayLetras(nombre,8)==0)
	{
		printf("\nLetras ingresadas: %s ",nombre);
	}
	else
	{
		printf("\nNo esta dentro del rango");
	}

	return EXIT_SUCCESS;
}
