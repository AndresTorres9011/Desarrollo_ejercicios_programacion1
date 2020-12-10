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
	int retorno=-1;
	int option;
	LinkedList* bufferAuxListaVenta = ll_subListFilter(listaVenta,venta_estaCobrada);
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		if( !utn_getNumber(&option,"\nIngrese una opcion:\n""1-Cliente al que se le vendio mas afiches\n"
						"2-Cliente al que se le vendio menos afiches\n""3-Venta con mas afiches vendidos\n"
						"4-Volver atras\n  Opcion: ","\nERROR!", 1, 4,CANTIDAD_REINTENTOS))
		{
			switch(option)
			{
			case 1:
				//if(!informe_clienteMasAfichesVendidos(listaCliente,bufferAuxListaVenta))
				if(!informe_clienteConMasAfichesVendidos(listaCliente,bufferAuxListaVenta))
				{
					retorno=0;
				}
			break;
			case 2:
				//if(!informe_clienteMenosAfichesVendidos(listaCliente, bufferAuxListaVenta))
				if(!informe_clienteConMenosAfichesVendidos(listaCliente, bufferAuxListaVenta))
				{
					retorno=0;
				}
			break;
			case 3:
				if(!informe_masAfichesVendidos(listaCliente, bufferAuxListaVenta))
				{
					retorno=0;
				}
			break;
			}
		}
	}
	return retorno;
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
int informe_masAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retorno=-1;
	int bufferCantidadAfiches;
	int maxAfiches;
	int bufferIdVenta;
	int bufferIdCliente;
	int clienteIndex;
	char bufferCuit[SIZE_CUIT];
	Venta* bufferVenta;
	Cliente* bufferCliente;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retorno=0;
		for(int i=0;i<ll_len(listaVenta);i++)
		{
			bufferVenta = ll_get(listaVenta, i);
			if(bufferVenta!=NULL && !venta_getCantidadAfiches(bufferVenta, &bufferCantidadAfiches))
			{
				if(i==0 || maxAfiches<bufferCantidadAfiches)
				{
					maxAfiches=bufferCantidadAfiches;
				}
			}
		}
		printf("\nVenta/s con mas afiches vendidos: \n");
		printf("\n%10s %15s\n","ID VENTA","CUIT CLIENTE");
		for(int i=0;i<ll_len(listaVenta);i++)
		{
			bufferVenta = ll_get(listaVenta, i);
			if(bufferVenta!=NULL && !venta_getCantidadAfiches(bufferVenta, &bufferCantidadAfiches))
			{
				if( bufferCantidadAfiches==maxAfiches && !venta_getIdCliente(bufferVenta, &bufferIdCliente) &&
					!venta_getIdVenta(bufferVenta, &bufferIdVenta))
				{
					clienteIndex=controller_findByIdCliente(listaCliente, bufferIdCliente);
					bufferCliente = ll_get(listaCliente, clienteIndex);
					if(bufferCliente!=NULL && !cliente_getCuit(bufferCliente, bufferCuit))
					{
						printf("\n%10d %15s\n", bufferIdVenta, bufferCuit);
					}
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief informe_clienteConMasAfichesVendidos: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informe_clienteConMasAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retorno=-1;
	int cantidadAfiches;
	int maxAfiches;
	int bufferClienteId;
	Cliente* bufferCliente;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retorno=0;
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferCliente = ll_get(listaCliente, i);
			if(bufferCliente!=NULL && !cliente_getId(bufferCliente, &bufferClienteId))
			{
				cantidadAfiches=ll_reduce(listaVenta,venta_acumularAfiches,bufferClienteId);
				if(cantidadAfiches>0)
				{
					if(i==0 || cantidadAfiches>maxAfiches)
					{
						maxAfiches = cantidadAfiches;
					}
				}
			}
		}
		printf("\nCliente/s con mas afiches vendidos: \n");
		headerClient();
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferCliente = ll_get(listaCliente, i);
			if(bufferCliente!=NULL && !cliente_getId(bufferCliente, &bufferClienteId))
			{
				cantidadAfiches=ll_reduce(listaVenta,venta_acumularAfiches,bufferClienteId);
				if(cantidadAfiches>0)
				{
					if(cantidadAfiches == maxAfiches)
					{
						//cliente_print(bufferClient);
						controller_printOneCliente(listaCliente, i);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief informe_clienteConmMenosAfichesVendidos: Function to print each ad that a client has (searched by ID).
 * \param Cliente *listUno: Pointer to  array.
 * \param int lenUno: Length of the array
 * \param Publicacion *listDos: Pointer to array.
 * \param int lenDos: Length of the array.
 * \param int id: receive the ID to be search.
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int informe_clienteConMenosAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retorno=-1;
	int cantidadAfiches;
	int minAfiches;
	int bufferClienteId;
	Cliente* bufferCliente;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retorno=0;
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferCliente = ll_get(listaCliente, i);
			if(bufferCliente!=NULL && !cliente_getId(bufferCliente, &bufferClienteId))
			{
				cantidadAfiches=ll_reduce(listaVenta,venta_acumularAfiches,bufferClienteId);
				if(cantidadAfiches>0)
				{
					if(i==0 || cantidadAfiches<minAfiches)
					{
						minAfiches = cantidadAfiches;
					}
				}
			}
		}
		printf("\nCliente/s con mas afiches vendidos: \n");
		headerClient();
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferCliente = ll_get(listaCliente, i);
			if(bufferCliente!=NULL && !cliente_getId(bufferCliente, &bufferClienteId))
			{
				cantidadAfiches=ll_reduce(listaVenta,venta_acumularAfiches,bufferClienteId);
				if(cantidadAfiches>0)
				{
					if(cantidadAfiches == minAfiches)
					{
						//cliente_print(bufferClient);
						controller_printOneCliente(listaCliente, i);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
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
int informe_clienteMasAfichesVendidos(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retorno=-1;
	int maxQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retorno=0;
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
		printf("\nCliente/s con mas afiches vendidos: \n");
		headerClient();
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta, venta_compararId, bufferClientId, &currentCounter))
			{
				if(currentCounter == maxQty)
				{
					//cliente_print(bufferClient);
					controller_printOneCliente(listaCliente, i);
				}
			}
		}
	}
	return retorno;
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
	int retorno=-1;
	int minQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	int i;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(listaCliente);i++)
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
		printf("\nCliente/s con menos afiches vendidos: \n");
		headerClient();
		for(int i=0;i<ll_len(listaCliente);i++)
		{
			bufferClient = ll_get(listaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(listaVenta,venta_compararId, bufferClientId, &currentCounter))
			{
				if(currentCounter == minQty)
				{
					//cliente_print(bufferClient);
					controller_printOneCliente(listaCliente, i);
				}
			}
		}
	}
	return retorno;
}
