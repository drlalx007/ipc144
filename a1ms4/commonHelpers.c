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
#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; //do nothing as not defined in assignment
	}
}

int getInteger(void)
{
	int input = 0;
	char newline = 0;
	int valid_flag = 0;
	do
	{

		scanf("%d%c", &input, &newline);
		if (newline == '\n')
		{
			valid_flag = 1;
		}
		else
		{
			printf("ERROR: Value must be an integer: ");
			clearStandardInputBuffer();
		}
	} while (valid_flag == 0);
	return input;
}

int getPositiveInteger(void)
{
	int input = 0;
	int valid_flag = 0;
	while (!valid_flag)
	{
		input = getInteger();
		if (input > 0)
		{
			return input;
		}
		else
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	}
	return 0;
}

int  getIntFromRange(int lower, int upper)
{
	int input = 0;
	int flag = 0;
	do
	{
		input = getInteger();
		if (input >= lower && input <= upper)
		{
			flag = 1;
		}
		else
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", lower, upper);
		}
	} while (flag == 0);
	return input;
}

double  getDouble(void)
{
	double input = 0;
	char newline = 0;
	int valid_flag = 0;
	do
	{

		scanf("%lf%c", &input, &newline);
		if (newline == '\n')
		{
			valid_flag = 1;
		}
		else
		{
			printf("ERROR: Value must be a double floating-point number: ");
			clearStandardInputBuffer();
		}
	} while (valid_flag == 0);
	return input;
}

double getPositiveDouble(void)
{
	double input = 0;
	int flag = 0;
	while (!flag)
	{
		input = getDouble();
		if (input > 0)
		{
			return input;
		}
		else
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	}
	return 0;
}

char getCharOption(const char* str_input)
{
	char char_input = 0;
	char newline = 0;
	int flag = 0;
	int i = 0;
	do
	{
		scanf("%c%c", &char_input, &newline);
		if (newline == '\n')
		{
			i = 0;
			while (str_input[i] != 0 && flag == 0)
			{
				if (str_input[i] == char_input)
				{
					flag = 1;
				}
				else
				{
					i++;
				}
			}
		}
		else
		{
			clearStandardInputBuffer();
		}
		if (flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", str_input);
		}
	} while (flag == 0);
	return char_input;
}

void getCString(char* cstring_input, int lower, int upper)
{
	char newline = 0;
	int valid_flag = 0;
	int terminatd_flag = 0;
	char input[100];
	int count = 0;
	int i = 0;
	do
	{
		scanf("%[^\n]%c", input, &newline);
		if (newline == '\n')
		{
			count = 0;
			valid_flag = 0;
			while (valid_flag == 0)
			{
				if (input[count] == 0)
				{
					valid_flag = 1;
				}
				else
				{
					count++;
				}
			}
			if (count >= lower && count <= upper)
			{
				for (i = 0; i < count; i++)
				{
					cstring_input[i] = input[i];
				}
				cstring_input[count] = 0;
				terminatd_flag = 1;
			}
			else if (count != lower && upper == lower)
			{
				printf("ERROR: String length must be exactly %d chars: ", lower);

			}
			else if (count > upper)
			{
				printf("ERROR: String length must be no more than %d chars: ", upper);
			}
			else
			{
				printf("ERROR: String length must be between %d and %d chars: ", lower, upper);

			}

		}

	} while (terminatd_flag == 0);
	return;
}