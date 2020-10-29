/*
 * alumno.c
 *
 *  Created on: 29/10/2020
 *       Author: TORRES CAICEDO ANDRES FELIPE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "utn.h"

#define CANTIDAD_REINTENTOS 3

static int newIdGenerate(void);
static int isValidName(char* cadena,int limite);
static int esNumerica(char *cadena, int limite);

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
Alumno* alumno_new(void)
{
	/*Alumno* auxiliarP=NULL;
	auxiliarP=(Alumno*)malloc(sizeof(Alumno));
	return auxiliarP;*/
	return (Alumno*)malloc(sizeof(Alumno));
}
Alumno* alumno_newConParametros(char* nombre,float altura)
{
	Alumno* punteroAlumno=NULL;
	punteroAlumno=alumno_new();
	if(punteroAlumno != NULL)
	{
		punteroAlumno->idAlumno=newIdGenerate();
		strncpy(punteroAlumno->nombre,nombre,sizeof(punteroAlumno->nombre));
		punteroAlumno->altura=altura;
	}
	return punteroAlumno;
}
void alumno_delete(Alumno* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
int alumno_setNombre(Alumno* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre != NULL)
	{
		if(isValidName(nombre,sizeof(this->nombre))==1)
		{
			strncpy(this->nombre,nombre,sizeof(this->nombre));
			retorno=0;
		}
	}
	return retorno;
}
int alumno_getNombre(Alumno* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,SIZE_NAME);
		retorno=0;
	}
	return retorno;
}
int alumno_setIdTxt(Alumno* this,char* id)
{
	int retorno=-1;

	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10)==1)
		{
			this->idAlumno=atoi(id);
			retorno=0;
		}
	}
	return retorno;
}
int alumno_setIdNumber(Alumno* this,int id)
{
	int retorno=-1;

	if(this != NULL && id>=0)
	{
		this->idAlumno=id;
		retorno=0;
	}
	return retorno;
}
int alumno_getIdTxt(Alumno* this,char* id)
{
	int retorno=-1;

	if(this != NULL && id != NULL)
	{
		sprintf(id,"%d",this->idAlumno);
		retorno=0;
	}
	return retorno;
}
int alumno_setAltura(Alumno* this,float altura)
{
	int retorno=-1;

	if(this != NULL && altura>=0)
	{
		this->altura=altura;
		retorno=0;
	}
	return retorno;
}
int alumno_getAltura(Alumno* this,float* altura)
{
	int retorno=-1;

	if(this != NULL && altura != NULL)
	{
		*altura=this->altura;
		retorno=0;
	}
	return retorno;
}
/**
 * \brief esUnNombreValido:	Verifica una cadena recibida como parametro para determinir si es un nombre valido.
 * \param char* cadena: Cadena a analizar.
 * \param int limite: Indica la cantidad de letras maxima de la cadena.
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
static int isValidName(char* cadena,int limite)
{
	int respuesta = 1; // TODO OK

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') )
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/**
 * \brief esNumerica: Verifica si la cadena recibida como parametro es numerica.
 * \param char* cadena: Cadena de caracteres a analizar.
 * \param int limite: Indica la cantidad de caracteres maximos de la cadena.
 * \return (0) Indica que la cadena no es numerica / (1) Indica que la cadena es numerica.
 */
static int esNumerica(char *cadena, int limite)
{
	int retorno=1;//VERDADERO
	int i=0;

	if(cadena[0]=='-')
	{
		i=1;
	}
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(;i<=limite && cadena[i]!='\0';i++)
		{
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=0;//FALSO
				break;
			}
		}
	}
	return retorno;
}
/*********************************************************************************************/
/**
 * \brief _init: To indicate that all position in the array are NULL,
*                this function put NULL in all
*                position of the array.
* \param (Cliente)* list: Pointer to the array.
* \param int len:  Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int alumno_initArray(Alumno* arrayPunteros[],int len)
{
	int retorno=-1;

	if(arrayPunteros!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			arrayPunteros[i] = NULL;
		}
		retorno=0;
	}
	return retorno;
}
/**
 * \brief _searchEmpty: Search in the array for the first index with TRUE in isEmpty.
 * \param (Cliente)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */
