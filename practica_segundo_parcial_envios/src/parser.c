#include <stdio.h>
#include <stdlib.h>

#include "Envios.h"
#include "LinkedList.h"

#define BUFFER_STRING 4096
/*
 * \brief _enviosFromText: Parse the envios data from the file in text mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEnvios:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int parser_enviosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	Envios *pEnvios;
	char bufferHeader[BUFFER_STRING];
	char bufferIdEnvio[BUFFER_STRING];
	char bufferProducto[BUFFER_STRING];
	char bufferIdCamion[BUFFER_STRING];
	char bufferZonaDestino[BUFFER_STRING];
	char bufferKmRecorridos[BUFFER_STRING];
	char bufferTipoEntrega[BUFFER_STRING];
	char bufferCostoEnvio[BUFFER_STRING]="00";

	if (pFile != NULL && pArrayListEnvios != NULL)
	{
		fscanf(pFile, "%[^\n]\n",bufferHeader);
		do
		{
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferIdEnvio, bufferProducto, bufferIdCamion, bufferZonaDestino, bufferKmRecorridos, bufferTipoEntrega) == 6)
			{
				pEnvios = envios_newParametrosTxt(bufferIdEnvio, bufferProducto, bufferIdCamion, bufferZonaDestino, bufferKmRecorridos, bufferTipoEntrega,bufferCostoEnvio);
				if (pEnvios != NULL)
				{
					retorno = ll_add(pArrayListEnvios, pEnvios);
				}
			}
			else
			{
				break;
			}
		} while (!feof(pFile));
	}
	return retorno;
}

/*
 * \brief _enviosFromBinary: Parse the envios data from the file in binary mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEnvios:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int parser_enviosFromBinary(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	Envios* pEnvios;

	if (pFile != NULL && pArrayListEnvios != NULL)
	{
		do
		{
			pEnvios = envios_new();
			if (pEnvios != NULL && fread(pEnvios,sizeof(Envios),1,pFile)==1)
			{
				retorno = ll_add(pArrayListEnvios, pEnvios);
			}
			else
			{
				break;
			}
		} while (!feof(pFile));
	}
	return retorno;
}
/*
 * \brief _enviosToText:  Parse envios data to the text mode file.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEnvios:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int parser_enviosToText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	Envios *pEnvios;
	int bufferIdEnvio;
	char bufferNombre[NOMBRE_LEN];
	int bufferIdCamion;
	char bufferZonaDestino[NOMBRE_LEN];
	float bufferKmRecorridos;
	int bufferTipoEntrega;
	float bufferCostoEnvio;

	int len= ll_len(pArrayListEnvios);
	int i;

	if (pFile != NULL && pArrayListEnvios != NULL)
	{
		fprintf(pFile,"ID ENVIO,PRODUCTO,ID CAMION,ZONA DESTINO,KM RECORRIDOS,TIPO ENTREGA,COSTO ENVIO\n");
		for (i = 0; i < len; i++)
		{
			pEnvios =ll_get(pArrayListEnvios, i);
		   if ( pEnvios != NULL &&
				!envios_getIdEnvio(pEnvios,&bufferIdEnvio) &&
				!envios_getNombre(pEnvios,bufferNombre) &&
				!envios_getIdCamion(pEnvios,&bufferIdCamion) &&
				!envios_getZonaDestino(pEnvios,bufferZonaDestino) &&
				!envios_getKmRecorridos(pEnvios,&bufferKmRecorridos) &&
				!envios_getTipoEntrega(pEnvios,&bufferTipoEntrega) &&
				!envios_getCostoEnvio(pEnvios,&bufferCostoEnvio))
			{
				fprintf(pFile, "%d,%s,%d,%s,%f,%d,%f\n", bufferIdEnvio, bufferNombre,bufferIdCamion,bufferZonaDestino,bufferKmRecorridos,bufferTipoEntrega,bufferCostoEnvio);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _enviosToBinary: Parse envios data to the binary mode file.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEnvios:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Envios* is NULL \ (0) OK
 */
int parser_enviosToBinary(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	Envios* pEnvios;
	int len=ll_len(pArrayListEnvios);
	int i;

	if (pFile != NULL && pArrayListEnvios != NULL)
	{
		for (i = 0; i < len; i++)
		{
			pEnvios =ll_get(pArrayListEnvios, i);
			if (pEnvios != NULL)
			{
				fwrite(pEnvios, sizeof(Envios), 1, pFile);
			}
		}
		retorno = 0;
	}
	return retorno;
}
