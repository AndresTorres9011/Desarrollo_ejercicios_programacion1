/*
 * ventas.h
 *
 *  Created on: 26/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef VENTAS_H_
#define VENTAS_H_

#define NOMBRE_LEN 128

typedef struct{
	int idCliente;
	int idVenta;
	int cantidadAfiches;
	char nombreArchivo[NOMBRE_LEN];
	int zona;
	int estadoVenta;
}Venta;

Venta* venta_new();
Venta* venta_newParametros(int idCliente,int idVenta,int cantidadAfiches,char* nombreArchivo,int zona,int estadoVenta);
Venta* venta_newParametrosTxt(char* idCliente,char* idVenta,char* cantidadAfiches,char* nombreArchivo,char* zona,char* estadoVenta);
void venta_delete(Venta*);

int venta_setIdCliente(Venta* this,int idCliente);
int venta_getIdCliente(Venta* this,int* idCliente);
int venta_setIdClienteTxt(Venta* this, char* idCliente);
int venta_getIdClienteTxt(Venta* this, char* idCliente);

int venta_setIdVenta(Venta* this,int idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);
int venta_setIdVentaTxt(Venta* this, char* idVenta);
int venta_getIdVentaTxt(Venta* this, char* idVenta);

int venta_setCantidadAfiches(Venta* this,int cantidadAfiches);
int venta_getCantidadAfiches(Venta* this,int* cantidadAfiches);
int venta_setCantidadAfichesTxt(Venta* this, char* cantidadAfiches);
int venta_getCantidadAfichesTxt(Venta* this, char* cantidadAfiches);


int venta_setNombreArchivo(Venta* this, char* nombreArchivo);
int venta_getNombreArchivo(Venta* this, char* nombreArchivo);

int venta_setZona(Venta* this,int zona);
int venta_getZona(Venta* this,int* zona);
int venta_setZonaTxt(Venta* this, char* zona);
int venta_getZonaTxt(Venta* this, char* zona);

int venta_setEstadoVenta(Venta* this,int estadoVenta);
int venta_getEstadoVenta(Venta* this,int* estadoVenta);
int venta_setEstadoVentaTxt(Venta* this, char* estadoVenta);
int venta_getEstadoVentaTxt(Venta* this, char* estadoVenta);

int venta_aCobrar(void* this);
int venta_estaCobrada(void* this);
int venta_compararId(void* this, void* id);
int venta_acumularAfiches(void* pElement,int idCliente);

#endif /* VENTAS_H_ */
