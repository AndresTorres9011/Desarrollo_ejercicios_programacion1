/*
 ============================================================================
 Name        : clase_09.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 CLASE DE ESTRUCTURAS
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int indice;

	Alumno arrayAlumnos[QTY_ALUMNOS];

	if(alumno_initArray(arrayAlumnos,QTY_ALUMNOS)==0)
	{
		do
		{
			if(utn_getNumero("\n  1-Alta Alumno\n  2-Modificar Alumno\n  3-Baja Alumno"
				             "\n  4-Ordenar por Nombre\n  5-Mostrar\n  6-Salir\n\n  Ingrese opción:",
							 "ERROR Reingrese opcion valida",&opcion,2,1,6)==0)
			{
				switch(opcion)
				{
					case 1:
						if(utn_getNumero("\n  Ingrese Indice?","\nError",&indice,2,0,QTY_ALUMNOS-1) == 0)
						// alumno_buscarLibre(arrayAlumnos,QTY_ALUMNOS)
						{
							alumno_alta(arrayAlumnos,QTY_ALUMNOS,indice);
						}
						break;
					case 2:
						// alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
					break;
					case 3:
						// alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
					break;
					case 4:
						// alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
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
