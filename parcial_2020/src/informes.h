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

int info_printAdsByClientID(Cliente *clientList, int clientLen, Publicacion *adList, int adLen, int id);
int info_printActive(Cliente *clientList, int clientLen, Publicacion *adList, int adLen);
int info_report(Cliente *clientList, int clientLen, Publicacion *adList, int adLen);
int info_clientMax(Cliente *clientList, int clientLen, Publicacion *adList, int adLen);
int info_pausedAdsQty(Cliente *clientList, int clientLen, Publicacion *adList, int adLen);

#endif /* INFORMES_H_ */
