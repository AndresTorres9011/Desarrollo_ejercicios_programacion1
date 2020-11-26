/*
 * utn.h
 *
 *  Created on: 25/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef UTN_H_
#define UTN_H_
#include "validations.h"

int utn_getNumber(int* pNumber, char* message, char* errorMessage, int min, int max,int retries);
int utn_getFloatNumber(float *pNumber, char *message, char *errorMessage, float min, float max, int retries);
int utn_getName(char* name, int len, char* message, char* errorMessage, int retries);
int utn_getAlphanumeric(char* name, int len, char* message, char* errorMessage, int retries);
int utn_getMail(char *name, int len, char *message, char *errorMessage, int retries);
int utn_getIdentityDocument(char *name, int len, char *message, char *errorMessage, int retries);
int utn_getCuit(char* msg, char* msgError, char* pResult, int reintentos, int limit);

#endif /* UTN_H_ */
