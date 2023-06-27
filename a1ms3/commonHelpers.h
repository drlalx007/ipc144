#define _CRT_SECURE_NO_WARNINGS
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#include <stdio.h>
int getInteger();
int getPositiveInteger();
double getDouble();
double getPositiveDouble();
int getIntFromRange(int lower_bound, int upper_bound);
char getCharOption(char a[]);
char getCString(char* a, int min, int max);
int currentYear(void);
void clearStandardInputBuffer(void);

#endif // !COMMON_HELPERS_H_
