/*
 * alumno.h
 *
 *  Created on: 29/10/2020
 *       Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define SIZE_NAME 50

typedef struct
{
	int idAlumno;
	char nombre[SIZE_NAME];
	float altura;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newConParametros(char* nombre,float altura);
void alumno_delete(Alumno* this);
int alumno_setNombre(Alumno* this,char* nombre);
int alumno_getNombre(Alumno* this,char* nombre);
int alumno_setIdTxt(Alumno* this,char* id);
int alumno_setIdNumber(Alumno* this,int id);
int alumno_getIdTxt(Alumno* this,char* id);
int alumno_setAltura(Alumno* this,float altura);
int alumno_getAltura(Alumno* this,float* altura);

int alumno_initArray(Alumno* arrayPunteros[],int len);
int alumno_searchFreeNull(Alumno* arrayPunteros[],int len);
int alumno_printAllArray(Alumno* arrayPunteros[],int len);
int alumno_removeByIndex(Alumno* arrayPunteros[],int len,int indice);
int alumno_findById(Alumno* arrayPunteros[], int len, int idAlumno);
int alumno_createNew(Alumno* arrayPunteros[],int len,char* nombre,float altura);
int alumno_removeById(Alumno* arrayPunteros[], int len, int idAlumno);

#endif /* ALUMNO_H_ */
