/*
 ============================================================================
 Name        : prueba_tp4.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envios.h"
#include "utn.h"


int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	LinkedList *listaEmpleados = ll_newLinkedList();
	int retorno;

	do
	{
		if(!utn_getNumber(&option,"\n\n1-Cargar archivo de empleados (modo texto).""\n2-Cargar archivo de empleados (modo binario)."
						  "\n3-\n4-\n5-\n6-Listar empleados\n7-"
							"\n8-Guardar datos en archivo (modo texto)\n9-Guardar datos en archivo (modo binario)."
							"\n10. SALIR\n\n Opcion: ","\nError! elija una opcion valida",1,10,CANTIDAD_REINTENTOS))
		{
			switch (option)
			{
				case 1:
					if (!controller_loadFromText("dataComoTexto.csv", listaEmpleados))
					{
						printf("\nARCHIVO CARGADO MODO TEXTO\n");
					}
					else
					{
						printf("\nARCHIVO NO CARGADO VERIFIQUE\n");
					}
					break;
				case 2:
					if ((retorno = controller_loadFromBinary("dataComoBinario.bin", listaEmpleados) == 0))
					{
						printf("\nARCHIVO CARGADO MODO BINARIO\n");
					}
					else
					{
						printf("\nARCHIVO NO CARGADO VERIFIQUE\n");
					}
					break;
			    case 3:
				break;
				case 4:
		        break;
				case 5:
				break;
				case 6:
					if(!ll_isEmpty(listaEmpleados))
					{
						controller_ListEnvios(listaEmpleados);
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 7:
				break;
				case 8:
					if(!ll_isEmpty(listaEmpleados))
					{
						if (controller_saveAsText("dataComoTexto.csv", listaEmpleados) == 0)
						{
							printf("\nARCHIVO GUARDADO EN MODO TEXTO\n");
						}
						else
						{
							printf("\nNO SE GUARDO ARCHIVO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 9:
					if(!ll_isEmpty(listaEmpleados))
					{
						if (controller_saveAsBinary("dataComoBinario.bin", listaEmpleados) == 0)
						{
							printf("\nARCHIVO GUARDADO EN MODO BINARIO\n");

						}
						else
						{
							printf("\nNO SE GUARDO ARCHIVO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
			}
		}
	} while (option != 10);
	printf("\n\nPROGRAMA TERMINADO\n\n");
	return 0;
}
