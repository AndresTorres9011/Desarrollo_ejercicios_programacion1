/*
 ============================================================================
 Name        : clase_12.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"

#define QTY_SCREEN 5
#define CANTIDAD_REINTENTOS 3
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int opcion;

    Pantalla arrayPantallas[QTY_SCREEN];

	if(pantalla_init(arrayPantallas,QTY_SCREEN)==0)
	{
		do
		{
			if(utn_getNumeroString("\n\n  1-Alta Pantalla\n  2-Modificar Pantalla\n  3-Baja Pantalla "
				                   "\n  4-Alta Contratacion\n  5-Modificar contratacion\n  6-Baja Contratacion\n  "
				             "7-Consultar Facturacion\n  8-Listar Contrataciones\n  9-Listar Pantallas\n  10-Informar  Ingrese opción:   ",
							 "ERROR Reingrese opcion valida",&opcion,CANTIDAD_REINTENTOS,1,10)==0)
			{
				switch(opcion)
				{
					case 1://Alta Pantalla
						   if(pantalla_createNew(arrayPantallas,QTY_SCREEN)==0)
						   {
							   printf("\n  ALTA EXITOSA\n");
						   }
						   else
						   {
							   printf("\n  NO SE REALIZO ALTA \n");
						   }
						break;
					case 2://Modificar Pantalla
						//pantalla_modifify(arrayPantallas,QTY_SCREEN)
						if(pantalla_modifify(arrayPantallas,QTY_SCREEN)==0)
						{
							printf("\n  MODIFICACION EXITOSA\n");
						}
						else
						{
							printf("\n  MODIFICACION INCORECTA\n");
						}
					break;
					case 3://Baja Pantalla
					    if(pantalla_remove(arrayPantallas,QTY_SCREEN)==0)
					    {
							 printf("\n  BAJA EXITOSA\n");
						}
						else
						{
							printf("\n  BAJA INCORECTA\n");
						}
					break;
					case 4://Alta Contratacion
					break;
					case 5://Modificar contratacion
					break;
					case 6://Baja Contratacion
					break;
					case 7://Consultar Facturacion
					break;
					case 8://Listar Contrataciones
					break;
					case 9://Listar Pantallas
						 pantalla_print(arrayPantallas,QTY_SCREEN);
					break;
					case 10://Informar
					break;
				}
			}
		}while(opcion!=6);
	}
	return EXIT_SUCCESS;
}
