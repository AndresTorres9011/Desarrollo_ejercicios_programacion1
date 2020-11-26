/*
 * validations.h
 *
 *  Created on: 25/11/2020
 *       Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int isValidName(char* string, int len);
int isValidLetters(char* string, int len);
int isValidNumber(char* num, int len);
int isValidNumberFloat(char* num,int len);
int isValidAlphaNumeric(char* string, int len);
int isValidDocumentNumber(char* string, int len);
int isValidMail(char* string, int len);
int isValidCuit(char* string);

#endif /* VALIDATIONS_H_ */
