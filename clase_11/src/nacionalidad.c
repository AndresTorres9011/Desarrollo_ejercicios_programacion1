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
#include "nacionalidad.h"

static int generarIdNuevo(void);

/**
 * \brief _alta: Realiza el alta solo si el indice corresponde a un Empty.
 * \param  array[]: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \param int indice: Es el indice donde se cargara el dato.
 * \return (-1) Error / (0) Ok
 *
 */
int nacionalidad_alta(Nacionalidad array[],int limite,int indice)
{
	int retorno = -1;
	Nacionalidad buffer;
	if(	array != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		array[indice].isEmpty == TRUE)
	{
		if(utn_getNombre("\n  Nombre?","\n  Error no es un nombre valido",buffer.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
		{
			//buffer.isEmpty = FALSE;
			buffer.id= generarIdNuevo();
			array[indice] = buffer;
			array[indice].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _altaSinIndice: Realiza el alta, utiliza _buscarLibreRef para ubicar
 *                               en una posicion libre.
 * \param  * pArray: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (0) Ok
 *
 */
int nacionalidad_altaSinIndice (Nacionalidad * pArray, int limite)
{
	int retorno = -1;
	int indice;
	Nacionalidad buffer;
	if (pArray != NULL && limite >0)
	{
		if (nacionalidad_buscarLibreRef(pArray,limite,&indice) == 0)
		{
			if (utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
			{
				buffer.id= generarIdNuevo();
				pArray[indice] = buffer;
				pArray[indice].isEmpty = FALSE;
				retorno=0;
			}
			else
			{
				printf("  ERROR NO INGRESASTE DATOS VALIDOS");
			}
		}
		else
		{
			printf("\n  NO QUEDADN ESPACIOS LIBRES");
		}
	}
	return retorno ;
}
/**
 * \brief _imprimir: Imprime los datos cargados
 * \param * pArray: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int nacionalidad_imprimir(Nacionalidad* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\n ID: %d - Nombre: %s\n",pArray[i].id,pArray[i].nombre);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief _printById: Imprime los datos cargados.
 * \param * pArray: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \param int index: Es la posicion del array.
 * \return (-1) Error / (0) Ok
 */
int nacionalidad_printById(Nacionalidad* pArray, int limit, int index)
{
	int retorno = -1;

	if(pArray!= NULL && limit > 0 && index < limit)
	{
		if(pArray[index].isEmpty == FALSE)
		{
			printf("\n ID: %d - Nombre: %s\n",pArray[index].id,pArray[index].nombre);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _initArray: Inicializa el array.
 * \param * pArray: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int nacionalidad_initArray(Nacionalidad* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief _buscarLibreRef: Busca un espacio libre.
 * \param  pArray[]: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \param int *pIndex: Direccion de memoria de la variable donde escribe el valor.
 * \return (-1) Error / (0) Ok
 */
int nacionalidad_buscarLibreRef(Nacionalidad pArray[], int limite, int *pIndex)
{
	int retornar = -1;
	if(pArray != NULL && pIndex != NULL && limite>0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == TRUE)
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
 * \brief _buscarLibreValor: Busca un espacio libre.
 * \param  pArray[]: Es el puntero al array.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (i) Ok
 */
int nacionalidad_buscarLibreValor(Nacionalidad pArray[], int limit)
{
	int retornar = -1;
	if(pArray != NULL && limit>0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArray[i].isEmpty == TRUE)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}
/**
 * \brief _modificar: Modifica los datos solo si el indice corresponde a un NO Empty
 * \param  array[]: Es el puntero al array
 * \param int limite: Es el limite de array
 * \param int indice: Es el indice donde se carga
 * \return (-1) Error / (0) Ok
 *
 */
int nacionalidad_modificar(Nacionalidad array[],int limite,int indice)
{
	int retorno = -1;

	Nacionalidad buffer;
	if(array != NULL && limite>0 && indice<limite)
	{
		if(utn_getNombre("\n Ingrese Nombre?","\nError Reingrese Nombre",buffer.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			buffer.id= array[indice].id; //generarIdNuevo(); // NOOOOOOOOO
			array[indice] = buffer;
			array[indice].isEmpty = FALSE;
			retorno = 0;
		}
	}

	return retorno;
}
/* Cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 */
static int generarIdNuevo(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}
/**
 * \brief _buscarId: Modifica los datos solo si el indice corresponde a un NO Empty.
 * \param  * pArray: Es el puntero al array.
 * \param int limite: Es el limite de array
 * \param int *pIndex: Direccion de memoria de la variable donde escribe el valor.
 * \param int id: Es el id que se asigna.
 * \return (-1) Error / (0) Ok
 *
 */
int nacionalidad_buscarId(Nacionalidad* pArray, int limite, int* pIndex, int id)
{
    int retorno = -1;
    //*pIndex = -1;
    if (pArray != NULL && limite > 0)
    {
        for (int i = 0; i < limite; i++)
        {
            if(pArray[i].isEmpty == FALSE )
            {
                if(pArray[i].id == id)
                {
                   *pIndex = i;
                   retorno = 0;
                    break;
                }
                else
                {
                	printf("  NO SE ENCUENTRA ID");
                }
            }
        }
    }
    return retorno;
}
/**
 * \brief _ordenarPorNombre:Ordena el array recibido como parametro por nombre.
 * \param  pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 *
 */
int nacionalidad_ordenarPorNombre( Nacionalidad pArray[], int len)
{
	int retorno=-1;
	Nacionalidad swap;
    int flagEstadoDesordenado=1;

    if(pArray!=NULL && len>0)
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if(strncmp(pArray[i].nombre,pArray[i + 1].nombre,LONG_NOMBRE)>0)// establezco por que criterio quiero ordenar
				{
					swap = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = swap;
					flagEstadoDesordenado = 1;
				}
			}
		}
    	retorno=0;
    }
	return retorno;
}
/**
 * \brief _baja: Da de baja los datos.
 * \param  array[]: Es el puntero al array.
 * \param int limite: Es el limite de array
 * \param int indice: Es el indice donde se cargara el dato.
 * \return (-1) Error / (0) Ok
 *
 */
int nacionalidad_baja(Nacionalidad array[],int limite,int indice)
{
	int retorno = -1;

	if(array != NULL && limite>0 && indice<limite)
	{
		if(array[indice].isEmpty == FALSE)
		{
			array[indice].isEmpty = TRUE;
			retorno = 0;
		}
	}
	return retorno;
}
