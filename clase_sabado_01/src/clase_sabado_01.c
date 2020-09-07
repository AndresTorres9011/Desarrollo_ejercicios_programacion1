/*
 ============================================================================
 Name        : clase_sabado_01.c
 Author      : Torres Andres
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Sin funciones:
para realizar un pedido, solicitar tres datos, iterar 5 veces
código de tipo int , validar entre 100 y 200
cantidad de tipo entero(int), validar entre 1 y 20
una talle de tipo char validad entre('S' , 'M' , 'L')
a-mostrar el código y el talle  del que mas cantidad solicito
b-el promedio del total  de cantidades de talle 'M' con decimales
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int codigo;
	int cantidad;
	char talle;
	int respuestaScan;
	int codigoMasCantidad;
	int talleMasCantidad;
	int acumuladorTalleS=0;
	int contadorTalleM=0;
	int acumuladorTalleM=0;
	int acumuladorTalleL=0;
	float promedioTalleM;

	for(int i=0;i<5;i=i+1)
	{
		printf("Ingrese codigo:");
		fflush(stdin);
		respuestaScan=scanf("%d",&codigo);
		while((respuestaScan==0) || codigo>200 || codigo<100)
		{
			printf("Reingrese codigo:");
			fflush(stdin);
			respuestaScan=scanf("%d",&codigo);
		}

		printf("Ingrese cantidad:");
		fflush(stdin);
		respuestaScan=scanf("%d",&cantidad);
		while(!(respuestaScan==1 && cantidad>=1 && cantidad<=20))
		{
			printf("Reingrese cantidad:");
			fflush(stdin);
			respuestaScan=scanf("%d",&cantidad);
		}

		printf("Ingrese talle (s-m-l):");
		fflush(stdin);
		respuestaScan=scanf("%c",&talle);
		while(respuestaScan==1 && talle!='s' && talle!='m' && talle!='l')
		{
			printf("Reingrese talle:");
			fflush(stdin);
			respuestaScan=scanf("%c",&talle);
		}

		switch(talle)
		{
		   	 case's':
		   		 acumuladorTalleS=acumuladorTalleS+cantidad;
		   	 break;
		   	 case'm':
		   		 acumuladorTalleM=acumuladorTalleM+cantidad;
		   		 contadorTalleM=contadorTalleM+1;
		     break;
		   	 case'l':
		   		 acumuladorTalleL=acumuladorTalleL+cantidad;
		   	 break;
		}
	}

	if(acumuladorTalleS>acumuladorTalleM && acumuladorTalleS>acumuladorTalleL)
	{
		codigoMasCantidad=codigo;
		talleMasCantidad='s';
	}
	else
	{
		if(acumuladorTalleL>acumuladorTalleS)
		{
			codigoMasCantidad=codigo;
			talleMasCantidad='l';
		}
		else
		{
			codigoMasCantidad=codigo;
			talleMasCantidad='m';
		}
	}

	printf("El codigo del articulo mas solicitado es: %d",codigoMasCantidad);
	printf("\nEl talle del articulo mas solicitado es: %c",talleMasCantidad);

	if(contadorTalleM>0)
	{
		promedioTalleM=(float)acumuladorTalleM/contadorTalleM;
		printf("\nEl promedio total de cantidades de talle m es: %.2f",promedioTalleM);

	}
	else
	{
		printf("\nNo solicito talle m.");
	}

	/*a-mostrar el código y el talle  del que mas cantidad solicito
	b-el promedio del total  de cantidades de talle 'M' con decimales
	*/

	return EXIT_SUCCESS;
}
