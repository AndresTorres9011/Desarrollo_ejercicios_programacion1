/*
 * cliente.c
 *
 *  Created on: 13/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

#define TRUE 1
#define FALSE 0
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999
#define QTY_CLIENTES 100
#define QTY_PUBLICACIONES 10000


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
int cliente_init(Cliente* list, int len)
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
int cliente_searchEmpty(Cliente* list, int len, int *pIndex)
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
	static int idCliente=0; // es global para solo la fn puede usarla

	//guarda el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	idCliente = idCliente+1;
	return idCliente;
}
/**
 * \brief _createNew: Create a new profile asking data to the user.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param (define struct) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_createNew(Cliente * list, int len)
{
	int retorno = -1;
	int indice;
	Cliente buffer;
	if (list != NULL && len >0)
	{
		if (cliente_searchEmpty(list,len,&indice) == 0)
		{
			if (utn_getCuit("\n  Ingrese Cuit?","\n  Error no es un cuit valido",buffer.cuit,CANTIDAD_REINTENTOS,SIZE_CUIT) == 0 &&
				utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.nombre,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getNombre("\n  Ingrese Apellido?","\n  Error no es un apellido valido",buffer.apellido,CANTIDAD_REINTENTOS,SIZE_NAME) == 0)
			{
				buffer.idCliente= newIdGenerate();
				list[indice] = buffer;
				list[indice].isEmpty = FALSE;
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
int cliente_findById(Cliente* list, int len, int* pIndex, int id)
{
    int retorno = -1;

    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if(list[i].idCliente == id)
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
int cliente_printById(Cliente* list, int len, int index)
{
	int retorno = -1;
	if(list!= NULL && len > 0 && index < len)
	{
		if(list[index].isEmpty == FALSE)
		{
			printf("\n  -IDC: %d -Cuit de cliente: %s -Nombre: %s -Apellido: %s",
									list[index].idCliente,list[index].cuit,list[index].nombre, list[index].apellido);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief _printAll: Print the uploaded data.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int cliente_printAll(Cliente* list, int len)
{
	int retorno = -1;

	if(list!= NULL && len > 0 )
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n  -IDC: %d -Cuit de cliente: %s -Nombre: %s -Apellido: %s",
						list[i].idCliente,list[i].cuit,list[i].nombre, list[i].apellido);
				retorno = 0;
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
int cliente_modifify(Cliente list[],int len)
{
	int retorno = -1;
	int idModificar;
	int index;
	Cliente buffer;
	if(list != NULL && len>0)
	{
		cliente_printAll(list,QTY_CLIENTES);
		if(utn_getNumeroString("\n\n  Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
									,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
		{
		   if(cliente_findById(list,QTY_CLIENTES,&index,idModificar)==0)
		   {
				if(utn_getCuit("\n  Ingrese Cuit?","\n  Error no es un cuit valido",buffer.cuit,CANTIDAD_REINTENTOS,SIZE_CUIT) == 0 &&
					utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.nombre,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
					utn_getNombre("\n  Ingrese Apellido?","\n  Error no es un apellido valido",buffer.apellido,CANTIDAD_REINTENTOS,SIZE_NAME) == 0)
				{
					//bufferAlumno.isEmpty = FALSE;
					buffer.idCliente= list[index].idCliente; //generarIdNuevo(); // NOOOOOOOOO
					list[index] = buffer;
					list[index].isEmpty = FALSE;
					retorno = 0;
				}
	       }
		   else
		   {
				printf("\n  ID NO ENCONTRADO VERIFIQUE ID\n");
		   }
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
int cliente_remove(Cliente* list,int len )
{
	int retorno = -1;
	int idBaja;
	int index;

	if(list != NULL && len>0)
	{
		cliente_printAll(list,QTY_CLIENTES);
		if(utn_getNumeroString("\n\n  Ingrese el ID a dar de baja:","  Error Reingrese el ID a dar de baja!"
								 ,&idBaja,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(cliente_findById(list,QTY_CLIENTES,&index,idBaja)==0)
			{
				if(list[index].isEmpty == FALSE)
				{
					//BAJA LOGICA DE ID
					list[index].isEmpty = TRUE;
					retorno = 0;
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE ID\n");
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
int cliente_countId(Cliente* list,int len,int* quantityId)
{
	int retorno=-1;
	int counterId=0;
	int i;

	if(list!=NULL && len>0 && quantityId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].idCliente>0)
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
 * \brief_altaForzada: Create a new profile asking data to the user.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param (define struct) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_altaForzada(Cliente * list, int len,char*cuit, char* nombre,char* apellido)
{
	int retorno = -1;
	int indice;
	Cliente buffer;
	if (list != NULL && len >0 && cuit!=NULL && nombre!=NULL && apellido!=NULL)
	{
		if(cliente_searchEmpty(list,len,&indice) == 0)
		{
			    strncpy(buffer.cuit,cuit,SIZE_CUIT);
				strncpy(buffer.nombre,nombre,SIZE_NAME);
				strncpy(buffer.apellido,apellido,SIZE_NAME);
				buffer.idCliente= newIdGenerate();
				list[indice] = buffer;
				list[indice].isEmpty = FALSE;
				retorno=0;
	    }
	}
	return retorno ;
}


