/*
 * parser.h
 *
 *  Created on: 25/11/2020
 *      Author: Vivi Herrera
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_clientFromText(FILE* pFile , LinkedList* clientList);
int parser_sellFromText(FILE* pFile , LinkedList* sellList);

#endif /* PARSER_H_ */
