/*
 * publicaciones.c
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include "publicaciones.h"
#include "cliente.h"
#include "informes.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define MIN_RUBRO 1
#define MAX_RUBRO 10
#define MIN_ID 0
#define MAX_ID 999
#define CANTIDAD_REINTENTOS 3

static int idGenerate(void);

/**
 * \brief Function to add an Publicacion asking for the client ID, sector number, and the ad text
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Publicacion array length
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \return (-1) if something went wrong, (0) if everything is OK.
 */
int publicacion_add(Publicacion *list, int len, Cliente *clientList, int clientLen)
{
	int retornar = -1;
	Publicacion buffer;
	int index;
	int clientIndex;
	if(list != NULL && len > 0 && cliente_searchEmpty(clientList,clientLen, &index) == 0)
	{
		if(publicacion_searchEmpty(list, len, &index) == 0 && index >= 0 && cliente_printAll(clientList, clientLen) == 0 &&
		   utn_getNumeroString("\n\nIngrese el ID del cliente: ", "\nERROR! Ingrese un ID valido: ",&buffer.idCliente, CANTIDAD_REINTENTOS,MIN_ID,MAX_ID)==0 &&
		   cliente_findById(clientList, clientLen,&clientIndex,buffer.idCliente) == 0 &&
		   utn_getNumeroString("\nIngrese el numero de rubro: ", "\nERROR! Ingrese un numero de rubro valido: ",&buffer.rubro, CANTIDAD_REINTENTOS, MIN_RUBRO, MAX_RUBRO)==0 &&
		   utn_getAlfanumerico("\nIngrese el texto del aviso: ", "\nERROR! Ingrese caracteres validos: ",buffer.texto,CANTIDAD_REINTENTOS, SIZE_TEXT)==0)
		{
			buffer.id = idGenerate();
			buffer.isEmpty = FALSE;
			buffer.isActive = TRUE;
			list[index] = buffer;
			retornar = 0;
			printf("\nID para el nuevo aviso: %d", list[index].id);
		}
	}
	return retornar;
}

/**
 * \brief Function pause an publicacion searched by ID (put isActive field on FALSE)
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \return (-1) if something went wrong, (0) if everything is OK.
 */

int publicacion_pause(Publicacion *list, int len, Cliente *clientList, int clientLen)
{
	int retornar = -1;
	int id;
	int index;
	int option;
	if(list != NULL && len > 0 && clientList != NULL && clientLen>0 && publicacion_searchForNoEmpty(list, len) == 0 && publicacion_searchForActive(list, len) == 1)
	{
		publicacion_print(list, len);
		if(utn_getNumeroString("\n\nIngrese el id de la publicacion a pausar: ", "\nError! Ingrese un ID valido: ", &id, CANTIDAD_REINTENTOS, MIN_ID,MAX_ID) == 0 && publicacion_findById(list, len, id, &index)==0 &&
		   list[index].isActive == TRUE && publicacion_printClientById(list, len, clientList, clientLen, id) == 0 &&
		   utn_getNumeroString("\n\nQuiere pausar esta publicidad? (1-SI O 2-NO): " , "\nERROR! Ingrese 1 o 2 ", &option, CANTIDAD_REINTENTOS, 1, 2)==0 && option == 1)
		{
			list[index].isActive = FALSE;
			retornar = 0;
		}
	}
	return retornar;
}

/**
 * \brief Function reanude an publicacion searched by ID (put isActive field on TRUE)
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \return (-1) if something went wrong, (0) if everything is OK.
 */
int publicacion_reanude(Publicacion *list, int len, Cliente *clientList, int clientLen)
{
	int retornar = -1;
	int id;
	int index;
	int option;
	if(list != NULL && len > 0 && clientList != NULL && clientLen>0 && publicacion_searchForNoEmpty(list, len) == 0 && publicacion_searchForActive(list, len) == 0)
	{
		publicacion_print(list, len);
		if(utn_getInt("\nIngrese el id de la publicacion a reanudar: ", "\nError! Ingrese un ID valido: ", &id,CANTIDAD_REINTENTOS, MIN_ID,MAX_ID) == 0 && publicacion_findById(list, len, id, &index)==0 &&
		   list[index].isActive == FALSE && publicacion_printClientById(list, len, clientList, clientLen, id) == 0 &&
		   utn_getInt("\n\nQuiere reanudar esta publicidad? presione 1 para SI o 2 para NO: ", "\nERROR! Ingrese 1 o 2 ", &option,CANTIDAD_REINTENTOS, 1, 2)==0 && option == 1)
		{
			list[index].isActive = TRUE;
			retornar = 0;
		}
	}
	return retornar;
}

/**
 * \brief Function to remove an publicacion searched by ID
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int id: receive the ID to be search
 * \return (-1) if something went wrong, (0) if everything is OK
*/
int publicacion_remove(Publicacion *list, int len, int id)
{
	int retornar = -1;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(publicacion_findByClientId(list, len, id)>-1)
			{
				list[i].isEmpty = TRUE;
			}
		}
		retornar = 0;
	}
	return retornar;
}

