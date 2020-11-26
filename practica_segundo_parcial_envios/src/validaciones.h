/*
 * validations.h
 *
 *  Created on: 3/11/2020
 *      Author: Vivi Herrera
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int isValidCompoundName(char* string, int len);
int isValidLetters(char* string, int len);
int isValidNumber(char* num, int len);
int isValidNumberFloat(char* num,int len);
int isValidAlphaNumeric(char* string, int len);
int isValidDocumentNumber(char* string, int len);
int isValidMail(char* string, int len);

#endif /* VALIDACIONES_H_ */