int alumno_searchFreeNull(Alumno* arrayPunteros[],int len)
{
	int retorno = -1;
	if(arrayPunteros != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(arrayPunteros[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief _printAllArray: Print all the uploaded data.
 * \param (Cliente)* list: Pointer to the array.
 * \param int len: Array length..
 * \return (-1) Error / (0) Ok
 */
int alumno_printAllArray(Alumno* arrayPunteros[],int len)
{
	int retorno = -1;

	if(arrayPunteros!= NULL && len > 0 )
	{
		printf("\n----LISTA ALUMNOS----\n");
		for(int i=0;i<len;i++)
		{
			if(arrayPunteros[i] != NULL )
			{
				printf("\n-ID: %d -Nombre: %s -Altura: %.2f\n",
						arrayPunteros[i]->idAlumno,arrayPunteros[i]->nombre,arrayPunteros[i]->altura);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief _remove: Remove data by Index
 * \param  (Cliente)* list: Pointer to the array.
 * \param int len: Length of the array
 * \param int index: is the position from which the data is deleted.
 * \return int Return (-1) if Error [Invalid length or NULL pointer o] - (0) if Ok
 */
int alumno_removeByIndex(Alumno* arrayPunteros[],int len,int indice)
{
	int retorno=-1;

	if(arrayPunteros!=NULL && len>0 && indice>=0 && arrayPunteros[indice]!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			alumno_delete(arrayPunteros[indice]);
			arrayPunteros[indice]=NULL;
		}
		retorno=0;
	}
	return retorno;
}
/**
 * \brief _findById: find the position in the array searched by Id.
 * \param (Cliente)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to the memory  where write the value.
 * \param int id: Id received to search position.
 * \return (-1) Error / (0) Ok
 */
int alumno_findById(Alumno* arrayPunteros[], int len, int idAlumno)
{
    int retorno = -1;

    if (arrayPunteros != NULL && len > 0 && idAlumno>0)
    {
        for (int i = 0; i < len; i++)
        {
            if(arrayPunteros[i] != NULL && arrayPunteros[i]->idAlumno == idAlumno )
            {
			   retorno = i;
			   break;
            }
        }
    }
    return retorno;
}
/**
 * \brief _createNew: Create a new profile.
 *                    Use _searchFreeNull, to locate data in an empty index.
 * \param (Cliente) * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 */
int alumno_createNew(Alumno* arrayPunteros[],int len,char* nombre,float altura)
{
    int retorno = -1;
    int indiceLibre;

    if (arrayPunteros != NULL && len > 0 && nombre!=NULL)
    {
    	indiceLibre=alumno_searchFreeNull(arrayPunteros,len);
		if(indiceLibre>=0)
		{
			arrayPunteros[indiceLibre] = alumno_newConParametros(nombre,altura);
			retorno=indiceLibre;
		}
   }
    return retorno;
}
/**
 * \brief _removeById: remove data in the array searched by Id.
 * \param (Cliente)* list: Pointer to the array.
 * \param int len: Array length.
 * \param int id: Id received to search position.
 * \return (-1) Error / (0) Ok
 */
int alumno_removeById(Alumno* arrayPunteros[], int len, int idAlumno)
{
    int retorno = -1;
    int indiceBorrar;

    if (arrayPunteros != NULL && len > 0 && idAlumno>0)
    {
    	indiceBorrar=alumno_findById(arrayPunteros,len,idAlumno);
		if(indiceBorrar>=0)
		{
			if(!alumno_removeByIndex(arrayPunteros,len,indiceBorrar))
			{
				retorno=0;
			}
		}
    }
    return retorno;
}