/**
 * \brief Function to print a client info searched by an publicacion ID
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param Client *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param int id: receive the ID to be search
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_printClientById(Publicacion *list, int len, Cliente *clientList, int clientLen, int id)
{
	int retornar=-1;
	int index;
	if(list!=NULL && len>0 && clientList!=NULL && clientLen>0 && clientLen>0 && id>0 && cliente_findById(clientList, len,&index, id)==0)
	{
		printf("\nCliente: \nNombre: %s - Apellido: %s - Cuit: %s", clientList[index].nombre, clientList[index].apellido, clientList[index].cuit);
		retornar = 0;
	}
	return retornar;
}


/**
 * \brief Function to print all the Publicacions in the array
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_print(Publicacion *list, int len)
{
	int retorno = -1;
	char strEstado[8];
	if(list != NULL && len > 0)
	{

		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				if (list[i].isActive == TRUE)
				{
					strncpy(strEstado,"ACTIVA",8);
				}
				else
				{
					strncpy(strEstado,"PAUSADA",8);
				}
				printf("\nID: %d - Estado: %s - texto: %s",list[i].id,strEstado,list[i].texto);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Function to count how many ads has a client searched by ID
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int id: receive the ID to be search
 * \param int *pCounter: Pointer of the counter
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_counterClient(Publicacion *adList, int adLen, int id, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(adList!=NULL && adLen>0)
	{
		for(int i=0;i<adLen;i++)
		{
			if(adList[i].idCliente == id)
			{
				counter++;
			}
		}
		*pCounter = counter;
		retornar = 0;
	}
	return retornar;
}

/**
 * \brief Function to count how many active ads has a client searched by ID
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int id: receive the ID to be search
 * \param int *pCounter: Pointer of the counter
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_counterActiveClient(Publicacion *adList, int adLen, int id, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(adList!=NULL && adLen>0)
	{
		for(int i=0;i<adLen;i++)
		{
			if(adList[i].idCliente == id && adList[i].isActive == TRUE)
			{
				counter++;
			}
		}
		*pCounter = counter;
		retornar = 0;
	}
	return retornar;
}

/**
 * \brief Function to count how many paused ads have an Publicacion array
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int *pCounter: Pointer of the counter
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_counterPaused(Publicacion *adList, int adLen, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(adList!=NULL && adLen>0)
	{
		for(int i=0;i<adLen;i++)
		{
			if(adList[i].isActive == FALSE)
			{
				counter++;
				retornar=0;
			}
		}
		*pCounter = counter;
	}
	return retornar;
}

/**
 * \brief Function to search in the publicacion array for an no empty field
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_searchForNoEmpty(Publicacion *list, int len)
{
	int retornar = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to search in the publicacion array if there's any active
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return (1) is there any active field TRUE or (0) if not
 */
int publicacion_searchForActive(Publicacion *list, int len)
{
	int retornar = 0;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isActive == TRUE)
			{
				retornar = 1;
				break;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to init isEmpty to TRUE and -1 to ID field of an Publicacion array
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_init(Publicacion* list, int len)
{
	int retornar = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].isActive = -1;
			list[i].id = -1;
		}
		retornar = 0;
	}
	return retornar;
}

/**
 * \brief Function that returns the first index found on an Publicacion array that is empty
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int *pIndex: pointer of the index
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_searchEmpty(Publicacion *list, int len, int *pIndex)
{
	int retornar = -1;
	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].id == -1)
			{
				retornar = 0;
				*pIndex = i;
				break;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to auto-generate an ID
 * \return the id
 */
static int idGenerate(void)
{
	static int id=0;
	id = id+1;
	return id;
}

/**
 * \brief Function to find an Publicacion index receiving an id
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int id: receive the id to be searched
 * \return the index or (-1) if something went wrong
 */
int publicacion_findById(Publicacion *list, int len, int id, int *pIndex)
{
	int retornar = -1;
	if(list != NULL && len > 0 && id > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==FALSE && (list[i].isActive==TRUE || list[i].isActive==FALSE))
			{
				*pIndex = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to find an Publicacion index receiving a client ID
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int id: receive the id to be searched
 * \return the index or (-1) if something went wrong
 */
int publicacion_findByClientId(Publicacion *list, int len, int id)
{
	int retornar = -1;
	if(list != NULL && len > 0 && id > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].idCliente==id && list[i].isEmpty==FALSE && (list[i].isActive==TRUE || list[i].isActive==FALSE))
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

/**
 * \brief Function to compare sectors counter and find the max
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return the index or (-1) if something went wrong
 */
int publicacion_rubroMax(Publicacion *list, int len)
{
	int retornar=-1;
	int currentCounter=0;
	int maxCounter;
	Publicacion aux;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && publicacion_equalRubro(list,len,list[i].rubro, &currentCounter)==0)
			{
				if(i==0 || currentCounter>maxCounter)
				{
					maxCounter = currentCounter;
					aux = list[i];
					retornar=0;
				}
			}
		}
		printf("\nEl rubro con mas avisos es el: %d\n", aux.rubro);
	}
	return retornar;
}

/**
 * \brief Function to count how many times a sector is repeated in the Publicacion array
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \param int sector: receive the sector to be searched
 * \param int *pCounter: pointer of the counter
 * \return the index or (-1) if something went wrong
 */
int publicacion_equalRubro(Publicacion *list, int len, int rubro, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].rubro == rubro)
			{
				counter++;
				retornar=0;
			}
		}
		*pCounter = counter;
	}
	return retornar;
}
int publicacion_altaForzada(Publicacion* list, int len,int idCliente,char* texto,int rubro)
{
	int retorno = -1;
	int indice;
	Publicacion buffer;
	if (list != NULL && len >0)
	{
		if(publicacion_searchEmpty(list,len,&indice) == 0)
		{
			    buffer.idCliente= idCliente;
				strncpy(buffer.texto,texto,SIZE_TEXT);
				buffer.rubro= rubro;
				buffer.id= idGenerate();
				list[indice] = buffer;
				list[indice].isEmpty = FALSE;
				list[indice].isActive =TRUE ;
				retorno=0;
	    }
	}
	return retorno ;
}
