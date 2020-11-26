/*
 * Alumno.c
 *
 *  Created on: 2/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

Alumno* alumno_new(void)
{
	Alumno* auxiliarP = NULL;
	auxiliarP = (Alumno*) malloc(sizeof(Alumno));
	return auxiliarP;
}

Alumno* alumno_newParametros(char* nombre,float altura,int id)
{
	Alumno* punteroAlumno = NULL;
	punteroAlumno = alumno_new();
	if(punteroAlumno != NULL)
	{
		strncpy(punteroAlumno->nombre,nombre,NOMBRE_LEN);
		punteroAlumno->altura = altura;
		punteroAlumno->id=id;
	}
	return punteroAlumno;
}

void alumno_delete(Alumno* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int alumno_setNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int alumno_getNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int alumno_setIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

int alumno_setId(Alumno* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int alumno_getIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

int alumno_setAltura(Alumno* this,float altura)
{
	int retorno = -1;
	if(this != NULL && altura >= 0)
	{
		retorno = 0;
		this->altura = altura;
	}
	return retorno;
}

int alumno_getAltura(Alumno* this,float* altura)
{
	int retorno = -1;
	if(this != NULL && altura != NULL)
	{
		retorno = 0;
		*altura = this->altura;
	}
	return retorno;
}
/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**********************************************************************/


int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice)
{
	int retorno=-1;
	if(arrayPunteros != NULL && indice >= 0 && indice < limite && arrayPunteros[indice] != NULL )
	{
		retorno = 0;
		alumno_delete(arrayPunteros[indice]);
		arrayPunteros[indice] = NULL;
	}
	return retorno;
}


int alumno_initArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			arrayPunteros[i] = NULL;
		}
	}
	return retorno;
}

int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
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

int alumno_imprimirArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n-----LISTA ALUMNOS-----\n");
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				printf("Dir: %p - Nombre: %s- ID: %d - Altura: %f\n", arrayPunteros[i],arrayPunteros[i]->nombre,arrayPunteros[i]->id,arrayPunteros[i]->altura);
			}
		}
	}
	return retorno;
}

int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id)
{
	int retorno=-1;
	int indiceLibre;
	if(arrayPunteros != NULL && limite > 0 && nombre != NULL && id >= 0)
	{
		indiceLibre = alumno_buscarLibreArray(arrayPunteros,limite);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre] = alumno_newParametros(nombre,altura,id);
			retorno = indiceLibre;
		}
	}
	return retorno;
}


int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int indiceBorrar;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		indiceBorrar = alumno_buscarPorIdArray(arrayPunteros,limite,id);
		if(indiceBorrar >= 0)
		{
			if(!alumno_deleteIndexInArray(arrayPunteros,limite,indiceBorrar))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}


int alumno_ordenarArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	int flagSwap;
	Alumno* bufferPunteroAlumno;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno=0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	arrayPunteros[i] != NULL &&
					arrayPunteros[i+1] != NULL &&
					strncmp(arrayPunteros[i]->nombre,arrayPunteros[i+1]->nombre,NOMBRE_LEN) > 0)
				{
					bufferPunteroAlumno = arrayPunteros[i];
					arrayPunteros[i] = arrayPunteros[i+1];
					arrayPunteros[i+1] = bufferPunteroAlumno;
					flagSwap=1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

int alumno_calcularAlturaPromedioArray(Alumno* arrayPunteros[],int limite, float* promedio)
{
	int retorno=-1;
	int i;
	int cantidadAlumnos = 0;
	float acumuladorAlturas=0;
	if(arrayPunteros != NULL && limite > 0 && promedio != NULL)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				cantidadAlumnos++;
				acumuladorAlturas = acumuladorAlturas + arrayPunteros[i]->altura;
			}
		}
		*promedio = acumuladorAlturas / cantidadAlumnos;
	}
	return retorno;
}

int alumno_calcularAlturaMaximaArray(Alumno* arrayPunteros[],int limite, int* indice)
{
	int retorno=-1;
	int i;
	int indiceMaximo;
	float alturaMaxima;
	int flagOnes = 0;

	if(arrayPunteros != NULL && limite > 0 && indice != NULL)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				if(!flagOnes)
				{
					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
					flagOnes = 1;
				}
				else if(arrayPunteros[i]->altura > alturaMaxima)
				{
					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
				}
			}
		}
		*indice = indiceMaximo;

	}
	return retorno;
}

