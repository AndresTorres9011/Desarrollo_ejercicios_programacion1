/*
 * ventas.c
 *
 *  Created on: 26/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventas.h"
#include "validations.h"

#define BUFFER_STRING 4096

/** \brief _new: Use malloc function to obtain a new memory address
 * 	\return the new memory address.
 */
Venta* venta_new()
{
	return (Venta*) malloc(sizeof(Venta));
}
/** \brief __newParametros: Register a client receiving the parameters as text.
 * \param int id:  Receive the id.
 * \param char* cuit: Receive the cuit.
 * \param char* nombre: Receive the name.
 * \param  char* apellido:: Receive the last name.
 * \return The memory address of the client with all his data loaded or NULL in case something went wrong.
 */
Venta* venta_newParametros(int idCliente,int idVenta,int cantidadAfiches,char* nombreArchivo,int zona,int estadoVenta)
{
	Venta* this = NULL;
	this = venta_new();
	if(this != NULL && nombreArchivo != NULL)
	{
		if(	venta_setIdCliente(this,idCliente) == -1 ||
			venta_setIdVenta(this,idVenta)==-1 ||
			venta_setCantidadAfiches(this,cantidadAfiches)==-1 ||
			venta_setNombreArchivo(this,nombreArchivo) == -1 ||
			venta_setZona(this,zona) == -1 ||
			venta_setEstadoVenta(this,estadoVenta) == -1)
		{
			venta_delete(this);
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
Venta* venta_newParametrosTxt(char* idCliente,char* idVenta,char* cantidadAfiches,char* nombreArchivo,char* zona,char* estadoVenta)
{
	Venta* this = NULL;
	this = venta_new();
	if(this != NULL && nombreArchivo != NULL && idCliente != NULL && idVenta != NULL && cantidadAfiches != NULL && zona != NULL && estadoVenta != NULL)
	{
		if(	venta_setIdClienteTxt(this,idCliente) == -1 ||
			venta_setIdVentaTxt(this,idVenta) == -1 ||
			venta_setCantidadAfichesTxt(this,cantidadAfiches) == -1 ||
			venta_setNombreArchivo(this,nombreArchivo) == -1 ||
			venta_setZonaTxt(this,zona) == -1 ||
			venta_setEstadoVentaTxt(this,estadoVenta) == -1 )
		{
			venta_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _delete: Deletes an venta's reserved memory address.
 *  \param Venta* this: Pointer to venta.

 */
void venta_delete(Venta* this)
{
	free(this);
}
/*
 * \brief _setId: Load the id into the client's field.
 * \param Venta* this : Pointer to client.
 * \param int idCliente: Id to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setIdCliente(Venta* this, int idCliente)
{
	int retorno = -1;
	if (this != NULL && idCliente >= 0)
	{
		this->idCliente = idCliente;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getId: Obtains the client's ID.
 * \param Venta* this : Pointer to client.
 * \param int idCliente: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getIdCliente(Venta* this, int* idCliente)
{
    int retorno = -1;
    if (this != NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdTxt: Load the id as text into the client's field.
 * \param Venta* this : Pointer to venta.
 * \param int idCliente: Id to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setIdClienteTxt(Venta* this, char* idCliente)
{
    int retorno = -1;
    if (this != NULL && idCliente != NULL && isValidNumber(idCliente, sizeof(idCliente)))
    {
        this->idCliente = atoi(idCliente);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdTxt: Obtains the client's ID as text.
 * \param Venta* this : Pointer to venta.
 * \param char* idCliente: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getIdClienteTxt(Venta* this, char* idCliente)
{
    int retorno = -1;
    if (this != NULL && idCliente != NULL)
    {
        sprintf(idCliente, "%d", this->idCliente);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdVenta: Load the id into the client's field.
 * \param Venta* this : Pointer to client.
 * \param int idVenta: Id to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setIdVenta(Venta* this, int idVenta)
{
	int retorno = -1;
	if (this != NULL && idVenta >= 0)
	{
		this->idVenta = idVenta;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getIdVenta: Obtains the client's ID.
 * \param Venta* this : Pointer to client.
 * \param int idVenta: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getIdVenta(Venta* this, int* idVenta)
{
    int retorno = -1;
    if (this != NULL && idVenta != NULL)
    {
        *idVenta = this->idVenta;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdVentaTxt: Load the id as text into the client's field.
 * \param Venta* this : Pointer to venta.
 * \param int idVenta: Id to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setIdVentaTxt(Venta* this, char* idVenta)
{
    int retorno = -1;
    if (this != NULL && idVenta != NULL && isValidNumber(idVenta, sizeof(idVenta)))
    {
        this->idVenta = atoi(idVenta);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdVentaTxt: Obtains the client's ID as text.
 * \param Venta* this : Pointer to venta.
 * \param char* idVenta: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getIdVentaTxt(Venta* this, char* idVenta)
{
    int retorno = -1;
    if (this != NULL && idVenta != NULL)
    {
        sprintf(idVenta, "%d", this->idVenta);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setCantidadAfiches: Load the id into the client's field.
 * \param Venta* this : Pointer to client.
 * \param int cantidadAfiches: Data to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setCantidadAfiches(Venta* this, int cantidadAfiches)
{
	int retorno = -1;
	if (this != NULL && cantidadAfiches >= 0)
	{
		this->cantidadAfiches = cantidadAfiches;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getCantidadAfiches: Obtains the client's ID.
 * \param Venta* this : Pointer to client.
 * \param int cantidadAfiches: Pointer to the space where the obtained data will be stored
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getCantidadAfiches(Venta* this, int* cantidadAfiches)
{
    int retorno = -1;
    if (this != NULL && cantidadAfiches != NULL)
    {
        *cantidadAfiches = this->cantidadAfiches;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setCantidadAfichesTxt: Load the id as text into the client's field.
 * \param Venta* this : Pointer to venta.
 * \param int cantidadAfiches: Id to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setCantidadAfichesTxt(Venta* this, char* cantidadAfiches)
{
    int retorno = -1;
    if (this != NULL && cantidadAfiches != NULL && isValidNumber(cantidadAfiches, sizeof(cantidadAfiches)))
    {
        this->cantidadAfiches = atoi(cantidadAfiches);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getCantidadAfichesTxt: Obtains the client's ID as text.
 * \param Venta* this : Pointer to venta.
 * \param char* cantidadAfiches: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getCantidadAfichesTxt(Venta* this, char* cantidadAfiches)
{
    int retorno = -1;
    if (this != NULL && cantidadAfiches != NULL)
    {
        sprintf(cantidadAfiches, "%d", this->cantidadAfiches);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setNombre: Load the name into the client's field.
 * \param Venta* this : Pointer to client.
 * \param char* nombre: Name to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setNombreArchivo(Venta* this, char* nombreArchivo)
{
	int retorno = -1;
	if (this != NULL && nombreArchivo != NULL && isValidAlphaNumeric(nombreArchivo, NOMBRE_LEN))
	{
		strncpy(this->nombreArchivo, nombreArchivo, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getNombre: Obtains the venta's name.
 * \param Venta* this : Pointer to venta.
 * \param char* nombre: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getNombreArchivo(Venta* this, char* nombreArchivo)
{
    int retorno = -1;
    if (this != NULL && nombreArchivo != NULL)
    {
        strncpy(nombreArchivo, this->nombreArchivo, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setZona: Load the id into the client's field.
 * \param Venta* this : Pointer to client.
 * \param int zona: Data to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setZona(Venta* this, int zona)
{
	int retorno = -1;
	if (this != NULL && zona >= 0)
	{
		this->zona = zona;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getZona: Obtains the client's ID.
 * \param Venta* this : Pointer to client.
 * \param int zona: Pointer to the space where the obtained data will be stored
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getZona(Venta* this, int* zona)
{
    int retorno = -1;
    if (this != NULL && zona != NULL)
    {
        *zona = this->zona;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setZonaTxt: Load the id as text into the client's field.
 * \param Venta* this : Pointer to venta.
 * \param int zona: Data to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setZonaTxt(Venta* this, char* zona)
{
    int retorno = -1;
    if (this != NULL && zona != NULL && isValidNumber(zona, sizeof(zona)))
    {
        this->zona = atoi(zona);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getZonaTxt: Obtains the client's ID as text.
 * \param Venta* this : Pointer to venta.
 * \param char* zona: Pointer to the space where the obtained data will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getZonaTxt(Venta* this, char* zona)
{
    int retorno = -1;
    if (this != NULL && zona != NULL)
    {
        sprintf(zona, "%d", this->zona);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setEstadoVenta: Load the id into the client's field.
 * \param Venta* this : Pointer to client.
 * \param int estadoVenta: Data to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setEstadoVenta(Venta* this, int estadoVenta)
{
	int retorno = -1;
	if (this != NULL && estadoVenta >= 0)
	{
		this->estadoVenta = estadoVenta;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getEstadoVenta: Obtains the client's ID.
 * \param Venta* this : Pointer to client.
 * \param int estadoVenta: Pointer to the space where the obtained data will be stored
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getEstadoVenta(Venta* this, int* estadoVenta)
{
    int retorno = -1;
    if (this != NULL && estadoVenta != NULL)
    {
        *estadoVenta = this->estadoVenta;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setEstadoVentaTxt: Load the id as text into the client's field.
 * \param Venta* this : Pointer to venta.
 * \param int estadoVenta: Data to load.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_setEstadoVentaTxt(Venta* this, char* estadoVenta)
{
    int retorno = -1;
    if (this != NULL && estadoVenta != NULL && isValidNumber(estadoVenta, sizeof(estadoVenta)))
    {
        this->estadoVenta = atoi(estadoVenta);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getEstadoVentaTxt: Obtains the client's ID as text.
 * \param Venta* this : Pointer to venta.
 * \param char* zona: Pointer to the space where the obtained data will be stored.
 * \return int (-1) ERROR - If pointer to Venta* is NULL \ (0) OK
 */
int venta_getEstadoVentaTxt(Venta* this, char* estadoVenta)
{
    int retorno = -1;
    if (this != NULL && estadoVenta != NULL)
    {
        sprintf(estadoVenta, "%d", this->estadoVenta);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _aCobrar: Obtains the state of the sell.
 * \param void* this : Pointer to venta.
 * \return int (-1) ERROR - (0,1) OK
 */
int venta_aCobrar(void* this)
{
	int retorno=-1;
	Venta* bufferVenta;
	int bufferEstadoVenta;
	if(this!=NULL)
	{
		retorno=0;
		bufferVenta = (Venta*) this;
		if(!venta_getEstadoVenta(bufferVenta, &bufferEstadoVenta) && bufferEstadoVenta==0)
		{
			retorno=1;
		}
	}
	return retorno;
}
/*
 * \brief __estaCobrada: Obtains the state of the sell.
 * \param void* this : Pointer to venta.
 * \return int (-1) ERROR - (0,1) OK
 */
int venta_estaCobrada(void* this)
{
	int retorno=-1;
	Venta* bufferVenta;
	int bufferEstadoVenta;
	if(this!=NULL)
	{
		retorno=1;
		bufferVenta = (Venta*) this;
		if(!venta_getEstadoVenta(bufferVenta, &bufferEstadoVenta) && bufferEstadoVenta==0)
		{
			retorno=0;
		}
	}
	return retorno;
}
/*
 * \brief _compararId: Compare the sell´s id.
 * \param void* this : Pointer to venta.
 * \return int (-1) ERROR - (0,1) OK
 */
int venta_compararId(void* this, void* id)
{
	int retorno=0;
	int bufferIdCliente;
	int bufferId = (int) id;
	Venta* bufferVenta = (Venta*) this;
	if( !venta_getIdCliente(bufferVenta, &bufferIdCliente))
	{
		if(bufferIdCliente == bufferId)
		{
			retorno=1;
		}
	}
	return retorno;
}
