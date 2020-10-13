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
#include "pantalla.h"

#define TRUE 1
#define FALSE 0
#define MIN_SALARY 1
#define MAX_SALARY 100000
#define MIN_SECTOR 1
#define MAX_SECTOR 10
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999
#define PANTALLA_TIPO_LED 0
#define PANTALLA_TIPO_LCD 1


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
int pantalla_init(Pantalla* list, int len)
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
int pantalla_searchEmpty(Pantalla* list, int len, int *pIndex)
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
	static int idPantalla=0; // es global para solo la fn puede usarla

	//guarda el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	idPantalla = idPantalla+1;
	return idPantalla;
}
/**
 * \brief _createNew: Create a new profile asking data to the user.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param (define struct) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int pantalla_createNew(Pantalla * list, int len)
{
	int retorno = -1;
	int indice;
	Pantalla buffer;
	if (list != NULL && len >0)
	{
		if (pantalla_searchEmpty(list,len,&indice) == 0)
		{
			if (utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getAlfanumerico("\n  Ingrese Direccion?","\n  Error no es una direccion valida",buffer.address,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getNumeroString("\n  Ingrese tipo de pantalla (0-LED o 1-LCD)?","\n  Error no es un numero valido",&buffer.pantallaType,CANTIDAD_REINTENTOS,0,1)==0 &&
				utn_getNumeroFloat("\n  Ingrese precio por dia?","\n  Error no es un numero valido",&buffer.pricePerDay,CANTIDAD_REINTENTOS,MIN_SALARY,MAX_SALARY)==0)
			{
				buffer.idPantalla= newIdGenerate();
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
int pantalla_findById(Pantalla* list, int len, int* pIndex, int idPantalla)
{
    int retorno = -1;
    //*pIndex = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if(list[i].idPantalla == idPantalla)
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
int pantalla_printById(Pantalla* list, int len, int index)
{
	int retorno = -1;
	char strTipo[8];
	if(list!= NULL && len > 0 && index < len)
	{
		if(list[index].isEmpty == FALSE)
		{
			if (list[index].pantallaType == PANTALLA_TIPO_LCD)
			{
				strncpy(strTipo,"LCD",8);
			}
			else
			{
				strncpy(strTipo,"LED",8);
			}
			printf("\n  -IDP: %d -Tipo de pantalla: %s -Nombre: %s -Direccion: %s  -Precio por dia: %.2f",
					list[index].idPantalla,strTipo,list[index].name, list[index].address, list[index].pricePerDay);
			retorno = 0;
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
int pantalla_print(Pantalla* list, int len)
{
	int retorno = -1;
	char strTipo[8];
	if(list!= NULL && len > 0 )
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				if (list[i].pantallaType == PANTALLA_TIPO_LCD)
				{
					sprintf(strTipo,"LCD");
				}
				else
				{
					sprintf(strTipo,"LED");
				}
				printf("\n  -IDp: %d -Tipo de pantalla: %s -Nombre: %s -Direccion: %s  -Precio por dia: %.2f",
						list[i].idPantalla,strTipo,list[i].name, list[i].address, list[i].pricePerDay);
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
int pantalla_modifify(Pantalla list[],int len)
{
	int retorno = -1;
	int idModificar;
	int index;
	Pantalla buffer;
	if(list != NULL && len>0)
	{
		pantalla_print(list,QTY_SCREEN);
		if(utn_getNumeroString("\n\n  Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
									,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
		{
		   if(pantalla_findById(list,QTY_SCREEN,&index,idModificar)==0)
		   {
				if(utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
						utn_getAlfanumerico("\n  Ingrese Direccion?","\n  Error no es una direccion valida",buffer.address,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
						utn_getNumeroString("\n  Ingrese tipo de pantalla (0-LED o 1-LCD)?","\n  Error no es un numero valido",&buffer.pantallaType,CANTIDAD_REINTENTOS,0,1)==0 &&
						utn_getNumeroFloat("\n  Ingrese precio por dia?","\n  Error no es un numero valido",&buffer.pricePerDay,CANTIDAD_REINTENTOS,MIN_SALARY,MAX_SALARY)==0)
				{
					//bufferAlumno.isEmpty = FALSE;
					buffer.idPantalla= list[index].idPantalla; //generarIdNuevo(); // NOOOOOOOOO
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
int pantalla_remove(Pantalla* list,int len )
{
	int retorno = -1;
	int idBaja;
	int index;

	if(list != NULL && len>0)
	{
		pantalla_print(list,QTY_SCREEN);
		if(utn_getNumeroString("\n\n  Ingrese el ID a dar de baja:","  Error Reingrese el ID a dar de baja!"
								 ,&idBaja,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(pantalla_findById(list,QTY_SCREEN,&index,idBaja)==0)
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
 * \brief _sortByLastName: Sort the list by ascendent (0) or descendent(1), the argument order
                indicate UP or DOWN order
 * \param (define struct) *list: Pointer to the array.
 * \param int len: Length of the array.
 * \param int order: Number indicating the order of the list.
 * \return (-1) if Error, (0)  if Ok
 */
