/*
 ============================================================================
 Name        : segundoparcial_2020.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "clientes.h"
#include "utn.h"
#include "informes.h"


int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	LinkedList *listaClientes = ll_newLinkedList();
	LinkedList* listaVentas = ll_newLinkedList();

	controller_loadClientFromText("clienteComoTexto.csv", listaClientes);
	controller_loadVentaFromText("ventaComoTexto.csv", listaVentas);
	do
	{
		if(!utn_getNumber(&option,"\n\n1-Alta de cliente.""\n2-Modificar datos de cliente"
						  "\n3-Baja de cliente\n4-Listar clientes\n5-Ordenar clientes\n6-Guardar datos de clientes en archivo (modo texto)\n7-Alta de venta"
						  "\n8-Modificar venta\n9-Cobrar venta\n10-Listar ventas\n11-Guardar datos de ventas en archivo (modo texto)"
				          "\n12-Generar informe de cobros\n13-Generar informe de deudas\n14-Generar estadísticas"
						   "\n15-SALIR\n\n Opcion: ","\nError! elija una opcion valida",1,15,CANTIDAD_REINTENTOS))
		{
			switch (option)
			{
				case 1:
					if(!ll_isEmpty(listaClientes))
					{
						if(!controller_addCliente(listaClientes))
						{
							printf("\nALTA DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE REALIZO ALTA DE EMPLEADO\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 2:
					if(!ll_isEmpty(listaClientes))
					{
						if (!controller_editCliente(listaClientes))
						{
							printf("\nMODIFICACION DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE MODIFICO EMPLEADO\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 3:
					if(!ll_isEmpty(listaClientes))
					{
						if(!controller_removeCliente(listaClientes))
						{
							printf("\nBAJA DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE REALIZO BAJA DE EMPLEADO\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 4:
					if(!ll_isEmpty(listaClientes))
					{
						controller_ListCliente(listaClientes);
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 5:
					if(!ll_isEmpty(listaClientes))
					{
						if(!controller_sortCliente(listaClientes))
						{
							printf("\nLISTA DE CLIENTES ORDENADA\n");
						}
						else
						{
							printf("\nNO SE ORDENO LA LISTA\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 6:
					if(!ll_isEmpty(listaClientes))
					{
						if (controller_saveClientAsText("clienteComoTexto.csv", listaClientes) == 0)
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
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 7:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if(!controller_addVenta(listaClientes,listaVentas))
						{
							printf("\nVENTA CARGADA A COBRAR OK\n");
						}
						else
						{
							printf("\nNO SE REALIZO ALTA DE VENTA\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 8:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if (!controller_editVenta(listaVentas,listaClientes))
						{
							printf("\nMODIFICACION DE VENTA OK\n");
						}
						else
						{
							printf("\nNO SE MODIFICO VENTA\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 9:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if (!controller_cobrarVenta(listaClientes,listaVentas))
						{
							printf("\nMODIFICACION DE VENTA OK\n");
						}
						else
						{
							printf("\nNO SE MODIFICO VENTA\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 10:
					if(!ll_isEmpty(listaClientes))
					{
						controller_listVenta(listaVentas);
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
					break;

				case 11:
					if(!ll_isEmpty(listaVentas))
					{
						if (controller_saveVentaAsText("ventaComoTexto.csv", listaVentas) == 0)
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
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 12:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if (controller_saveClientesVentasCobradas(listaClientes,listaVentas) == 0)
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
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 13:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if (controller_saveClienteVentasCobrar(listaClientes,listaVentas) == 0)
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
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
				case 14:
					if(!ll_isEmpty(listaVentas) && !ll_isEmpty(listaClientes))
					{
						if (informes_report(listaClientes,listaVentas) == 0)
						{
							printf("\nINFORME DE ESTADISTICAS OK\n");
						}
						else
						{
							printf("\nNO SE PUEDE GENERAR INFORME DE ESTADISTICAS\n");
						}
					}
					else
					{
						printf("\nNO HAY DATOS CARGADOS\n");
					}
				break;
			}
		}
	} while (option != 15);
	printf("\n\nPROGRAMA TERMINADO\n\n");
	return 0;
}
