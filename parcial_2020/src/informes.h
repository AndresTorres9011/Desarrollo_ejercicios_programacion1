/*
 * informes.h
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "cliente.h"
#include "publicaciones.h"

int info_printAdsByClientID(Cliente *listUno, int lenUno, Publicacion *listDos, int lenDos, int id);
int info_removeClientById(Cliente* list,int len,Publicacion* listDos,int lenDos);
int info_printActive(Cliente *listUno, int lenUno, Publicacion *listDos, int lenDos);
int info_report(Cliente *listUno, int lenUno, Publicacion *listDos, int lenDos);
int informe_imprimirClienteMayorCantidadAvisos(Publicacion* listUno,int lenUno,Cliente* listDos,int lenDos);

#endif /* INFORMES_H_ */
