/*
 * informes.c
 *
*  Created on: 25/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "clientes.h"
#include "utn.h"
#include "controller.h"
#include "ventas.h"
#include "informes.h"

/**
 * \brief info__report: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informes_report(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retornar=-1;
	int option;
	LinkedList* bufferAuxListaVenta = ll_subListFilter(listaVenta,venta_estaCobrada);
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		if( !utn_getNumber(&option,"\nIngrese una opcion:\n""1)Cliente al que se le vendio mas afiches\n"
						"2)Cliente al que se le vendio menos afiches\n""3)Venta con mas afiches vendidos\n"
						"4)Volver atras\n> > Opcion: ","\nERROR!", 1, 4,CANTIDAD_REINTENTOS))
		{
			switch(option)
			{
			case 1:
				if(informe_clienteMasAfichesVendidos(listaCliente, bufferAuxListaVenta))
				{
					retornar=0;
				}
			break;
			case 2:
				if(!informe_clienteMenosAfichesVendidos(listaCliente, bufferAuxListaVenta))
				{
					retornar=0;
				}
			break;
			case 3:
				if(!informe_masAfichesVendidos(listaCliente, bufferAuxListaVenta))
				{
					retornar=0;
				}
			break;
			}
		}
	}
	return retornar;
}
/**
 * \brief informe_clienteMasAfichesVendidos: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informe_clienteMasAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)//clientMaxPosterQty
{
	int retornar=-1;
	int maxQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta,venta_compararId, bufferClientId, &currentCounter))
			{
				if(i==0 || maxQty<currentCounter)
				{
					maxQty = currentCounter;
				}
			}
		}
		printf("\nEl cliente con mas afiches es: \n");
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta, venta_compararId, bufferClientId, &currentCounter))
			{
				if(currentCounter == maxQty)
				{
					cliente_print(bufferClient);
				}
			}
		}
	}
	return retornar;
}
/**
 * \brief informe_clienteMenosAfichesVendidos: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informe_clienteMenosAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retornar=-1;
	int minQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta, venta_compararId, bufferClientId, &currentCounter))
			{
				if(i==0 || minQty>currentCounter)
				{
					minQty = currentCounter;
				}
			}
		}
		printf("\nEl cliente con menos afiches es: \n");
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta,venta_compararId, bufferClientId, &currentCounter))
			{
				if(currentCounter == minQty)
				{
					cliente_print(bufferClient);
				}
			}
		}
	}
	return retornar;
}
/**
 * \brief informe_masAfichesVendidos: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informe_masAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)//sellMaxPosterQty
{
	int retornar=-1;
	int bufferPosterQty;
	int maxPosterQty;
	int bufferIdSell;
	int bufferIdClient;
	int clientIndex;
	char bufferCuit[SIZE_CUIT];
	Venta* bufferSell;
	Cliente* bufferClient;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(listaVenta);i++)
		{
			bufferSell = ll_get(listaVenta, i);
			if(bufferSell!=NULL && !venta_getCantidadAfiches(bufferSell, &bufferPosterQty))
			{
				if(i==0 || maxPosterQty<bufferPosterQty)
				{
					maxPosterQty=bufferPosterQty;
				}
			}
		}
		printf("\nLa venta con mas afiches vendidos es: \n");
		for(int i=0;i<ll_len(listaVenta);i++)
		{
			bufferSell = ll_get(listaVenta, i);
			if(bufferSell!=NULL && !venta_getCantidadAfiches(bufferSell, &bufferPosterQty))
			{
				if( bufferPosterQty==maxPosterQty && !venta_getIdCliente(bufferSell, &bufferIdClient) &&
					!venta_getIdVenta(bufferSell, &bufferIdSell))
				{
					clientIndex=controller_findByIdCliente(listaCliente, bufferIdClient);
					bufferClient = ll_get(listaCliente, clientIndex);
					if(bufferClient!=NULL && !cliente_getCuit(bufferClient, bufferCuit))
					{
						printf("\nID venta: %d - Cuit cliente: %s", bufferIdSell, bufferCuit);
					}
				}
			}
		}
	}
	return retornar;
}
