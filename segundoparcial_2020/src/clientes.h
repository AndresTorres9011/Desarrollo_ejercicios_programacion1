/*
 * clientes.h
 *
 *  Created on: 25/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define NOMBRE_LEN 128
#define SIZE_CUIT 14
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999

typedef struct
{
    int id;
    char cuit[SIZE_CUIT];
    char nombre[NOMBRE_LEN];
    char apellido[NOMBRE_LEN];
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newParametros(int id,char* cuit,char* nombre,char* apellido);
Cliente* cliente_newParametrosTxt(char* id,char* cuit,char* nombre,char* apellido);
void cliente_delete(Cliente*);

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);
int cliente_setIdTxt(Cliente* this, char* id);
int cliente_getIdTxt(Cliente* this, char* id);

int cliente_setCuit(Cliente* this, char* nombre);
int cliente_getCuit(Cliente* this, char* nombre);

int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);

int cliente_setApellido(Cliente* this, char* nombre);
int cliente_getApellido(Cliente* this, char* nombre);

int cliente_compareByName(void* thisA, void* thisB);
void headerClient(void);
int cliente_print(void* this);



#endif /* CLIENTES_H_ */
