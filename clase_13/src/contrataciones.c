/*
 * contratacion.c
 *
 *  Created on: 8/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contrataciones.h"
#include "pantalla.h"

#define TRUE 1
#define FALSE 0
#define MIN_CUIT 1
#define MAX_CUIT 999999999
#define MIN_DIAS 1
#define MAX_DIAS 1000
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999
#define PANTALLA_TIPO_LED 0
#define PANTALLA_TIPO_LCD 1
#define QTY_SCREEN 15
#define QTY_CONTRATACIONES 15
#define CANTIDAD_REINTENTOS 3
#define SIZE_CUIT 51


static int newIdGenerate(void);

/**
 * \brief _init: To indicate that all position in the array are empty,
*                this function put the flag (isEmpty) in TRUE in all
*                position of the array.
* \param (define struct)* list: Pointer to the array.
* \param int len:  Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int contratacion_init(Contratacion* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief _searchEmpty: Search in the array for the first index with TRUE in isEmpty.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */
int contratacion_searchEmpty(Contratacion* list, int len, int *pIndex)
{
	int retornar = -1;
	if(list != NULL && pIndex != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}
/* \brief newIdGenerate: Create a new id when the user load data (different id).
 *  \return id.
 */
static int newIdGenerate(void)
{
	static int idContratacion=0; // es global para solo la fn puede usarla

	//guarda el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	idContratacion = idContratacion+1;
	return idContratacion;
}
/**
 * \brief _createNew: Create a new profile asking data to the user.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param (define struct) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int contratacion_createNew(Contratacion * listUno, int lenUno,Pantalla* listDos,int lenDos)
{
	int retorno = -1;
	int indice;
	Contratacion buffer;
	if (listUno != NULL && lenUno >0 && listDos !=NULL && lenDos>0)
	{
		if (contratacion_searchEmpty(listUno,lenUno,&indice) == 0)
		{
			pantalla_print(listDos,lenDos);
			if (utn_getNumeroString("\n  Id de pantalla: ","\n  Error no es un numero valido",&buffer.idPantalla,CANTIDAD_REINTENTOS,1,1000)==0 &&
				pantalla_findById(listDos,QTY_SCREEN,&indice,buffer.idPantalla)==0 &&
			    utn_getNombre("\n  Nombre de Archivo: ","\n  Error no es un nombre valido",buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getCuit("\n  Cuit del cliente: ","\n  Error no es un cuit valido",buffer.cuitCliente,SIZE_CUIT,CANTIDAD_REINTENTOS,MIN_CUIT,MAX_CUIT) == 0 &&
				utn_getNumeroString("\n  Cantidad de dias: ","\n  Error no es un numero valido",&buffer.cantidadDias,CANTIDAD_REINTENTOS,MIN_DIAS,MAX_DIAS)==0)
			{
				buffer.idContratacion= newIdGenerate();
				listUno[indice] = buffer;
				listUno[indice].isEmpty = FALSE;
				retorno=0;
			}
			else
			{
				printf("  ERROR NO INGRESASTE DATOS VALIDOS");
			}
		}
		else
		{
			printf("\n  NO QUEDAN ESPACIOS LIBRES");
		}
	}
	return retorno ;
}
/**
 * \brief _findById: find  by Id.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to the memory  where write the value.
 * \param int id: Assigned id.
 * \return (-1) Error / (0) Ok
 *
 */
int contratacion_findById(Contratacion* list, int len, int* pIndex, int idContratacion)
{
    int retorno = -1;

    if (list != NULL && pIndex!= NULL && len > 0 && idContratacion>0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if(list[i].idContratacion == idContratacion)
                {
                   *pIndex = i;
                   retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
/**
 * \brief _printById: Print data by ID.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int contratacion_printById(Contratacion* list, int len, int index)
{
	int retorno = -1;
	if(list!= NULL && len > 0 && index < len)
	{
		if(list[index].isEmpty == FALSE)
		{
			printf("\n  -IDc: %d -Cuit Cliente: %s -Nombre Archivo: %s -Cantidad de Dias: %d",
					list[index].idContratacion,list[index].cuitCliente,list[index].name,list[index].cantidadDias);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief _findById: find  by Cuit.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to the memory  where write the value.
 * \param int id: Assigned id.
 * \return (-1) Error / (0) Ok
 *
 */
int contratacion_findByCuit(Contratacion* list, int len, int* pIndex, char* cuitCliente)
{
    int retorno = -1;

    if (list != NULL && pIndex!= NULL && len > 0 && cuitCliente>0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if(strncmp(list[i].cuitCliente,cuitCliente,SIZE_CUIT)==0)
                {
                   *pIndex = i;
                   retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
/**
 * \brief _print: Print the uploaded data.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int contratacion_print(Contratacion* list, int len,Pantalla * listDos , int lenDos)
{
	int retorno = -1;

	if(list!= NULL && len > 0 && listDos !=NULL && lenDos>0 )
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{

				printf("\n  -IDc: %d -Cuit Cliente: %s -Nombre Archivo: %s -Cantidad de Dias: %d  -IDp: %d" ,list[i].idContratacion,list[i].cuitCliente,list[i].name,list[i].cantidadDias,list[i].idPantalla);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief _imprimirContratacionesPorCuit: Print the uploaded data by cuit.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int contratacion_imprimirContratacionesPorCuit (Contratacion * list, int len, Pantalla * listDos , int lenDos,char* cuit)
{
	int retorno =-1;
	int indicePantalla;
	int idPantalla;
	char strTipo[8];
		if (list != NULL && len > 0 && listDos != NULL && lenDos>0)
		{
			for(int i = 0; i<len ; i++)
			{
				if (list[i].isEmpty == FALSE && strncmp(list[i].cuitCliente,cuit,SIZE_CUIT)==0)
				{
					if (listDos[i].pantallaType == PANTALLA_TIPO_LCD)
					{
						sprintf(strTipo,"LCD");
					}
					else
					{
						sprintf(strTipo,"LED");
					}
					retorno = 0;
					idPantalla= list[i].idPantalla;
					pantalla_findById(listDos, lenDos, &indicePantalla,idPantalla);
					printf("\n  -IDc: %d -Cuit: %s -Archivo: %s -Cantidad de Dias: %d  -IDp: %d" ,list[i].idContratacion,list[i].cuitCliente,list[i].name,list[i].cantidadDias,list[i].idPantalla);
					printf("-Tipo de pantalla: %s -Nombre: %s -Direccion: %s  -Precio por dia: %.2f",strTipo,listDos[indicePantalla].name,listDos[indicePantalla].address,listDos[indicePantalla].pricePerDay);

				}
			}
		}

	return retorno;
}
/**
 * \brief _modifify: Modify the data only if the index corresponds to a NO Empty
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int index: Is the index where it is loaded.
 * \return (-1) Error / (0) Ok
 *
 */
int contratacion_modifify(Contratacion* list,int len,Pantalla* listDos,int lenDos)
{
	int retorno = -1;
	char cuitBuscar[SIZE_CUIT];
	int indexbuscar;
	int idModificar;
	Contratacion buffer;
	if(list != NULL && len>0 && listDos !=NULL && lenDos>0)
	{
		if(!utn_getCuit("\n\n  Ingrese cuit a buscar:","  Error Reingrese cuit a modificar!",cuitBuscar,SIZE_CUIT,CANTIDAD_REINTENTOS,MIN_CUIT,MAX_CUIT) &&
				!contratacion_findByCuit(list,QTY_CONTRATACIONES,&indexbuscar,cuitBuscar))
		{
			contratacion_imprimirContratacionesPorCuit(list,len,listDos,lenDos,cuitBuscar);
			if(!utn_getNumeroString("\n\n  Ingrese el ID de contratacion a modificar:","  Error Reingrese el ID a modificar!"
										,&idModificar,CANTIDAD_REINTENTOS,1,1000))
			{
			   if(!contratacion_findById(list,QTY_CONTRATACIONES,&indexbuscar,idModificar) &&  strncmp(list[indexbuscar].cuitCliente,cuitBuscar,SIZE_CUIT)==0)
			   {if(utn_getCuit("\n  Cuit de cliente: ","\n  Error no es un cuit valido",buffer.cuitCliente,SIZE_CUIT,CANTIDAD_REINTENTOS,MIN_CUIT,MAX_CUIT) == 0 &&
				   utn_getNombre("\n  Nombre de Archivo: ","\n  Error no es un nombre valido",buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				   utn_getNumeroString("\n  Cantidad de dias: ","\n  Error no es un numero valido",&buffer.cantidadDias,CANTIDAD_REINTENTOS,MIN_DIAS,MAX_DIAS)==0 &&
				   utn_getNumeroString("\n  Id de pantalla: ","\n  Error no es un numero valido",&buffer.idPantalla,CANTIDAD_REINTENTOS,1,1000)==0)
					{
						//bufferAlumno.isEmpty = FALSE;
						buffer.idContratacion= list[indexbuscar].idContratacion; //generarIdNuevo(); // NOOOOOOOOO
						list[indexbuscar] = buffer;
						list[indexbuscar].isEmpty = FALSE;
						retorno = 0;
					}
			   }
			   else
			   {
					printf("\n  ID NO ENCONTRADO VERIFIQUE \n");
			   }
			}
		}
		else
		{
			printf("\n  CUIT INVALIDO VERIFIQUE  \n");
		}
	}
	return retorno;
}
/**
 * \brief _remove: Remove data by Id (put isEmpty Flag in 1)
 * \param  (define struct)* list: Pointer to the array.
 * \param int len: Length of the array
 * \param int index: is the position from which the data is deleted.
 * \return int Return (-1) if Error [Invalid length or NULL pointer o] - (0) if Ok
 *
 */
int contratacion_remove(Contratacion* list,int len,Pantalla* listDos,int lenDos)
{
	int retorno = -1;
	int idBaja;
	int index;
	char cuitBuscar[SIZE_CUIT];

	if(list != NULL && len>0)
	{
		if(!utn_getCuit("\n\n  Ingrese cuit a buscar:","  Error Reingrese cuit a modificar!",cuitBuscar,SIZE_CUIT,CANTIDAD_REINTENTOS,MIN_CUIT,MAX_CUIT) &&
						!contratacion_findByCuit(list,QTY_CONTRATACIONES,&index,cuitBuscar))
		{
			contratacion_imprimirContratacionesPorCuit(list,len,listDos,lenDos,cuitBuscar);
			if(!utn_getNumeroString("\n\n  Ingrese el ID de contratacion a cancelar: ","  Error Reingrese ID"
												,&idBaja,CANTIDAD_REINTENTOS,1,1000))
		    {
				if(contratacion_findById(list,QTY_SCREEN,&index,idBaja)==0 && strncmp(list[index].cuitCliente,cuitBuscar,SIZE_CUIT)==0)
				{
					if(list[index].isEmpty == FALSE)
					{
						//BAJA LOGICA DE ID
						list[index].isEmpty = TRUE;
						retorno = 0;
					}
				}
				else
			    {
					printf("\n  ID NO ENCONTRADO VERIFIQUE \n");
			    }
		    }
		}
		else
		{
			printf("\n  CUIT NO ENCONTRADO VERIFIQUE \n");
		}
	}
	return retorno;
}
/**
 * \brief _countId: Count the data you have registered.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length.
 * \paramfloat* quantityId:Pointer to the memory space where the result of the function will be left.
 * \return (-1) Error / (0) Ok
 */
int contratacion_countId(Contratacion* list,int len,int* quantityId)
{
	int retorno=-1;
	int counterId=0;
	int i;

	if(list!=NULL && len>0 && quantityId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].idContratacion>0)
			{
				counterId++;
				retorno=0;
			}
		}
	}
	*quantityId = counterId;
	return retorno;
}
/**
 * \brief _altaForzada: Create a new profile.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param (define struct) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int contratacion_altaForzada(Contratacion * listUno, int lenUno,Pantalla* listDos,int lenDos,int idPantalla,char* name,int cantidadDias,char* cuitCliente)
{
	int retorno = -1;
	int indice;
	Contratacion buffer;
	if (listUno != NULL && lenUno >0 && listDos !=NULL && lenDos>0)
	{
		if (contratacion_searchEmpty(listUno,lenUno,&indice) == 0)
		{
				buffer.idPantalla=idPantalla;
				strncpy(buffer.name,name,SIZE_NAME);
				buffer.cantidadDias=cantidadDias;
				strncpy(buffer.cuitCliente,cuitCliente,SIZE_CUIT);
				//buffer.cuitCliente=cuitCliente;
				buffer.idContratacion= newIdGenerate();
				listUno[indice] = buffer;
				listUno[indice].isEmpty = FALSE;

		}
		else
		{
			printf("\n  NO QUEDAN ESPACIOS LIBRES");
		}
	}
	return retorno ;
}
