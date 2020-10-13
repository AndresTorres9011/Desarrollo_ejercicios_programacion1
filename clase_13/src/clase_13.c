/*
 ============================================================================
 Name        : clase_13.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contrataciones.h"
#include "utn.h"
#include "pantalla.h"
#include "informes.h"

#define QTY_SCREEN 15
#define QTY_CONTRATACIONES 15
#define CANTIDAD_REINTENTOS 3
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int opcion;

    Pantalla arrayPantallas[QTY_SCREEN];
    Contratacion arrayContratacion[QTY_CONTRATACIONES];

	if(pantalla_init(arrayPantallas,QTY_SCREEN)==0 && contratacion_init(arrayContratacion,QTY_CONTRATACIONES)==0)
	{
		pantalla_altaForzada(arrayPantallas,QTY_SCREEN,"Pantalla 1","Superi 1435",0,12000);
		pantalla_altaForzada(arrayPantallas,QTY_SCREEN,"Pantalla 2","Av elcano 3165",1,22000);
		pantalla_altaForzada(arrayPantallas,QTY_SCREEN,"Pantalla 3","Av cramer 2500",0,2000);
		pantalla_altaForzada(arrayPantallas,QTY_SCREEN,"Pantalla 4","Zapiola 879",1,1000);
		pantalla_altaForzada(arrayPantallas,QTY_SCREEN,"Pantalla 5","Conde 450",0,6000);

		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,1,"pepito",25,"209472881");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,3,"mov",30,"309445896");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,2,"avi",15,"209472881");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,3,"jpg",10,"409572983");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,5,"docx",6,"209472881");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,2,"pep",25,"209472881");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,4,"ovi",3,"309445896");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,2,"res",1,"209666681");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,1,"qwerty",4,"409572983");
		contratacion_altaForzada(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN,5,"tyui",9,"209666681");

		do
		{
			if(utn_getNumeroString("\n\n  1-Alta Pantalla\n  2-Modificar Pantalla\n  3-Baja Pantalla "
				                   "\n  4-Alta Contratacion\n  5-Modificar contratacion\n  6-Baja Contratacion\n  "
				             "7-Consultar Facturacion\n  8-Listar Contrataciones\n  9-Listar Pantallas\n  10-Informar  \n  11-Salir  \n  Ingrese opción:   ",
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
						if(contratacion_createNew(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN)==0)
						{
							   printf("\n  ALTA EXITOSA\n");
						}
					    else
						{
				        	   printf("\n  NO SE REALIZO ALTA \n");
					    }
					break;
					case 5://Modificar contratacion
						if(!contratacion_modifify(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN))
						{
							printf("\n  MODIFICACION EXITOSA\n");
						}
						else
						{
							printf("\n  MODIFICACION INCORECTA\n");
						}
					break;
					case 6://Baja Contratacion
						if(!contratacion_remove(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN))
						{
							 printf("\n  BAJA EXITOSA\n");
						}
						else
						{
							printf("\n  BAJA INCORRECTA\n");
						}
					break;
					case 7://Consultar Facturacion
						//info_imprimirContratacionesConImporte(arrayContratacion,QTY_CONTRATACIONES);
						informes_importe(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN);
					break;
					case 8://Listar Contrataciones
						contratacion_print(arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN);
					break;
					case 9://Listar Pantallas
						 pantalla_print(arrayPantallas,QTY_SCREEN);
					break;
					case 10://Informar
						informes_imprimirContratacionesConImportePorCliente (arrayContratacion,QTY_CONTRATACIONES,arrayPantallas,QTY_SCREEN);
					break;
				}
			}
		}while(opcion!=11);
	}
	return EXIT_SUCCESS;
}

