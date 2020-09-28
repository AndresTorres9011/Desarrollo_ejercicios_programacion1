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
#include "alumno.h"

static int generarIdNuevo(void);

/**
 * \brief alumno_alta: Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[]: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array
 * \param int indice: Es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(	arrayAlumnos != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayAlumnos[indice].isEmpty == TRUE)
	{
		if(	utn_getNumeroString("\n  Legajo?","\n  Error no es un numero valido",&bufferAlumno.legajo,CANTIDAD_REINTENTOS,MIN_LEGAJO,MAX_LEGAJO) == 0
				 &&
			utn_getNombre("\n  Nombre?","\n  Error no es un nombre valido",bufferAlumno.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			bufferAlumno.id= generarIdNuevo();
			arrayAlumnos[indice] = bufferAlumno;
			arrayAlumnos[indice].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief alumno_altaSinIndice: Realiza el alta de un alumno, utiliza alumno_buscarLibreRef para ubicar al alumno
 *                               en una posicion libre.
 * \param Alumno arrayAlumnos[]: Es el puntero al array de alumnos.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_altaSinIndice (Alumno * pArrayAlumnos, int limite)
{
	int retorno = -1;
	int indice;
	Alumno bufferAlumno;
	if (pArrayAlumnos != NULL && limite >0)
	{
		if (alumno_buscarLibreRef (pArrayAlumnos,limite,&indice) == 0)
		{
			if (utn_getNumeroString("\n  Ingrese Legajo?","\n  Error no es un numero valido",&bufferAlumno.legajo,CANTIDAD_REINTENTOS,MIN_LEGAJO,MAX_LEGAJO) == 0
					 &&
				utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",bufferAlumno.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
			{
				bufferAlumno.id= generarIdNuevo();
				pArrayAlumnos[indice] = bufferAlumno;
				pArrayAlumnos[indice].isEmpty = FALSE;
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
 * \brief alumno_imprimir: Imprime los alumnos cargados
 * \param Alumno* pArrayAlumnos: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\n ID: %d - Legajo: %d - Nombre: %s\n",pArrayAlumnos[i].id,pArrayAlumnos[i].legajo,pArrayAlumnos[i].nombre);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief alumno_printById: Imprime los alumnos cargados.
 * \param Alumno* pArrayAlumnos: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array.
 * \param int index: Es la posicion del array.
 * \return (-1) Error / (0) Ok
 */
int alumno_printById(Alumno* pArrayAlumnos, int limit, int index)
{
		int retorno = -1;

		if(pArrayAlumnos!= NULL && limit > 0 && index < limit)
		{
			if(pArrayAlumnos[index].isEmpty == FALSE)
			{
				printf("\n ID: %d - Legajo: %d - Nombre: %s\n",pArrayAlumnos[index].id,pArrayAlumnos[index].legajo,pArrayAlumnos[index].nombre);
				retorno = 0;
			}
		}
		return retorno;
}
/**
 * \brief alumno_initArray: Inicializa el array de alumnos.
 * \param Alumno* pArrayAlumnos: Es el puntero al array de alumnos.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief alumno_buscarLibreRef: Busca un espacio libre.
 * \param Alumno pArrayAlumnos[]: Es el puntero al array de alumnos.
 * \param int limite: Es el limite de array.
 * \param int *pIndex: Direccion de memoria de la variable donde escribe el valor.
 * \return (-1) Error / (0) Ok
 */
int alumno_buscarLibreRef(Alumno pArrayAlumnos[], int limite, int *pIndex)
{
	int retornar = -1;
	if(pArrayAlumnos != NULL && pIndex != NULL && limite>0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE)
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
 * \brief alumno_buscarLibreValor: Busca un espacio libre.
 * \param Alumno pArrayAlumnos[]: Es el puntero al array de alumnos.
 * \param int limite: Es el limite de array.
 * \return (-1) Error / (i) Ok
 */
int alumno_buscarLibreValor(Alumno pArrayAlumnos[], int limit)
{
	int retornar = -1;
	if(pArrayAlumnos != NULL && limit>0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}
/**
 * \brief alumno_modificar: Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[]: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array
 * \param int indice: Es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;

	Alumno bufferAlumno;
	if(arrayAlumnos != NULL && limite>0 && indice<limite)
	{
		if(	utn_getNumeroString("\n Ingrese Legajo?","\nError Reingrese Legajo",&bufferAlumno.legajo,CANTIDAD_REINTENTOS,MIN_LEGAJO,MAX_LEGAJO) == 0
			&&
		utn_getNombre("\n Ingrese Nombre?","\nError Reingrese Nombre",bufferAlumno.nombre,CANTIDAD_REINTENTOS,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			bufferAlumno.id= arrayAlumnos[indice].id; //generarIdNuevo(); // NOOOOOOOOO
			arrayAlumnos[indice] = bufferAlumno;
			arrayAlumnos[indice].isEmpty = FALSE;
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
 * \brief alumno_buscarId: Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[]: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array
 * \param int *pIndex: Direccion de memoria de la variable donde escribe el valor.
 * \param int id: Es el id que se le asigna al alumno.
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int* pIndex, int id)
{
    int retorno = -1;
    //*pIndex = -1;
    if (pArrayAlumnos != NULL && limite > 0)
    {
        for (int i = 0; i < limite; i++)
        {
            if(pArrayAlumnos[i].isEmpty == FALSE )
            {
                if(pArrayAlumnos[i].id == id)
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
 * \brief alumno_ordenarPorNombre:Ordena el array recibido como parametro por nombre.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 *
 */
int alumno_ordenarPorNombre( Alumno pArray[], int len)
{
	int retorno=-1;
	Alumno swap;
    int flagEstadoDesordenado=1;

    if(pArray!=NULL && len>0)
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if(strncmp(pArray[i].nombre,pArray[i + 1].nombre,LONG_NOMBRE)>0)//aca establezco por que criterio quiero ordenar
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
 * \brief alumno_ordenarPorLegajo:Ordena el array recibido como parametro por numero de lagajo.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 *
 */
int alumno_ordenarPorLegajo( Alumno pArray[], int len)
{
	int retorno=-1;
	Alumno swap;
    int flagEstadoDesordenado=1;

    if(pArray!=NULL && len>0)
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if(pArray[i].legajo > pArray[i+1].legajo)
				{
					// intercambiar (swap)
					swap = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = swap;
					flagEstadoDesordenado=1;
				}
			}
		}
    	retorno=0;
    }
	return retorno;
}
/**
 * \brief alumno_baja: Da de baja los datos de un alumno .
 * \param Alumno arrayAlumnos[]: Es el puntero al array de alumnos
 * \param int limite: Es el limite de array
 * \param int indice: Es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_baja(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;

	if(arrayAlumnos != NULL && limite>0 && indice<limite)
	{
		if(arrayAlumnos[indice].isEmpty == FALSE)
		{
			arrayAlumnos[indice].isEmpty = TRUE;
			retorno = 0;
		}
	}
	return retorno;
}

