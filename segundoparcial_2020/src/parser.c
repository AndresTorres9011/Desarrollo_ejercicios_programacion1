/*
 * parser.c
 *
 *  Created on: 25/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "clientes.h"
#include "ventas.h"

#define BUFFER_STRING 4096

/*
 * \brief _clientFromText: Parse the client data from the file in text mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* clientList:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int parser_clientFromText(FILE* pFile , LinkedList* clientList)
{
	int retorno=-1;
	char bufferId[BUFFER_STRING];
	char bufferCuit[BUFFER_STRING];
	char bufferNombre[BUFFER_STRING];
	char bufferApellido[BUFFER_STRING];
	Cliente* bufferClient;
	if(pFile!=NULL && clientList!=NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferCuit,bufferNombre,bufferApellido)==4)
			{
				bufferClient = cliente_newParametrosTxt(bufferId, bufferCuit, bufferNombre, bufferApellido);
				ll_add(clientList, bufferClient);
				retorno=0;
			}
			else
			{
				cliente_delete(bufferClient);
			}
		}while(feof(pFile)==0);
	}
    return retorno;
}
/*
 * \brief __sellFromText: Parse the sell data from the file in text mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* sellList:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Cliente* is NULL \ (0) OK
 */
int parser_sellFromText(FILE* pFile , LinkedList* sellList)
{
	int retornar=-1;
	char bufferIdCliente[BUFFER_STRING];
	char bufferIdVenta[BUFFER_STRING];
	char bufferCantidadAfiches[BUFFER_STRING];
	char bufferNombreArchivo[BUFFER_STRING];
	char bufferZona[BUFFER_STRING];
	char bufferEstadoVenta[BUFFER_STRING];
	Venta* bufferVenta;
	if(pFile!=NULL && sellList!=NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferIdCliente, bufferIdVenta,bufferCantidadAfiches,bufferNombreArchivo,bufferZona, bufferEstadoVenta)==6)
			{
				bufferVenta = venta_newParametrosTxt(bufferIdCliente, bufferIdVenta, bufferCantidadAfiches, bufferNombreArchivo, bufferZona, bufferEstadoVenta);
				ll_add(sellList, bufferVenta);
				retornar=0;
			}
			else
			{
				venta_delete(bufferVenta);
			}
		}while(feof(pFile)==0);
	}
    return retornar;
}

