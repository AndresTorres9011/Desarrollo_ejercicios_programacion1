/*
 * utn.h
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int* pIndex, int id);
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_altaSinIndice (Alumno * pArrayAlumnos, int limite);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_printById(Alumno* pArray, int limit, int index);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_buscarLibreRef(Alumno pArrayAlumnos[], int limite, int *pIndex);
int alumno_buscarLibreValor(Alumno pArrayAlumnos[], int limit);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int alumno_ordenarPorNombre( Alumno pArray[], int len);
int alumno_ordenarPorLegajo( Alumno pArray[], int len);
int alumno_baja(Alumno arrayAlumnos[],int limite,int indice);

#endif /* ALUMNO_H_ */
