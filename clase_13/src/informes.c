/*
 * informes.c
 *
 *  Created on: 12/10/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */


/**
 * \brief _imprimirContratacionesPorCuit: Print the uploaded data by cuit.
 * \param (define struct)* list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contrataciones.h"
#include "pantalla.h"
#include "informes.h"

#define TRUE 1
#define FALSE 0
#define CANTIDAD_REINTENTOS 3
#define MIN_CUIT 1
#define MAX_CUIT 999999999
#define QTY_CONTRATACIONES 15
#define SIZE_CUIT 51
#define CANTIDAD_CLIENTES 1000

int informes_imprimirContratacionesConImporte(Contratacion * list, int len, Pantalla * listDos , int lenDos, char* cuit)
{
	int retorno =-1;
	int indicePantalla;
	int idPantalla;
	float auxiliarImporte;
		if (list != NULL && len > 0 && listDos != NULL && lenDos>0)
		{
			for(int i = 0; i<len ; i++)
			{
				if ( list[i].isEmpty == FALSE && strncmp(list[i].cuitCliente,cuit,SIZE_CUIT)==0 )
				{
					retorno = 0;
					idPantalla= list[i].idPantalla;
					pantalla_findById(listDos, lenDos, &indicePantalla,idPantalla);
					auxiliarImporte = list[i].cantidadDias * listDos[indicePantalla].pricePerDay;
					printf("\n  -IDc: %d -Cuit: %s -Archivo: %s -Cantidad de Dias: %d   -IDp: %d"
						  ,list[i].idContratacion,list[i].cuitCliente,list[i].name,list[i].cantidadDias,list[i].idPantalla);
					printf("  -Precio por dia: %.2f  -Importe: %.2f",listDos[indicePantalla].pricePerDay,auxiliarImporte);
				}
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
int informes_findByCuit(Contratacion* list, int len, int* pIndex, char* cuitCliente)
{
    int retorno = -1;

    if (list != NULL && pIndex!= NULL && len > 0 && cuitCliente>0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if( strncmp(list[i].cuitCliente,cuitCliente,SIZE_CUIT)==0  )
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

int informes_importe(Contratacion * list, int len, Pantalla * listDos , int lenDos)
{
	int retorno = -1;
	char cuitBuscar[SIZE_CUIT];
	int index;

	if(list != NULL && len>0 && listDos!=NULL && lenDos>0)
	{
			if(!utn_getCuit("\n\n  Ingrese cuit a buscar:","  Error Reingrese cuit!",cuitBuscar,SIZE_CUIT,CANTIDAD_REINTENTOS,MIN_CUIT,MAX_CUIT) &&
				!informes_findByCuit(list,QTY_CONTRATACIONES,&index,cuitBuscar))
			{
				informes_imprimirContratacionesConImporte (list,len,listDos, lenDos,cuitBuscar);
				retorno=0;
			}
			else
			{
				printf("\n  CUIT INVALIDO VERIFIQUE\n");
			}
	}
	return retorno;
}

int informes_imprimirContratacionesConImportePorCliente (Contratacion * list, int len, Pantalla * listDos , int lenDos)
{
	int retorno=-1;
	char listaCuit[CANTIDAD_CLIENTES][SIZE_CUIT];
	int i;
	int j;
	int flagExisteCuit;
	int indiceCuitLibre=0;
	float auxiliarDeuda;
	float deudaMaxima;
	int indiceClienteDeudaMax;

	if(list != NULL && len>0 && listDos!=NULL && lenDos>0)
	{
		for( i=0;i<len;i++)
		{
			flagExisteCuit=0;
			if(list[i].isEmpty== FALSE)
			{
				for( j=0;j<indiceCuitLibre;j++)
				{
					if(strncmp(list[i].cuitCliente,listaCuit[j],SIZE_CUIT)==0)
					{
						flagExisteCuit=1;
						break;
					}
				}
				if(flagExisteCuit==0)
				{
					strncpy(listaCuit[indiceCuitLibre],list[i].cuitCliente,SIZE_CUIT);
					indiceCuitLibre++;
					//agregar
				}
		    }
		}
		for( j=0;j<indiceCuitLibre;j++)
		{
			printf("\n\n  El cliente con cuit %s \n",listaCuit[j]);
			informes_imprimirContratacionesConImporte (list,len,listDos,lenDos,listaCuit[j]);
		}
		for( j=0;j<indiceCuitLibre;j++)
		{
			informes_calcularDeudaCliente(list,len,listDos,lenDos,listaCuit[j],&auxiliarDeuda);
			if( j==0 || (auxiliarDeuda>deudaMaxima))
			{
				deudaMaxima=auxiliarDeuda;
				indiceClienteDeudaMax=j;
			}
		}
		printf("\n\n  El cliente con la deuda mas alta es cuit  %s - Debe %.2f\n",listaCuit[indiceClienteDeudaMax],deudaMaxima);
	}
	return retorno;
}
int informes_calcularDeudaCliente(Contratacion * list, int len, Pantalla * listDos , int lenDos, char* cuit, float* deuda)
{
	int retorno =-1;
	int indicePantalla;
	int idPantalla;
	float auxiliarDeuda=0;

	if (list != NULL && len > 0 && listDos != NULL && lenDos>0)
	{
		for(int i = 0; i<len ; i++)
		{
			if ( list[i].isEmpty == FALSE && strncmp(list[i].cuitCliente,cuit,SIZE_CUIT)==0 )
			{
				idPantalla= list[i].idPantalla;
				pantalla_findById(listDos, lenDos, &indicePantalla,idPantalla);
				auxiliarDeuda =  auxiliarDeuda +(list[i].cantidadDias * listDos[indicePantalla].pricePerDay);
			}
		}
		 retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}
