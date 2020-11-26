#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "Envios.h"

/**
 * \brief _loadFromText: Carga los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param char* path: File address..
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEnvios != NULL)
	{
		pFile = fopen(path,"r");
		if (pFile != NULL)
		{
			retorno = parser_enviosFromText(pFile, pArrayListEnvios);
			fclose(pFile);
		}
	}
	return retorno;
}
/**
 * \brief _loadFromBinary: Carga los datos de los empleados desde el archivo que recibe como parametro (modo binario).
 * * \param char* path: File address.
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEnvios != NULL)
	{
		pFile = fopen(path,"rb");
		if (pFile != NULL)
		{
			retorno = parser_enviosFromBinary(pFile, pArrayListEnvios);
			fclose(pFile);
		}
	}
	return retorno;
}

/**
 * \brief _ListEnvios: Print all the uploaded data.
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_ListEnvios(LinkedList* pArrayListEnvios)
{
    int retorno = -1;
    int len= ll_len(pArrayListEnvios);
    int i;

    if(pArrayListEnvios != NULL)
    {
    	printf("\n%10s %15s %10s %15s %10s %10s %10s \n",
    			"ID ENVIO","PRODUCTO","ID CAMION","ZONA DESTINO","KM RECORRIDOS","TIPO ENTREGA","COSTO ENVIO\n");
    	for(i=0;i<len;i++)
    	{
    		retorno = controller_printOneEnvios(pArrayListEnvios,i);
    	}
    }
	return retorno;
}
/**
 * \brief _printOneEnvios: Print data by index.
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \param int index: Is the data position in the array.
 * \return (-1) Error / (0) Ok
 */
int controller_printOneEnvios(LinkedList* pArrayListEnvios, int index)
{
	int retorno = -1;
	Envios buffer;
	Envios* pEnvios;

	if(pArrayListEnvios != NULL && index >= 0)
	{
		pEnvios = (Envios*)ll_get(pArrayListEnvios,index);
		if(	pEnvios != NULL && !envios_getIdEnvio(pEnvios,&buffer.idEnvio) &&
			!envios_getNombre(pEnvios,buffer.nombreProducto) &&
			!envios_getIdCamion(pEnvios,&buffer.idCamion) &&
		    !envios_getZonaDestino(pEnvios,buffer.zonaDestino) &&
			!envios_getKmRecorridos(pEnvios,&buffer.kmRecorridos) &&
			!envios_getTipoEntrega(pEnvios,&buffer.tipoEntrega) &&
			!envios_getCostoEnvio(pEnvios,&buffer.costoEnvio))
		{
			printf("\n%10d %15s %10d %15s %10.1f %10d %10.2f\n",
					buffer.idEnvio,buffer.nombreProducto,buffer.idCamion,buffer.zonaDestino,buffer.kmRecorridos,buffer.tipoEntrega,buffer.costoEnvio);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _saveAsText: Guarda los datos de los empleados en el archivo que recibe como parametro (modo texto).
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEnvios != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			retorno = parser_enviosToText(pFile, pArrayListEnvios);
			fclose(pFile);
		}
	}
	return retorno;
}
/**
 * \brief _saveAsBinary: Guarda los datos de los empleados en el archivo que recibe como parametro (modo binario).
 * \param LinkedList* pArrayListEnvios: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEnvios != NULL)
	{
		pFile = fopen(path,"wb");
		if (pFile != NULL)
		{
			retorno = parser_enviosToBinary(pFile, pArrayListEnvios);
			fclose(pFile);
		}
	}
	return retorno;
}
