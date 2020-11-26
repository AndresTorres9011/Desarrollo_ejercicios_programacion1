/*
 * Alumno.h
 *
 *  Created on: 2/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	float altura;
	int id;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParametros(char* nombre,float altura,int id);
void alumno_delete(Alumno* this);
int alumno_setNombre(Alumno* this,char* nombre);
int alumno_getNombre(Alumno* this,char* nombre);
int alumno_setIdTxt(Alumno* this,char* id);
int alumno_setId(Alumno* this,int id);
int alumno_getIdTxt(Alumno* this,char* id);
int alumno_setAltura(Alumno* this,float altura);
int alumno_getAltura(Alumno* this,float* altura);

/**************************************************************/

int alumno_initArray(Alumno* arrayPunteros[],int limite);
int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite);
int alumno_imprimirArray(Alumno* arrayPunteros[],int limite);
int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice);
int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id);
int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int alumno_ordenarArray(Alumno* arrayPunteros[],int limite);
int alumno_calcularAlturaPromedioArray(Alumno* arrayPunteros[],int limite, float* promedio);
int alumno_calcularAlturaMaximaArray(Alumno* arrayPunteros[],int limite, int* indice);
#endif /* ALUMNO_H_ */

