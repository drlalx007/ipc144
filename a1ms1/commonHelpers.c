/*
	==================================================
	Assignment1 Milestone1:
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include "commonHelpers.h"
#include <stdio.h>
#include <time.h>

int i, found = 0;
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}
int getInteger()
{
	int a;
	char newline = 'x';
	scanf("%d%c", &a, &newline);
	clearStandardInputBuffer();
	do
	{
		if ((a <= 0 || a > 0))
		{
			printf("ERROR: Value must be an integer: ");
			scanf("%d%c", &a, &newline);
		}
	} while (!(a <= 0 || a > 0));
	return a;
}
int getPositiveInteger()
{
	int a;
	scanf("%d", &a);
	do
	{
		if (a <= 0)
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
			scanf("%d", &a);
		}

	} while (a <= 0);
	return a;
}
double getDouble()
{
	double a;
	char newline = 'x';
	scanf("%lf%c", &a, &newline);
	clearStandardInputBuffer();
	do
	{
		if (newline != '\n')
		{
			printf("ERROR: Value must be a double floating-point number: ");
			scanf("%lf%c", &a, &newline);
		}

	} while (newline != '\n');
	return a;
}
double getPositiveDouble()
{
	double a;
	scanf("%lf", &a);
	do
	{
		if (a <= 0)
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
			scanf("%lf", &a);
		}

	} while (a <= 0);
	return a;
}
int getIntFromRange(int lower_bound, int upper_bound)
{
	int a;
	char newline = 'x';
	scanf("%d%c", &a, &newline);
	do
	{
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
			scanf("%d%c", &a, &newline);
		}
		if (a < lower_bound || a > upper_bound)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
			scanf("%d%c", &a, &newline);
		}
		
	} while (a < lower_bound || a > upper_bound);
	return a;
}
char getCharOption(char a[])
{
	char input[10];
	scanf("%s", &input[1]);
	do
	{
		found = 0;
		for (i = 0; i < 6; i++)
		{
			if (input[1] == a[i])
			{
				found += 1;
			}
		}
		if (found == 0)
		{
			printf("ERROR: Character must be one of [qwerty]: ");
			scanf("%s", &input[1]);
		}
	} while (found == 0);

	return input[1];
}
char getCString(char *a, int min, int max)
{
	int count = 0;
	if (min == 3)
	{
		char input[30];
		
		for ( i = 0; i < 15; i++)
		{
			scanf("%c", &input[i]);
		}
		for (i = 0; i < max; i++)
		{
			if (input[i] != '\0')
			{
				count++;
			}
		}
		goto label;
	}
	scanf("%30s", a);
	do
	{
		for (i = 0; i < max; i++)
		{
			if (a[i] != '\0')
			{
				count++;
			}
		}
	label:
		if (min==max)
		{
			printf("ERROR: String length must be exactly %d chars: ", max);
			scanf("%30s", a);
		}
		else if (count == max)
		{
			printf("ERROR: String length must be no more than %d chars: ", max);
			scanf("%30s", a);
		}
		else if (count < min)
		{
			printf("ERROR: String length must be between %d and %d chars: ", min, max);
			scanf("%30s", a);
		}
		else
		{
			found += 1;
		}
	} while (found == 0);
	return 0;
}