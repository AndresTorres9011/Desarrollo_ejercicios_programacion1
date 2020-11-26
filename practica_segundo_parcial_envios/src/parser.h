/*
 * parser.h
 *
 *  Created on: 3/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

int parser_enviosFromText(FILE* pFile , LinkedList* pArrayListEnvios);
int parser_enviosFromBinary(FILE* pFile , LinkedList* pArrayListEnvios);

int parser_enviosToText(FILE* pFile , LinkedList* pArrayListEnvios);
int parser_enviosToBinary(FILE* pFile , LinkedList* pArrayListEnvios);

