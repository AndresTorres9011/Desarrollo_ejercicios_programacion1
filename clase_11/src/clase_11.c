/*
 ============================================================================
 Name        : clase_11.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "nacionalidad.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	//int indiceVacio;
	int idModificar;
	int indice;
	int idBaja;

	Nacionalidad array[QTY_NACIONALIDAD];

	if(nacionalidad_initArray(array,QTY_NACIONALIDAD)==0)
	{
		do
		{
			if(utn_getNumeroString("\n  1-Alta \n  2-Modificar \n  3-Baja "
				             "\n  4-Ordenar por Nombre\n  5-Mostrar\n  6-Salir\n\n  Ingrese opción:",
							 "ERROR Reingrese opcion valida",&opcion,CANTIDAD_REINTENTOS,1,6)==0)
			{
				switch(opcion)
				{
					case 1:
						/*if(alumno_buscarLibreRef(arrayAlumnos,QTY_ALUMNOS,&indiceVacio)==0)
						{
							alumno_alta(arrayAlumnos,QTY_ALUMNOS,indiceVacio);

						}*/
						   if(nacionalidad_altaSinIndice (array,QTY_NACIONALIDAD)==0)
						   {
							   printf("\n  ALTA EXITOSA\n");
						   }
						   else
						   {
							   printf("\n  NO SE REALIZO ALTA \n");
						   }
						break;
					case 2:
						// MODIFICAR POR ID
						if(utn_getNumeroString("Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
								                ,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
						{
							if(nacionalidad_buscarId(array, QTY_NACIONALIDAD, &indice, idModificar)==0)
							{
								nacionalidad_modificar(array,QTY_NACIONALIDAD,indice);
							}
						}
					break;
					case 3:
						if(	utn_getNumeroString("\n Ingrese ID A Borrar?","\nError Reingrese ID a borrar",&idBaja,CANTIDAD_REINTENTOS,MIN_ID,MAX_ID) == 0)
						{
							if(nacionalidad_buscarId(array, QTY_NACIONALIDAD, &indice, idBaja)==0)
							{
								nacionalidad_baja(array,QTY_NACIONALIDAD,indice);
							}
						}
					break;
					case 4:
							nacionalidad_ordenarPorNombre(array,QTY_NACIONALIDAD);
					break;
					case 5:
						nacionalidad_imprimir(array,QTY_NACIONALIDAD);
					break;
				}
			}
		}while(opcion!=6);
	}
	return EXIT_SUCCESS;
}