int pantalla_sortByLastName(Pantalla* list, int len, int order)
{
	int retorno=-1;
	Pantalla swap;
    int flagEstadoDesordenado=1;

    if(list!=NULL && len>0 && (order == 1 || order == 0))
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if((order == 1 && (strncmp(list[i].name, list[i + 1].name,SIZE_NAME)>0 ||
					  (strncmp(list[i].name, list[i + 1].name,SIZE_NAME)==0 &&
					   strncmp(list[i].address, list[i + 1].address,SIZE_NAME)>0))) ||
					  (order == 0 &&(strncmp(list[i].name, list[i + 1].name,SIZE_NAME)<0 ||
					  (strncmp(list[i].name, list[i + 1].name,SIZE_NAME)==0 &&
					   strncmp(list[i].address, list[i + 1].address,SIZE_NAME)<0))))
				{
					swap = list[i];
					list[i] = list[i + 1];
					list[i + 1] = swap;
					flagEstadoDesordenado = 1;
				}
			}
		}
    	retorno=0;
    }
	return retorno;
}
/**
 * \brief _sortBySector: Sort the list by ascendent (0) or descendent(1), the argument order
                indicate UP or DOWN order
 * \param (define struct) *list: Pointer to the array.
 * \param int len: Length of the array.
 * \param int order: Number indicating the order of the list.
 * \return (-1) if Error, (0)  if Ok
 */
int pantalla_sortBySector(Pantalla *list, int len, int order)
{
	int retorno = -1;
	Pantalla auxSwap;
	int flagEstadoDesordenado=1;
	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		do
		{
			flagEstadoDesordenado=0;
			// la pasadita
			for(int i=0; i<len-1; i++)
			{
				if( (order == 1 && list[i].pricePerDay > list[i+1].pricePerDay)
						||
					(order == 0 && list[i].pricePerDay < list[i+1].pricePerDay))//aca establezco por que criterio quiero ordenar
				{
					auxSwap = list[i];
					list[i] = list[i+1];
					list[i+1] = auxSwap;
					flagEstadoDesordenado=1;
					retorno = 0;
				}
			}
		}while(flagEstadoDesordenado==1);// no esta ordenado
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
int pantalla_countId(Pantalla* list,int len,int* quantityId)
{
	int retorno=-1;
	int counterId=0;
	int i;

	if(list!=NULL && len>0 && quantityId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].idPantalla>0)
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
int pantalla_altaForzada(Pantalla * list, int len, char* name,char* address,int pantallaType,float pricePerDay)
{
	int retorno = -1;
	int indice;
	Pantalla buffer;
	if (list != NULL && len >0 && name!=NULL && address!=NULL)
	{
		if(pantalla_searchEmpty(list,len,&indice) == 0)
		{
				strncpy(buffer.name,name,SIZE_NAME);
				strncpy(buffer.address,address,SIZE_NAME);
				buffer.pricePerDay=pricePerDay;
				buffer.pantallaType=pantallaType;
				buffer.idPantalla= newIdGenerate();
				list[indice] = buffer;
				list[indice].isEmpty = FALSE;
				retorno=0;
	    }
	}
	return retorno ;
}
