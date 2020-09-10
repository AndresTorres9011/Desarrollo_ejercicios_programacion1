/*
 * utn.h
 *
 *  Created on: 8/09/2020
 *      Author: Torres Andres
 */

#ifndef UTN_H_
#define UTN_H_

int int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
char utn_getCaracter(char* mensaje, char* mensajeError,char* pResultado, int reintentos, char minimo, char maximo);

#endif /* UTN_H_ */
