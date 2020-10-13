/*
 * cliente.h
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define SIZE_NAME 51
#define SIZE_CUIT 14


typedef struct
{
	int idCliente;
	int isEmpty;
	char cuit[SIZE_CUIT];
	char nombre[SIZE_NAME];
	char apellido[SIZE_NAME];
}Cliente;

int cliente_init(Cliente* list, int len);
int cliente_searchEmpty(Cliente* list, int len, int *pIndex);
int cliente_createNew(Cliente* list, int len);
int cliente_findById(Cliente* list, int len, int* pIndex, int id);
int cliente_printById(Cliente* list, int len, int index);
int cliente_printAll(Cliente* list, int len);
int cliente_modifify(Cliente* list,int len);
int cliente_remove(Cliente* list,int len);
int cliente_countId(Cliente* list,int len,int* quantityId);
int cliente_altaForzada(Cliente * list, int len,char*cuit, char* nombre,char* apellido);


#endif /* CLIENTE_H_ */
