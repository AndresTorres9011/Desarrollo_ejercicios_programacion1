/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_NACIONALIDAD 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int isEmpty;
	int id;
}Nacionalidad;

int nacionalidad_buscarId(Nacionalidad* pArray, int limite, int* pIndex, int id);
int nacionalidad_alta(Nacionalidad array[],int limite,int indice);
int nacionalidad_altaSinIndice (Nacionalidad * pArray, int limite);
int nacionalidad_imprimir(Nacionalidad* pArray, int limite);
int nacionalidad_printById(Nacionalidad* pArray, int limit, int index);
int nacionalidad_initArray(Nacionalidad* pArray, int limite);
int nacionalidad_buscarLibreRef(Nacionalidad pArray[], int limite, int *pIndex);
int nacionalidad_buscarLibreValor(Nacionalidad pArray[], int limit);
int nacionalidad_modificar(Nacionalidad array[],int limite,int indice);
int nacionalidad_ordenarPorNombre( Nacionalidad pArray[], int len);
int nacionalidad_baja(Nacionalidad array[],int limite,int indice);


#endif /* NACIONALIDAD_H_ */
