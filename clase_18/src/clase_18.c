/*
 ============================================================================
 Name        : clase_18.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "utn.h"

#define QTY_ALUMNOS 100

int main(void)
{
	setbuf(stdout,NULL);

	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];

	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("\nINIT OK\n");
		if(alumno_createNew(arrayPunterosAlumno,QTY_ALUMNOS,"Andres",1.85)>=0)
		{
			printf("\nALTA OK\n");;
		}

		if(alumno_createNew(arrayPunterosAlumno,QTY_ALUMNOS,"Viviana",1.72)>=0)
		{
			printf("\nALTA OK\n");;
		}

		alumno_printAllArray(arrayPunterosAlumno,QTY_ALUMNOS);

		if(!alumno_removeById(arrayPunterosAlumno,QTY_ALUMNOS,1))
		{
			printf("\n BORRADO CON EXITO\n");
		}

		alumno_printAllArray(arrayPunterosAlumno,QTY_ALUMNOS);
	}
	return EXIT_SUCCESS;
}
