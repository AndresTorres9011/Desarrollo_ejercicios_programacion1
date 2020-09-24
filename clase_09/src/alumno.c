/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(	arrayAlumnos != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayAlumnos[indice].isEmpty == TRUE)
	{
		if(	utn_getNumero("\n  Legajo?","\nError",&bufferAlumno.legajo,2,MIN_LEGAJO,MAX_LEGAJO) == 0 &&
			utn_getNombre("\n  Nombre?","\nError",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			arrayAlumnos[indice].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	return retorno;
}



/**
 * \brief Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\n %d Nombre: %s - Legajo: %d\n",i,pArrayAlumnos[i].nombre,pArrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
