/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 *
 *      *pantalla
--idPantallapantalla
--isEmpty
--nombre de pantalla
--tipo de pantalla
--precio de publicidad en la pantalla, por dia: OK
--direccion
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define SIZE_NAME 51
#define QTY_SCREEN 15


typedef struct
{
	int idPantalla;
	char name[SIZE_NAME];
	char address[SIZE_NAME];
	int pantallaType;
	float pricePerDay;
	int isEmpty;

}Pantalla;

int pantalla_init(Pantalla* list, int len);
int pantalla_searchEmpty(Pantalla* list, int len, int *pIndex);
int pantalla_createNew(Pantalla* list, int len);
int pantalla_findById(Pantalla* list, int len, int* pIndex, int idPantalla);
int pantalla_printById(Pantalla* list, int len, int index);
int pantalla_print(Pantalla* list, int len);
int pantalla_modifify(Pantalla* list,int len);
int pantalla_remove(Pantalla* list,int len);
int pantalla_sortByLastName(Pantalla* list, int len, int order);
int pantalla_sortBySector(Pantalla *list, int len, int order);
int pantalla_countId(Pantalla* list,int len,int* quantityId);
int pantalla_altaForzada(Pantalla * list, int len, char* name,char* address,int pantallaType,float pricePerDay);



#endif /* PANTALLA_H_ */
