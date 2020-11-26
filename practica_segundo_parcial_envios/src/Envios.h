//#ifndef employee_H_INCLUDED
//#define employee_H_INCLUDED

#ifndef ENVIOS_H_
#define ENVIOS_H_

#define NOMBRE_LEN 51
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999
#define MIN_SUELDO 0
#define MAX_SUELDO 100000
typedef struct
{
	int idEnvio;
	char nombreProducto[NOMBRE_LEN];
	int idCamion;
	char zonaDestino[NOMBRE_LEN];
	float kmRecorridos;
	int tipoEntrega;
	float costoEnvio;
}Envios;

Envios* envios_new();
Envios* envios_newParametros(int idEnvio,char* producto,int idCamion,char* destino, float kmRecorridos, int tipoEntrega, float costoEnvio);
Envios* envios_newParametrosTxt(char* idEnvio,char* producto,char* idCamion,char* destino,char* kmRecorridos,char* tipoEntrega,char* costoEnvio );
void envios_delete(Envios*);

int envios_setIdEnvio(Envios* this,int id);
int envios_getIdEnvio(Envios* this,int* id);
int envios_setIdTxtEnvio(Envios* this, char* id);
int envios_getIdTxtEnvio(Envios* this, char* id);

int envios_setNombre(Envios* this, char* nombre);
int envios_getNombre(Envios* this, char* nombre);

int envios_setIdCamion(Envios* this,int id);
int envios_getIdCamion(Envios* this,int* id);
int envios_setIdTxtCamion(Envios* this, char* id);
int envios_getIdTxtCamion(Envios* this, char* id);

int envios_setZonaDestino(Envios *this, char* zona);
int envios_getZonaDestino(Envios* this, char* zona);

int envios_setKmRecorridos(Envios* this, float kmRecorridos);
int envios_getKmRecorridos(Envios* this, float* kmRecorridos);
int envios_setKmRecorridosTxt(Envios* this, char* kmRecorridos);
int envios_getKmRecorridosTxt(Envios* this, char* kmRecorridos);

int envios_setTipoEntrega(Envios* this, int tipoEntrega);
int envios_getTipoEntrega(Envios* this, int* tipoEntrega);
int envios_setTipoEntregaTxt(Envios* this, char* tipoEntrega);
int envios_getTipoEntregaTxt(Envios* this, char* tipoEntrega);

int envios_setCostoEnvio(Envios* this, float costoEnvio);
int envios_getCostoEnvio(Envios* this, float* costoEnvio);
int envios_setCostoEnvioTxt(Envios* this, char* costoEnvio);
int envios_getCostoEnvioTxt(Envios* this, char* costoEnvio);

int envios_compareByName(void* thisA, void* thisB);

#endif // envios_H_INCLUDED
