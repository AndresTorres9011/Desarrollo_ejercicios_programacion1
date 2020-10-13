/*
 * informes.h
 *
 *  Created on: 12/10/2020
 *     Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informes_imprimirContratacionesConImporte(Contratacion * list, int len, Pantalla * listDos , int lenDos, char* cuit);
int informes_findByCuit(Contratacion* list, int len, int* pIndex, char* cuitCliente);
int informes_importe(Contratacion * list, int len, Pantalla * listDos , int lenDos);
int informes_imprimirContratacionesConImportePorCliente (Contratacion * list, int len, Pantalla * listDos , int lenDos);
int informes_calcularDeudaCliente(Contratacion * list, int len, Pantalla * listDos , int lenDos, char* cuit, float* deuda);

#endif /* INFORMES_H_ */
