/*
 ============================================================================
 Name        : clase_10.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	//int indiceVacio;
	int idModificar;
	int indice;
	int opcionOrdenar;
	int idBaja;

	Alumno arrayAlumnos[QTY_ALUMNOS];

	if(alumno_initArray(arrayAlumnos,QTY_ALUMNOS)==0)
	{
		do
		{
			if(utn_getNumeroString("\n  1-Alta Alumno\n  2-Modificar Alumno\n  3-Baja Alumno"
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
						   if(alumno_altaSinIndice (arrayAlumnos,QTY_ALUMNOS)==0)
						   {
							   printf("\n  ALTA DE ALUMNO EXITOSA\n");
						   }
						   else
						   {
							   printf("\n  NO SE REALIZO ALTA DEL ALUMNO\n");
						   }
						break;
					case 2:
						// MODIFICAR POR ID
						if(utn_getNumeroString("Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
								                ,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
						{
							if(alumno_buscarId(arrayAlumnos, QTY_ALUMNOS, &indice, idModificar)==0)
							{
								alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
							}
						}
					break;
					case 3:
						if(	utn_getNumeroString("\n Ingrese ID A Borrar?","\nError Reingrese ID a borrar",&idBaja,CANTIDAD_REINTENTOS,MIN_ID,MAX_ID) == 0)
						{
							if(alumno_buscarId(arrayAlumnos, QTY_ALUMNOS, &indice, idBaja)==0)
							{
								alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
							}
						}
					break;
					case 4:
						if(utn_getNumeroString("\n  1-Ordenar por nombre\n  2-Ordenar por legajo\n\n Ingrese opcion orden:",
								                "ERROR Reingrese opcion valida",&opcionOrdenar,CANTIDAD_REINTENTOS,1,2)==0)
						{
							switch(opcionOrdenar)
							{
								case 1:
									alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
								break;
								case 2:
									alumno_ordenarPorLegajo(arrayAlumnos,QTY_ALUMNOS);
								break;
							}
						}
					break;
					case 5:
						alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
					break;
				}
			}
		}while(opcion!=6);
	}
	return EXIT_SUCCESS;
}
