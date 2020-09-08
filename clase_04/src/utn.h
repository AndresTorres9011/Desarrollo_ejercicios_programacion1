/*
 * utn.h
 *
 *  Created on: 8/09/2020
 *      Author: Torres Andres
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
char utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* UTN_H_ */
