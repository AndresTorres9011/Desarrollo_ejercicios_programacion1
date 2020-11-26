/*
 * controller.h
 *
 *  Created on: 25/11/2020
 *      Author: Vivi Herrera
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadClientFromText(char* path, LinkedList* clientList);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_findById(LinkedList* pArrayListCliente, int id);
int controller_findByCuit(LinkedList* pArrayListCliente, char* cuitCliente);
int controller_editCliente(LinkedList* pArrayListCliente);
int controller_removeCliente(LinkedList* pArrayListCliente);
int controller_ListCliente(LinkedList* pArrayListCliente);
int controller_printOneCliente(LinkedList* pArrayListCliente, int index);
int controller_sortCliente(LinkedList* pArrayListCliente);
int controller_saveClientAsText(char* path, LinkedList* clientList);

int controller_loadVentaFromText(char* path, LinkedList* listaVenta);
int controller_addVenta(LinkedList* pArrayListCliente,LinkedList* pArrayListVenta);
int controller_findByIdCliente(LinkedList* pArrayListCliente, int id);
int controller_listVenta(LinkedList* pArrayListVenta);
int controller_printOneVenta(LinkedList* pArrayListVenta, int index);
int controller_editVenta(LinkedList* listVenta,LinkedList* listCliente);
int controller_cobrarVenta(LinkedList* listaCliente, LinkedList* listaVenta);
int controller_saveVentaAsText(char* path, LinkedList* listVenta);
int controller_findByIdVenta(LinkedList* pArrayListVenta, int id);
int controller_saveClienteVentasCobrar(LinkedList* listaCliente, LinkedList* listaVenta);
int controller_saveClientesVentasCobradas(LinkedList* listaCliente, LinkedList* listaVenta);


#endif /* CONTROLLER_H_ */
