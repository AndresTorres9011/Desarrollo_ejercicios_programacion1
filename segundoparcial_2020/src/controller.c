/*
 * controller.c
 *
 *  Created on: 25/11/2020
 *      Author: Vivi Herrera
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


static int findMaxId(LinkedList* pArrayListCliente);
static int generateNewId(LinkedList* pArrayListCliente);
static int findMaxIdVenta(LinkedList* pArrayListVenta);
static int generateNewIdVenta(LinkedList* pArrayListVenta);
/*--------------------------------------------------------CLIENTES---------------------------------------------------------------------------------*/

/**
 * \brief findMaxId: Search max id.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return id if OK/ (-1) Error
 */
static int findMaxId(LinkedList* pArrayListCliente)
{

	Cliente* pCliente;
	int len;
	int i;
	int max;
	int id = -1;

	if(pArrayListCliente != NULL)
	{
		len = ll_len(pArrayListCliente);
		for(i=0;i<len;i++)
		{
			pCliente = ll_get(pArrayListCliente,i);
			cliente_getId(pCliente,&id);
			if (i == 0 || id > max)
			{
				max = id;
			}
		}
		id = max;

	}
	return id;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewId(LinkedList* pArrayListCliente)
{
    static int id = -1;
    static int flag = 1;

    if(pArrayListCliente != NULL)
    {
		if(flag == 1)
		{
			id = findMaxId(pArrayListCliente);
			flag++;
		}
		id++;
    }
    return id;
}
/**
 * \brief _loadClienteFromText: Carga los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param char* path: File address..
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadClientFromText(char* path, LinkedList* clientList)
{
	int retornar=-1;
	FILE* pFile;
	if(path!=NULL && clientList!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_clientFromText(pFile, clientList))
		{
			retornar=0;
		}
		else
		{
			printf("\nEl archivo no existe");
		}
		fclose(pFile);
	}
    return retornar;
}
/**
 * \brief _addCliente: Create a new profile asking data to the user.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	Cliente* pCliente;
	Cliente buffer;

	if (pArrayListCliente != NULL)
	{
		pCliente = cliente_new();
		if(pCliente != NULL && !utn_getCuit("\nIngrese cuit: ","Error",buffer.cuit,CANTIDAD_REINTENTOS,SIZE_CUIT) &&
		   !controller_findByCuit(pArrayListCliente,buffer.cuit) &&
		   !utn_getName(buffer.nombre,sizeof(buffer.nombre),"\nIngrese nombre: ","Error", CANTIDAD_REINTENTOS) &&
		   !utn_getName(buffer.apellido,NOMBRE_LEN, "\nIngrese nuevo apellido: ", "\nError!",CANTIDAD_REINTENTOS))
		{
			buffer.id = generateNewId(pArrayListCliente);
			if (!cliente_setCuit(pCliente, buffer.cuit) &&
				!cliente_setNombre(pCliente, buffer.nombre) &&
				!cliente_setApellido(pCliente, buffer.apellido) &&
			    !cliente_setId(pCliente,buffer.id))
			{
				retorno = ll_add(pArrayListCliente, pCliente);
				printf("\nID para el nuevo cliente: %d\n", buffer.id);
			}
		}
		else
		{
			printf("\nCUIT EXISTENTE EN SISTEMA VERIFIQUE");
		}
	}
	return retorno;
}
/**
 * \brief _findById: find the position in the array searched by Id.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param int id: Id received to search position.
 * \\return int indice encontrado if OK o (-1) si el puntero a LikedList es NULL, id invalido o cliente no encontrado
 */
int controller_findById(LinkedList* pArrayListCliente, int id)
{
	int retorno = -1;
	int i;
	int bufferId;
	int len;
	Cliente* pCliente;

	if (pArrayListCliente != NULL && id > 0)
	{
		len = ll_len(pArrayListCliente);
		for (i = 0; i < len; i++)
		{
			pCliente = (Cliente*)ll_get(pArrayListCliente,i);
			if (pCliente != NULL && !cliente_getId(pCliente,&bufferId) && bufferId == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief _findByCuit: find position in the array by Cuit.
 * \param (Cliente)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to the memory  where write the value.
 * \param char* cuitCliente: Assigned cuit.
 * \return (-1) Error / (0) Ok
 */
int controller_findByCuit(LinkedList* clientList, char* cuit)
{
	int retorno=-1;
	Cliente* bufferClient;
	char bufferCuit[SIZE_CUIT];
	if(clientList!=NULL && cuit!=NULL)
	{
		retorno=0;
		for(int i=0;i<ll_len(clientList);i++)
		{
			bufferClient = ll_get(clientList, i);
			if(bufferClient!=NULL && !cliente_getCuit(bufferClient, bufferCuit))
			{
				if(!strncmp(bufferCuit, cuit,SIZE_CUIT))
				{
					retorno=1;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief _editCliente: Modify the data of an cliente.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return Return(-1) Error / Return(0) Ok
 */
int controller_editCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	Cliente* pCliente;
	Cliente buffer;
	int index;
	int option;

	if (pArrayListCliente != NULL)
	{
		if (!controller_ListCliente(pArrayListCliente) && !utn_getNumber(&buffer.id, "\nIngrese el id del cliente que quiere modificar: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS))
		{
			index = controller_findById(pArrayListCliente, buffer.id);
			if (index != -1)
			{
				pCliente = (Cliente*) ll_get(pArrayListCliente, index);
				if (pCliente != NULL)
				{
					do {
						if (!utn_getNumber(&option, "\n\n1.Modificar Cuit \n2.Modificar Nombre "
								"\n3.Modificar Apellido \n4.Volver al menu principal\n \n Opcion:","Error, elija una opcion valida\n", 1, 4, CANTIDAD_REINTENTOS))
						{
							switch (option)
							{
							case 1:
								if (!utn_getCuit("\nIngrese nuevo cuit: ", "\nError!",buffer.cuit,CANTIDAD_REINTENTOS,SIZE_CUIT))
								{
									cliente_setCuit(pCliente,buffer.cuit);
									printf("\nMODIFICACION DE CUIT OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO CUIT\n");
								}
							break;
							case 2:
								if (!utn_getName(buffer.nombre, NOMBRE_LEN, "\nIngrese nuevo nombre: ", "\nError!", CANTIDAD_REINTENTOS))
								{
									cliente_setNombre(pCliente,buffer.nombre);
									printf("\nMODIFICACION DE NOMBRE OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO NOMBRE\n");
								}
							break;
							case 3:
								if (!utn_getName(buffer.apellido,NOMBRE_LEN, "\nIngrese nuevo apellido: ", "\nError!",CANTIDAD_REINTENTOS))
								{
									cliente_setApellido(pCliente, buffer.apellido);
									printf("\nMODIFICACION DE APELLIDO OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO EL APELLIDO\n");
								}
							break;
							}
						}
						else
						{
							printf("\nSE QUEDO SIN INTENTOS, REGRESANDO A MENU ANTERIOR\n");
						}
						if (retorno < 0)
						{
							break;
						}
					} while (option != 4);
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE\n");
		}
	}
	return retorno;
}
/**
 * \brief _removeCliente: Remove data by Id.
 * \param  LinkedList* pArrayListCliente: Pointer to the array.
 * \return int Return (-1) if Error [Invalid length or NULL pointer o] - Return (0) if Ok
 */

int controller_removeCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int index;
	int bufferId;
	Cliente* pCliente;
	char bufferAnswer[10];

	if (pArrayListCliente != NULL)
	{
		if (!controller_ListCliente(pArrayListCliente)
			&& !utn_getNumber(&bufferId , "\nIngrese el id del cliente que quiere eliminar: ", "\nError!",MIN_ID,MAX_ID,CANTIDAD_REINTENTOS))
		{
			index = controller_findById(pArrayListCliente, bufferId);
			if(index != -1)
			{
				pCliente = (Cliente*)ll_get(pArrayListCliente, index);
				if (pCliente != NULL
						&& !utn_getName(bufferAnswer, 10, "\n\nConfirma Borrado? Ingrese 'Si' para proceder con la baja: ",
								"\nError ingrese una respuesta valida.",CANTIDAD_REINTENTOS) && strncasecmp(bufferAnswer,"si", 10) == 0)
				{
					cliente_delete(pCliente);
					retorno = ll_remove(pArrayListCliente,index);
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE\n");
		}

	}
	return retorno;
}
/**
 * \brief _ListCliente: Print all the uploaded data.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_ListCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int len= ll_len(pArrayListCliente);
    int i;

    if(pArrayListCliente != NULL)
    {
    	printf("\n%10s %15s %15s %15s\n","ID","CUIT","NOMBRE","APELLIDO\n");
    	for(i=0;i<len;i++)
    	{
    		retorno = controller_printOneCliente(pArrayListCliente,i);
    	}
    }
	return retorno;
}
/**
 * \brief _printOneCliente: Print data by index.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param int index: Is the data position in the array.
 * \return (-1) Error / (0) Ok
 */
int controller_printOneCliente(LinkedList* pArrayListCliente, int index)
{
	int retorno = -1;
	Cliente buffer;
	Cliente* pCliente;

	if(pArrayListCliente != NULL && index >= 0)
	{
		pCliente = (Cliente*)ll_get(pArrayListCliente,index);
		if(	pCliente != NULL && !cliente_getId(pCliente,&buffer.id) &&
			!cliente_getCuit(pCliente,buffer.cuit) &&
			!cliente_getNombre(pCliente,buffer.nombre) &&
		    !cliente_getApellido(pCliente,buffer.apellido) )
		{
			printf("\n%10d %15s %15s %15s\n",buffer.id,buffer.cuit,buffer.nombre,buffer.apellido);
					retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _sortCliente: Sort the array by different critery.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_sortCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int order;

	if (pArrayListCliente != NULL)
	{
		if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,CANTIDAD_REINTENTOS)==0)
		{
			//printf("\nENTRO A ORDENAR");
			ll_sort(pArrayListCliente,cliente_compareByName,order);
			retorno=0;
			//printf("\nSALGO ORDENADO");
		}
	}
	//printf("NO ORDENADO");
	return retorno;
}
/**
 * \brief _saveAsText: Guarda los datos de los empleados en el archivo que recibe como parametro (modo texto).
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveClientAsText(char* path, LinkedList* clientList)
{
	int retornar=-1;
	FILE* pFile;
	Cliente* bufferClient;
	int bufferId;
	char bufferName[NOMBRE_LEN];
	char bufferLastName[NOMBRE_LEN];
	char bufferCuit[SIZE_CUIT];
	if(path!=NULL && clientList!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,cuit,nombre,apellido\n");
			retornar=0;
			for(int i=0;i<ll_len(clientList);i++)
			{
				bufferClient = ll_get(clientList, i);
				if(bufferClient!=NULL)
				{
					if( !cliente_getId(bufferClient, &bufferId) && !cliente_getCuit(bufferClient, bufferCuit)
							&& !cliente_getNombre(bufferClient, bufferName) &&!cliente_getApellido(bufferClient, bufferLastName) )
					{
						fprintf(pFile, "%d,%s,%s,%s\n",bufferId, bufferCuit, bufferName, bufferLastName);

					}

				}
			}

		}
		fclose(pFile);
	}
	return retornar;
}
/*--------------------------------------------------------VENTAS---------------------------------------------------------------------------------*/
/**
 * \brief findMaxId: Search max id.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return id if OK/ (-1) Error
 */
static int findMaxIdVenta(LinkedList* pArrayListVenta)
{

	Venta* pVenta;
	int len;
	int i;
	int max;
	int idVenta = -1;

	if(pArrayListVenta != NULL)
	{
		len = ll_len(pArrayListVenta);
		for(i=0;i<len;i++)
		{
			pVenta = ll_get(pArrayListVenta,i);
			venta_getIdVenta(pVenta,&idVenta);
			if (i == 0 || idVenta > max)
			{
				max = idVenta;
			}
		}
		idVenta = max;
	}
	return idVenta;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewIdVenta(LinkedList* pArrayListVenta)
{
    static int idVenta = -1;
    static int flag = 1;

    if(pArrayListVenta != NULL)
    {
		if(flag == 1)
		{
			idVenta = findMaxIdVenta(pArrayListVenta);
			flag++;
		}
		idVenta++;
    }
    return idVenta;
}
/**
 * \brief _loadClienteFromText: Carga los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param char* path: File address..
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadVentaFromText(char* path, LinkedList* listaVenta)
{
	int retornar=-1;
	FILE* pFile;
	if(path!=NULL && listaVenta!=NULL)
	{

		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_sellFromText(pFile, listaVenta))
		{
			retornar=0;
		}
		else
		{
			printf("\nEl archivo no existe");
		}
		fclose(pFile);
	}
    return retornar;
}
/**
 * \brief _addCliente: Create a new profile asking data to the user.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_addVenta(LinkedList* pArrayListCliente,LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pVenta;
	Venta buffer;
	Cliente bufferCliente;
	if (pArrayListCliente != NULL && pArrayListVenta != NULL && !controller_ListCliente(pArrayListCliente))
	{
		pVenta = venta_new();
		if(pVenta != NULL && !utn_getNumber(&bufferCliente.id, "\nIngrese el id del cliente: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS) &&
		   controller_findByIdCliente(pArrayListCliente,bufferCliente.id)>=0)
		{
			if(!utn_getNumber(&buffer.cantidadAfiches, "\nIngrese cantidad de afiches a comprar: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS) &&
			   !utn_getName(buffer.nombreArchivo,sizeof(buffer.nombreArchivo),"\nIngrese nombre: ","Error", CANTIDAD_REINTENTOS) &&
			   !utn_getNumber(&buffer.zona, "\nIngrese zona donde se pegaran los afiches: \n1)CABA\n2)SUR\n3)OESTE\n ZONA:" ,"\nError!",1, 3, CANTIDAD_REINTENTOS))
			{


				buffer.idVenta = generateNewIdVenta(pArrayListVenta);
				if (!venta_setIdCliente(pVenta,bufferCliente.id) &&
					!venta_setIdVenta(pVenta,buffer.idVenta) &&
					!venta_setCantidadAfiches(pVenta,buffer.cantidadAfiches) &&
					!venta_setNombreArchivo(pVenta,buffer.nombreArchivo) &&
					!venta_setZona(pVenta,buffer.zona)&&
					!venta_setEstadoVenta(pVenta,0))
				{
					retorno = ll_add(pArrayListVenta, pVenta);
					printf("\nID para la nueva venta: %d\n", buffer.idVenta);
			    }
			}
			else
			{
				printf("\nDATOS INGRESADOS INCORRECTOS VERIFIQUE");
			}
		}
		else
		{
			printf("\nID CLIENTE NO EXISTE VERIFIQUE");
		}
	}
	return retorno;
}
/**
 * \brief _findById: find the position in the array searched by Id.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param int id: Id received to search position.
 * \\return int indice encontrado if OK o (-1) si el puntero a LikedList es NULL, id invalido o cliente no encontrado
 */
int controller_findByIdCliente(LinkedList* pArrayListCliente, int id)
{
	int retorno = -1;
	int i;
	int bufferId;
	int len;
	Cliente* pCliente;

	if (pArrayListCliente != NULL && id > 0)
	{
		len = ll_len(pArrayListCliente);
		for (i = 0; i < len; i++)
		{
			pCliente = (Cliente*)ll_get(pArrayListCliente,i);
			if (pCliente != NULL && !cliente_getId(pCliente,&bufferId) && bufferId == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief _ListCliente: Print all the uploaded data.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_listVenta(LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int len= ll_len(pArrayListVenta);
    int i;

    if(pArrayListVenta != NULL)
    {
    	printf("\n%8s %8s %15s %30s %10s %15s\n","IDC","IDV","CANTIDAD AFICHES","NOMBRE ARCHIVO","ZONA","ESTADO VENTA\n");
    	for(i=0;i<len;i++)
    	{
    		retorno = controller_printOneVenta(pArrayListVenta,i);
    	}
    }
	return retorno;
}
/**
 * \brief _printOneCliente: Print data by index.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param int index: Is the data position in the array.
 * \return (-1) Error / (0) Ok
 */
int controller_printOneVenta(LinkedList* pArrayListVenta, int index)
{
	int retorno = -1;
	Venta buffer;
	Venta* pVenta;

	if(pArrayListVenta != NULL && index >= 0)
	{
		pVenta = (Venta*)ll_get(pArrayListVenta,index);
		if(	pVenta != NULL && !venta_getIdCliente(pVenta,&buffer.idCliente) &&
			!venta_getIdVenta(pVenta,&buffer.idVenta) &&
			!venta_getCantidadAfiches(pVenta,&buffer.cantidadAfiches) &&
			!venta_getNombreArchivo(pVenta,buffer.nombreArchivo) &&
		    !venta_getZona(pVenta,&buffer.zona) &&
			!venta_getEstadoVenta(pVenta,&buffer.estadoVenta))
		{
			printf("\n%8d %8d %15d %30s %10d %15d\n",buffer.idCliente,buffer.idVenta,buffer.cantidadAfiches,buffer.nombreArchivo,buffer.zona,buffer.estadoVenta);
					retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _editCliente: Modify the data of an cliente.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \return Return(-1) Error / Return(0) Ok
 */
int controller_editVenta(LinkedList* listVenta,LinkedList* listCliente)
{
	int retorno = -1;
	LinkedList* bufferAuxListaVenta;
	Venta* pVenta;
	Venta buffer;
	int index;
	int option;

	if (listVenta != NULL)
	{
		bufferAuxListaVenta = ll_subListFilter(listVenta,venta_aCobrar);
		if (!controller_listVenta(bufferAuxListaVenta) &&
			!utn_getNumber(&buffer.idVenta, "\nIngrese el id de venta que quiere modificar: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS))
		{
			index = controller_findByIdVenta(listVenta,buffer.idVenta);
			if (index != -1)
			{
				pVenta = (Venta*) ll_get(listVenta, index);
				venta_getEstadoVenta(pVenta,&buffer.estadoVenta);
				if (pVenta != NULL && buffer.estadoVenta==0 )
				{
					do {
						if (!utn_getNumber(&option, "\n\n1.Modificar cantidad afiches \n2.Modificar nombre archivo "
								"\n3.Modificar zona\n4.Volver al menu principal\n \n Opcion:","Error, elija una opcion valida\n", 1, 4, CANTIDAD_REINTENTOS))
						{
							switch (option)
							{
							case 1:
								if (!utn_getNumber(&buffer.cantidadAfiches, "\nIngrese cantidad de afiches: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS))
								{
									venta_setCantidadAfiches(pVenta,buffer.cantidadAfiches);
									ll_set(listVenta, index, pVenta);
									printf("\nMODIFICACION DE AFICHES OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO AFICHES\n");
								}
							break;
							case 2:
								if (!utn_getName(buffer.nombreArchivo,sizeof(buffer.nombreArchivo),"\nIngrese nombre de archivo: ","Error", CANTIDAD_REINTENTOS))
								{
									venta_setNombreArchivo(pVenta,buffer.nombreArchivo);
									ll_set(listVenta, index, pVenta);
									printf("\nMODIFICACION DE NOMBRE DE ARCHIVO OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO NOMBRE DE ARCHIVO\n");
								}
							break;
							case 3:
								if (!utn_getNumber(&buffer.zona, "\nIngrese zona nueva donde se pegaran los afiches: \n1)CABA\n2)SUR\n3)OESTE\n ZONA:" ,"\nError!",1, 3, CANTIDAD_REINTENTOS))
								{
									venta_setZona(pVenta,buffer.zona);
									ll_set(listVenta, index, pVenta);
									printf("\nMODIFICACION DE ZONA OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO LA ZONA\n");
								}
							break;
							}
						}
						else
						{
							printf("\nSE QUEDO SIN INTENTOS, REGRESANDO A MENU ANTERIOR\n");
						}
						if (retorno < 0)
						{
							break;
						}
					} while (option != 4);
				}
				else
				{
					printf("\nNO SE PUEDE MODIFICAR VENTA EN ESTADO COBRADA\n");
				}
			}
			else
			{
				printf("\nID NO ENCONTRADO VERIFIQUE\n");
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE\n");
		}
	}
	return retorno;
}
/**
 * \brief _cobrarVenta: Change the state of a sell.
 * \param LinkedList* listaCliente: Pointer to the array.
 * \param LinkedList* listaVenta: Pointer to the array.
 * \return Return(-1) Error / Return(0) Ok
 */
int controller_cobrarVenta(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retorno=-1;
	LinkedList* bufferAuxListaVenta;
	int bufferId;
	int indexVenta;
	int indexClient;
	Cliente* bufferClient;
	Venta* bufferVenta;
	int bufferInt;
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		bufferAuxListaVenta = ll_subListFilter(listaVenta,venta_aCobrar);
		if( !controller_listVenta(bufferAuxListaVenta) &&
			!utn_getNumber(&bufferId, "\nIngrese el id de venta que quiere cobrar: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS))
		{
			indexVenta=controller_findByIdVenta(listaVenta, bufferId);
			bufferVenta = ll_get(listaVenta, indexVenta);
			if(venta_aCobrar(bufferVenta) && !venta_getIdCliente(bufferVenta, &bufferId))
			{
				indexClient=controller_findByIdCliente(listaCliente, bufferId);
				bufferClient = ll_get(listaCliente, indexClient);
				cliente_print(bufferClient);
				if( !utn_getNumber(&bufferInt,"\n\nDesea cobrar esta venta?\nIngrese 1 para cobrar o 2 para volver atras: ", "\nERROR!", 1, 2,CANTIDAD_REINTENTOS) &&
					bufferInt==1 && !venta_setEstadoVenta(bufferVenta, 1))
				{
					ll_set(listaVenta,indexVenta,bufferVenta);
					retorno=0;
				}
				else
				{
					printf("\nNO SE CAMBIO A ESTADO COBRADA\n");
				}
			}
			else
			{
				printf("\nID NO ENCONTRADO\n");
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO\n");
		}
	}
	return retorno;
}
/**
 * \brief _saveAsText: Guarda los datos de los empleados en el archivo que recibe como parametro (modo texto).
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveVentaAsText(char* path, LinkedList* listVenta)
{
	int retornar=-1;
	FILE* pFile;
	Venta* bufferVenta;
	int bufferIdCliente;
	int bufferIdVenta;
	int bufferCantidadAfiches;
	char bufferNombreArchivo[NOMBRE_LEN];
	int bufferZona;
	int bufferEstadoVenta;
	if(path!=NULL && listVenta!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile,"idcliente,idventa,cantidadAfiches,nombrearchivo,zona,estadoventa\n");
			retornar=0;
			for(int i=0;i<ll_len(listVenta);i++)
			{
				bufferVenta = ll_get(listVenta, i);
				if(bufferVenta!=NULL)
				{
					if( !venta_getIdCliente(bufferVenta,&bufferIdCliente) &&
						!venta_getIdVenta(bufferVenta,&bufferIdVenta) &&
						!venta_getCantidadAfiches(bufferVenta,&bufferCantidadAfiches) &&
						!venta_getNombreArchivo(bufferVenta,bufferNombreArchivo) &&
						!venta_getZona(bufferVenta,&bufferZona) &&
						!venta_getEstadoVenta(bufferVenta,&bufferEstadoVenta)  )
					{
						fprintf(pFile, "%d,%d,%d,%s,%d,%d\n",bufferIdCliente,bufferIdVenta,bufferCantidadAfiches,bufferNombreArchivo,bufferZona,bufferEstadoVenta);
					}
				}
			}
		}
		fclose(pFile);
	}
	return retornar;
}
/**
 * \brief _findById: find the position in the array searched by Id.
 * \param LinkedList* pArrayListCliente: Pointer to the array.
 * \param int id: Id received to search position.
 * \\return int indice encontrado if OK o (-1) si el puntero a LikedList es NULL, id invalido o cliente no encontrado
 */
int controller_findByIdVenta(LinkedList* pArrayListVenta, int id)
{
	int retorno = -1;
	int i;
	int bufferId;
	int len;
	Venta* pVenta;

	if (pArrayListVenta != NULL && id > 0)
	{
		len = ll_len(pArrayListVenta);
		for (i = 0; i < len; i++)
		{
			pVenta = (Venta*)ll_get(pArrayListVenta,i);
			if (pVenta != NULL && !venta_getIdVenta(pVenta,&bufferId) && bufferId == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief _saveClienteVentasCobrar: Guarda las listas generadas en un archivo a_cobrar.txt.(modo texto).
 * \param LinkedList* listaCliente: Pointer to the array.
 * \param LinkedList* listaVenta: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_saveClienteVentasCobrar(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retornar=-1;
	Cliente* bufferClient;
	FILE* pFile;
	LinkedList* bufferAuxListaVenta;
	int counter;
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	char bufferApellido[NOMBRE_LEN];
	char bufferCuit[SIZE_CUIT];
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		bufferAuxListaVenta = ll_subListFilter(listaVenta,venta_aCobrar);
		pFile = fopen("a_cobrar.txt", "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,cuit,nombre,apellido,ventas_a_cobrar\n");
			for(int i=0;i<ll_len(listaCliente);i++)
			{
				bufferClient = ll_get(listaCliente, i);
				if( !cliente_getId(bufferClient, &bufferId) &&
					!cliente_getCuit(bufferClient, bufferCuit) &&
					!cliente_getNombre(bufferClient, bufferNombre) &&
					!cliente_getApellido(bufferClient, bufferApellido))
				{
					if(!ll_reduceInt(bufferAuxListaVenta,venta_compararId,bufferId,&counter) && counter!=0)
					{
						fprintf(pFile, "%d,%s,%s,%s,%d\n", bufferId, bufferCuit, bufferNombre, bufferApellido, counter);
					}
				}
			}
		}
		retornar=0;
		fclose(pFile);
	}
	return retornar;
}
/**
 * \brief _saveClienteVentasCobrar: Guarda la lista generada en un archivo cobrados.txt.(modo texto).
 * \param LinkedList* listaCliente: Pointer to the array.
 * \param LinkedList* listaVenta: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_saveClientesVentasCobradas(LinkedList* listaCliente, LinkedList* listaVenta)
{
	int retornar=-1;
	Cliente* bufferClient;
	FILE* pFile;
	LinkedList* bufferAuxListaVenta;
	int counter;
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	char bufferApellido[NOMBRE_LEN];
	char bufferCuit[SIZE_CUIT];
	if(listaCliente!=NULL && listaVenta!=NULL)
	{
		bufferAuxListaVenta = ll_subListFilter(listaVenta,venta_estaCobrada);
		pFile = fopen("cobrados.txt", "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,cuit,nombre,apellido,ventas_cobradas\n");
			for(int i=0;i<ll_len(listaCliente);i++)
			{
				bufferClient = ll_get(listaCliente, i);
				if( !cliente_getId(bufferClient, &bufferId) &&
					!cliente_getCuit(bufferClient, bufferCuit) &&
					!cliente_getNombre(bufferClient, bufferNombre) &&
					!cliente_getApellido(bufferClient, bufferApellido))
				{
					if(!ll_reduceInt(bufferAuxListaVenta, venta_compararId, bufferId ,&counter) && counter!=0)
					{
						fprintf(pFile, "%d,%s,%s,%s,%d\n", bufferId, bufferCuit, bufferNombre, bufferApellido, counter);
					}
				}
			}
		}
		retornar=0;
		fclose(pFile);
	}
	return retornar;
}
