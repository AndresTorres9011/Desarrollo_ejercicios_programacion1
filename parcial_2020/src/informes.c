/*
 * informes.c
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "publicaciones.h"
#include "informes.h"

#define TRUE 1
#define FALSE 0

/**
 * \brief Function to print each ad that a client has (searched by ID)
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Advertisement *adList: Pointer to an Advertisement array
 * \param int adLen: Length of the array
 * \param int id: receive the ID to be search
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int info_printAdsByClientID(Cliente *clientList, int clientLen, Publicacion *adList, int adLen, int id)
{
	int retorno=-1;
	int clientIndex;
	if(clientList!=NULL && clientLen>0 && adList!=NULL && adLen>0 && id>0)
	{
		if(cliente_findById(clientList, clientLen,&clientIndex ,id)==0)
		{
			printf("\nID cliente: %d - Nombre: %s - Apellido: %s - CUIT: %s", clientList[clientIndex].idCliente, clientList[clientIndex].nombre, clientList[clientIndex].apellido, clientList[clientIndex].cuit);
			if(publicacion_findByClientId(adList, adLen, clientList[clientIndex].idCliente)==0)
			{
				for(int i=0;i<adLen;i++)
				{
					if(adList[i].idCliente==clientList[clientIndex].idCliente)
					{
						printf("\n> > > ID publicacion: %d - Estado: %d - texto: %s",adList[i].id, adList[i].isActive, adList[i].texto);
					}
				}
			}
			else
			{
				printf(" y no tiene anuncios");
			}
			retorno=0;
		}
		else
		{
			printf("\nCliente no encontrado");
		}
	}
	return retorno;
}

/**
 * \brief Function to print clients and how many active ads has
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Advertisement *adList: Pointer to an Advertisement array
 * \param int adLen: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int info_printActive(Cliente *clientList, int clientLen, Publicacion *adList, int adLen)
{
	int retornar = -1;
	int adCounter;
	if(clientList!=NULL && clientLen>0 && adList!=NULL && adLen>0)
	{
		for(int i=0;i<clientLen;i++)
		{
			if(clientList[i].isEmpty == FALSE && publicacion_counterActiveClient(adList, adLen, clientList[i].idCliente, &adCounter)==0)
			{
				printf("\nID cliente: %d - Nombre: %s - Apellido: %s - CUIT: %s - Cantidad de anuncios activos: %d", clientList[i].idCliente, clientList[i].nombre, clientList[i].apellido, clientList[i].cuit, adCounter);
				retornar=0;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to report the client with more ads, how many paused ads are and the sector number with more ads
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Advertisement *adList: Pointer to an Advertisement array
 * \param int adLen: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int info_report(Cliente *clientList, int clientLen, Publicacion *adList, int adLen)
{
	int retornar = -1;
	int option;
	int adsCounter;
	if(clientList!=NULL && clientLen>0 && adList!=NULL && adLen>0  && publicacion_searchForNoEmpty(adList, adLen)==0)
	{
		do
		{
			if(utn_getNumeroString("\n\n  1-Cliente con mas avisos\n  2-Cantidad de avisos pausados\n  3-Rubro con mas avisos\n  4-Salir \n  Opcion:", "\nERROR! Elija una opcion valida", &option, 2, 1, 4)==0)
			{
				switch(option)
				{
				case 1:
					if(info_clientMax(clientList, clientLen, adList, adLen)==0)
					{
						retornar=0;
					}
				break;
				case 2:
					if(publicacion_counterPaused(adList, adLen, &adsCounter)==0)
					{
						printf("\nCantidad de avisos pausados: %d\n", adsCounter);
						retornar=0;
					}
					else
					{
						printf("\nNo hay avisos pausados\n");
					}
				break;
				case 3:
					if(publicacion_rubroMax(adList, adLen)==0)
					{
						retornar=0;
					}
					else
					{
						printf("\nNo hay rubros cargados\n");
					}
				break;
				}
			}
		}while(option != 4);
	}
	return retornar;
}

/**
 * \brief Function to find the client with more ads quantity
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Advertisement *adList: Pointer to an Advertisement array
 * \param int adLen: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int info_clientMax(Cliente *clientList, int clientLen, Publicacion *adList, int adLen)
{
	int retornar=-1;
	int currentCounter;
	int maxCounter;
	int index;
	Cliente bufferMax;
	if(clientList!=NULL && clientLen>0 && adList!=NULL && adLen>0)
	{
		for(int i=0;i<clientLen;i++)
		{
			publicacion_counterClient(adList, adLen, clientList[i].idCliente, &currentCounter);
			if(i==0 || currentCounter>maxCounter)
			{
				maxCounter = currentCounter;
				bufferMax = clientList[i];
			}
		}
		if(cliente_findById(clientList, clientLen,&index,bufferMax.idCliente)==0)
		{
			printf("\nEl cliente con mas avisos es: %s %s, CUIT: %s\n", clientList[index].nombre, clientList[index].apellido, clientList[index].cuit);
			retornar = 0;
		}
	}
	return retornar;
}

