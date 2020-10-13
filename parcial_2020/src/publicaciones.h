/*
 * publicaciones.h
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef PUBLICACIONES_H_
#define PUBLICACIONES_H_

#include "cliente.h"
#define SIZE_TEXT 64


typedef struct
{
	int id;
	int isEmpty;
	int idCliente;
	char texto[SIZE_TEXT];
	int rubro;
	int isActive;
}Publicacion;

int publicacion_init(Publicacion* list, int len);
int publicacion_add(Publicacion *list, int len, Cliente *clientList, int clientLen);
int publicacion_modify(Publicacion *list, int len);
int publicacion_pause(Publicacion *list, int len, Cliente *clientList, int clientLen);
int publicacion_reanude(Publicacion *list, int len, Cliente *clientList, int clientLen);;
int publicacion_searchEmpty(Publicacion *list, int len, int *pIndex);
int publicacion_findById(Publicacion *list, int len, int id, int *pIndex);
int publicacion_findByClientId(Publicacion *list, int len, int id);
int publicacion_print(Publicacion *list, int len);
int publicacion_printClientById(Publicacion *list, int len, Cliente *clientList, int clientLen, int id);
int publicacion_remove(Publicacion *list, int len, int id);
int publicacion_searchForActive(Publicacion *list, int len);
int publicacion_searchForNoEmpty(Publicacion *list, int len);
int publicacion_counterClient(Publicacion *adList, int adLen, int id, int *pCounter);
int publicacion_counterActiveClient(Publicacion *adList, int adLen, int id, int *pCounter);
int publicacion_counterPaused(Publicacion *adList, int adLen, int *pCounter);
int publicacion_rubroMax(Publicacion *list, int len);
int publicacion_equalRubro(Publicacion *list, int len, int rubro, int *pCounter);
int publicacion_altaForzada(Publicacion* list, int len,int idCliente,char* texto,int rubro);


#endif /* PUBLICACIONES_H_ */

