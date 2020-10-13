/*
 * contrataciones.h
 *
 *  Created on: 8/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 *      	char nombreArchivo[SIZE_NOMBRE];
		int cuitCliente;
		int idPantalla;
		int cantidadDias;

 */
#include "pantalla.h"

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define SIZE_NAME 51
#define SIZE_CUIT 51
#define QTY_SCREEN 15


typedef struct
{
	int idContratacion;
	char name[SIZE_NAME];
	int cantidadDias;
	int idPantalla;
	char cuitCliente[SIZE_CUIT];
	int isEmpty;

}Contratacion;

int contratacion_init(Contratacion* list, int len);
int contratacion_searchEmpty(Contratacion* list, int len, int *pIndex);
int contratacion_createNew(Contratacion * listUno, int lenUno,Pantalla* listDos,int lenDos);
int contratacion_findById(Contratacion* list, int len, int* pIndex, int idContratacion);
int contratacion_print(Contratacion* list, int len,Pantalla * listDos , int lenDos);
int contratacion_modifify(Contratacion* list,int len,Pantalla* listDos,int lenDos);
int contratacion_remove(Contratacion* list,int len,Pantalla* listDos,int lenDos);
int contratacion_countId(Contratacion* list,int len,int* quantityId);
int contratacion_altaForzada(Contratacion * listUno, int lenUno,Pantalla* listDos,int lenDos,int idPantalla,char* name,int cantidadDias,char* cuitCliente);



#endif /* CONTRATACION_H_ */
