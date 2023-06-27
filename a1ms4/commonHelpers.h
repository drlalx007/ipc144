/*
	==================================================
	Assignment1 Milestone4:
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#include <time.h>
#include <stdio.h>
int currentYear(void);

void clearStandardInputBuffer(void);

int getInteger(void);

int getPositiveInteger(void);

int  getIntFromRange(int lower, int upper);

double  getDouble(void);

double getPositiveDouble(void);

char getCharOption(const char* str_input);

void getCString(char* cstringValue, int lower, int upper);
#endif // !COMMON_HELPERS_H_
