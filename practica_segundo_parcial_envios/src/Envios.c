#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Envios.h"
#include "validaciones.h"

/** \brief _new: Use malloc function to obtain a new memory address
 * 	\return the new memory address.
 */
Envios* envios_new()
{
	return (Envios*) malloc(sizeof(Envios));
}
/** \brief _newParametrosTxt: Register an envios receiving the parameters as text.
 * \param int id:  Receive the id.
 * \param char* nombre: Receive the name.
 * \param int horasTrabajadas: Receive the worked hours.
 * \param float sueldo: Receive salary.
 * \return The memory address of the envios with all his data loaded or NULL in case something went wrong.
 */
Envios* envios_newParametros(int idEnvio,char* producto,int idCamion,char* destino, float kmRecorridos, int tipoEntrega, float costoEnvio)
{
	Envios* this = NULL;
	this = envios_new();
	if(this != NULL && producto != NULL  && destino != NULL)
	{
		if(	envios_setIdEnvio(this,idEnvio) == -1 ||
			envios_setNombre(this,producto) == -1 ||
			envios_setIdCamion(this,idCamion)==-1 ||
			envios_setZonaDestino(this,destino) == -1 ||
			envios_setKmRecorridos(this,kmRecorridos) == -1 ||
			envios_setTipoEntrega(this,tipoEntrega) == -1 ||
			envios_setCostoEnvio(this,costoEnvio) == -1)

		{
			envios_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _newParametrosTxt: Register an envios receiving the parameters as text.
 * \param char* id:  Receive the id in text form
 * \param char* nombre: Receive the name.
 * \param char* horasTrabajadas: Receive the worked hours in text form.
 * \param char* sueldo: Receive salary in text form.
 * \return The memory address of the envios with all his data loaded or NULL in case something went wrong.
 */
Envios* envios_newParametrosTxt(char* idEnvio,char* producto,char* idCamion,char* destino,char* kmRecorridos,char* tipoEntrega,char* costoEnvio )
{
	Envios* this = NULL;
	this = envios_new();
	if(this != NULL && producto != NULL && idCamion != NULL && idEnvio != NULL && destino != NULL && kmRecorridos != NULL && tipoEntrega != NULL)
	{
		if(	envios_setIdTxtEnvio(this,idEnvio) == -1 ||
			envios_setNombre(this,producto) == -1 ||
			envios_setIdTxtCamion(this,idCamion)==-1 ||
			envios_setZonaDestino(this,destino) == -1 ||
			envios_setKmRecorridosTxt(this,kmRecorridos) == -1 ||
			envios_setTipoEntregaTxt(this,tipoEntrega) == -1 ||
			envios_setCostoEnvioTxt(this,costoEnvio) == -1)
		{
			envios_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _delete: Deletes an envios's reserved memory address.
 *  \param Envios* this: Pointer to envios.

 */
void envios_delete(Envios* this)
{
	free(this);
}
/*
 * \brief _setId: Load the id into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setIdEnvio(Envios* this, int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		this->idEnvio = id;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getId: Obtains the envios's ID.
 * \param Envios* this : Pointer to envios.
 * \param int id: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getIdEnvio(Envios* this, int* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->idEnvio;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdTxt: Load the id as text into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setIdTxtEnvio(Envios* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->idEnvio = atoi(id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdTxt: Obtains the envios's ID as text.
 * \param Envios* this : Pointer to envios.
 * \param char* id: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getIdTxtEnvio(Envios* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idEnvio);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setNombre: Load the name into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param char* nombre: Name to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setNombre(Envios *this, char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && isValidCompoundName(nombre, NOMBRE_LEN))
	{
		strncpy(this->nombreProducto, nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getNombre: Obtains the envios's name.
 * \param Envios* this : Pointer to envios.
 * \param char* nombre: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getNombre(Envios* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombreProducto, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setId: Load the id into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setIdCamion(Envios* this, int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		this->idCamion = id;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getId: Obtains the envios's ID.
 * \param Envios* this : Pointer to envios.
 * \param int id: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getIdCamion(Envios* this, int* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->idCamion;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdTxt: Load the id as text into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setIdTxtCamion(Envios* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->idCamion = atoi(id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdTxt: Obtains the envios's ID as text.
 * \param Envios* this : Pointer to envios.
 * \param char* id: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getIdTxtCamion(Envios* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idCamion);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setZonaDestino: Load the name into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param char* zona: Name to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setZonaDestino(Envios *this, char* zona)
{
	int retorno = -1;
	if (this != NULL && zona != NULL && isValidCompoundName(zona, NOMBRE_LEN))
	{
		strncpy(this->zonaDestino, zona, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getZonaDestino: Obtains the envios's name.
 * \param Envios* this : Pointer to envios.
 * \param char* zona: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getZonaDestino(Envios* this, char* zona)
{
    int retorno = -1;
    if (this != NULL && zona != NULL)
    {
        strncpy(zona, this->zonaDestino, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}

/*
 * \brief _setSueldo: Load the salarys into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param float sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setKmRecorridos(Envios* this, float kmRecorridos)
{
	int retorno = -1;
	if(this != NULL && kmRecorridos > 0)
	{
		this->kmRecorridos = kmRecorridos;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getSueldo: Obtains the envios's salary.
 * \param Envios* this : Pointer to envios.
 * \param float* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getKmRecorridos(Envios* this, float* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL)
    {
        *kmRecorridos = this->kmRecorridos;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setSueldoTxt: Load the worked hours as text into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param char* sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setKmRecorridosTxt(Envios* this, char* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL && isValidNumberFloat(kmRecorridos, sizeof(kmRecorridos)))
    {
        this->kmRecorridos = atof(kmRecorridos);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getSueldoTxt: Obtains the envios's salary as text.
 * \param Envios* this : Pointer to envios.
 * \param char* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getKmRecorridosTxt(Envios* this, char* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL)
    {
        sprintf(kmRecorridos, "%.2f", this->kmRecorridos);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setHorasTrabajadas: Load the worked hours into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param int tipoEntrega: Worked hours to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setTipoEntrega(Envios* this, int tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega > 0)
	{
		this->tipoEntrega = tipoEntrega;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getHorasTrabajadas: Obtains the envios's worked hours.
 * \param Envios* this : Pointer to envios.
 * \param int* tipoEntrega: Pointer to the space where the obtained worked hours will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getTipoEntrega(Envios* this, int* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setHorasTrabajadasTxt: Load the worked hours as text into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param char* horasTrabajadas: Worked hours to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setTipoEntregaTxt(Envios* this, char* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL && isValidNumber(tipoEntrega, sizeof(tipoEntrega)))
    {
        this->tipoEntrega = atoi(tipoEntrega);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getHorasTrabajadasTxt: Obtains the envios's worked hours as text.
 * \param Envios* this : Pointer to envios.
 * \param char* tipoEntrega: Pointer to the space where the obtained worked hours will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getTipoEntregaTxt(Envios* this, char* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL)
    {
        sprintf(tipoEntrega, "%d", this->tipoEntrega);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setSueldo: Load the salarys into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param float sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setCostoEnvio(Envios* this, float costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio > 0)
	{
		this->costoEnvio = costoEnvio;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getSueldo: Obtains the envios's salary.
 * \param Envios* this : Pointer to envios.
 * \param float* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getCostoEnvio(Envios* this, float* costoEnvio)
{
    int retorno = -1;
    if (this != NULL && costoEnvio != NULL)
    {
        *costoEnvio = this->costoEnvio;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setSueldoTxt: Load the worked hours as text into the envios's field.
 * \param Envios* this : Pointer to envios.
 * \param char* sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_setCostoEnvioTxt(Envios* this, char* costoEnvio)
{
    int retorno = -1;
    if (this != NULL && costoEnvio != NULL && isValidNumberFloat(costoEnvio, sizeof(costoEnvio)))
    {
        this->costoEnvio = atof(costoEnvio);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getSueldoTxt: Obtains the envios's salary as text.
 * \param Envios* this : Pointer to envios.
 * \param char* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int envios_getCostoEnvioTxt(Envios* this, char* costoEnvio)
{
    int retorno = -1;
    if (this != NULL && costoEnvio != NULL)
    {
        sprintf(costoEnvio, "%.2f", this->costoEnvio);
        retorno = 0;
    }
    return retorno;
}
float calcularCostoEnvio(float kmRecorridos, int tipoEntrega)
{
	float costo = -1;

	if (kmRecorridos > 0 && (tipoEntrega == 0 || tipoEntrega == 1 || tipoEntrega == 2))
	{
		if(kmRecorridos<50)
		{
			costo = 150*kmRecorridos;

		} else {
			costo = 100*kmRecorridos;
		}

		if(tipoEntrega == 0)
		{
			costo = costo+350;
		}
		else if(tipoEntrega == 1)
		{
			costo = costo+420;
		}
		else
		{
			costo = costo+275;
		}
	}
	return costo;
}
