/*
 * clientes.c
 *
 *  Created on: 25/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "validations.h"

/** \brief _new: Use malloc function to obtain a new memory address
 * 	\return the new memory address.
 */
Cliente* cliente_new()
{
	return (Cliente*) malloc(sizeof(Cliente));
}
/** \brief __newParametros: Register a client receiving the parameters as text.
 * \param int id:  Receive the id.
 * \param char* cuit: Receive the cuit.
 * \param char* nombre: Receive the name.
 * \param  char* apellido:: Receive the last name.
 * \return The memory address of the client with all his data loaded or NULL in case something went wrong.
 */
Cliente* cliente_newParametros(int id,char* cuit,char* nombre,char* apellido)
{
	Cliente* this = NULL;
	this = cliente_new();
	if(this != NULL && nombre != NULL)
	{
		if(	cliente_setId(this,id) == -1 ||
			cliente_setCuit(this,cuit)==-1 ||
			cliente_setNombre(this,nombre) == -1 ||
			cliente_setApellido(this,apellido) == -1)
		{
			cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _newParametrosTxt: Register an client receiving the parameters as text.
 * \param char* id:  Receive the id in text form
 * \param char* cuit: Receive the cuit.
 * \param char* nombre: Receive the name.
 * \param  char* apellido: Receive the last name.
 * \return The memory address of the client with all his data loaded or NULL in case something went wrong.
 */
Cliente* cliente_newParametrosTxt(char* id,char* cuit,char* nombre,char* apellido)
{
	Cliente* this = NULL;
	this = cliente_new();
	if(this != NULL && nombre != NULL && cuit != NULL && id != NULL && apellido != NULL)
	{
		if(	cliente_setIdTxt(this,id) == -1 ||
			cliente_setCuit(this,cuit) == -1 ||
			cliente_setNombre(this,nombre) == -1 ||
			cliente_setApellido(this,apellido) == -1)
		{
			cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _delete: Deletes an cliente's reserved memory address.
 *  \param Cliente* this: Pointer to cliente.

 */
void cliente_delete(Cliente* this)
{
	free(this);
}
/*
 * \brief _setId: Load the id into the client's field.
 * \param Cliente* this : Pointer to client.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_setId(Cliente* this, int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getId: Obtains the client's ID.
 * \param Cliente* this : Pointer to client.
 * \param int id: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdTxt: Load the id as text into the client's field.
 * \param Cliente* this : Pointer to cliente.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_setIdTxt(Cliente* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdTxt: Obtains the client's ID as text.
 * \param Cliente* this : Pointer to cliente.
 * \param char* id: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_getIdTxt(Cliente* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setCuit: Load the cuit into the client's field.
 * \param Cliente* this : Pointer to client.
 * \param char* nombre: Name to load.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_setCuit(Cliente *this, char* cuit)
{
	int retorno = -1;
	if (this != NULL && cuit != NULL && isValidCuit(cuit))
	{
		strncpy(this->cuit,cuit,SIZE_CUIT);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getCuit: Obtains the client's cuit.
 * \param Cliente* this : Pointer to client.
 * \param char* cuit: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_getCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if (this != NULL && cuit != NULL)
    {
        strncpy(cuit, this->cuit,SIZE_CUIT);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setNombre: Load the name into the client's field.
 * \param Cliente* this : Pointer to client.
 * \param char* nombre: Name to load.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_setNombre(Cliente *this, char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && isValidName(nombre, NOMBRE_LEN))
	{
		strncpy(this->nombre, nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getNombre: Obtains the cliente's name.
 * \param Cliente* this : Pointer to cliente.
 * \param char* nombre: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setApellido: Load the name into the cliente's field.
 * \param Cliente* this : Pointer to cliente.
 * \param char* apellido: Last name to load.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_setApellido(Cliente *this, char* apellido)
{
	int retorno = -1;
	if (this != NULL && apellido != NULL && isValidName(apellido, NOMBRE_LEN))
	{
		strncpy(this->apellido, apellido, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getApellido: Obtains the cliente's name.
 * \param Cliente* this : Pointer to cliente.
 * \param char* apellido: Pointer to the space where the obtained last name will be stored.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if (this != NULL && apellido != NULL)
    {
        strncpy(apellido, this->apellido, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}

/*
 * \brief _compareByName: Compare two cliente names.
 * \param void* thisA: Pointer to the first cliente to compare.
 * \param void* thisB: Pointer to the second cliente to compare.
 * \return int (-1) If the first cliente's name is less than the second. \(1) If the first cliente's name is greater than the second.
 * 					   (0) If the names are the same.
 */
int cliente_compareByName(void* thisA, void* thisB)
{
	int retorno = 0;
	Cliente* pClienteA = (Cliente*)thisA;
	char bufferNombreA[NOMBRE_LEN];
	char bufferNombreB[NOMBRE_LEN];
	int respuestaStrCmp;

	if(thisA != NULL && thisB != NULL)
	{
		cliente_getNombre(pClienteA,bufferNombreA);
		cliente_getNombre((Cliente*)thisB,bufferNombreB);
		respuestaStrCmp=strcmp(bufferNombreA,bufferNombreB);
		if(respuestaStrCmp > 0)
		{
			retorno = 1;
		}
		else if(respuestaStrCmp < 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief headerClient: Imprime una cabecera.
 * \param void*
 * \return void Return
 */
void headerClient(void)
{
	printf("\n%10s %15s %15s %15s\n","ID","CUIT","NOMBRE","APELLIDO");
}
/*
 * \brief _print: Print data of one client..
 * \param void* this: Pointer to the first cliente to compare.
 * \return int (-1) If pointer is NULL.
 * 			   (0) todo ok.
 */
int cliente_print(void* this)
{
	int retornar=-1;
	Cliente* bufferClient;
	int bufferId;
	char bufferName[NOMBRE_LEN];
	char bufferLastName[NOMBRE_LEN];
	char bufferCuit[SIZE_CUIT];

	if(this!=NULL)
	{
		retornar=0;
		bufferClient = (Cliente*) this;
		if( !cliente_getId(bufferClient, &bufferId) &&
			!cliente_getCuit(bufferClient, bufferCuit) &&
			!cliente_getNombre(bufferClient, bufferName) &&
			!cliente_getApellido(bufferClient, bufferLastName))
		{
			printf("\n%10d %15s %15s %15s\n",bufferId,bufferCuit,bufferName,bufferLastName);
			//printf("\nID: %d - Cuit: %s - Nombre: %s - Apellido: %s ", bufferId, bufferCuit, bufferName, bufferLastName);
		}
	}
	return retornar;
}
