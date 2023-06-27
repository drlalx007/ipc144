/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3

int main()
{
	const int JAN = 1;
	const int DEC = 12;
	int year = 0;
	int	month = 0;
	float r = 0.0;
	float tm = 0.0, te = 0.0, otr, atr;
	float am, ae;
	printf("General Well-being Log\n");
	printf("======================\n");
	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);
		if (year >= MIN_YEAR && year <= MAX_YEAR && month >= 1 && month <= 12)
		{
			printf("\n*** Log date set! ***\n");

		}
		if (year < 2010 || year>2021)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (month > DEC || month < JAN)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}

	} while (year < 2010 || year>2021 || month > DEC || month < JAN);
	
	int i;
	for (i = 0; i < LOG_DAYS; i++)
	{
		switch (month)
    	{
		case 1:printf("\n%d-JAN-0%d\n", year,i+1);
		break;
		case 2:printf("\n%d-FEB-0%d\n", year, i + 1);
		break;
		case 3:printf("\n%d-MAR-0%d\n", year, i + 1);
		break;
		case 4:printf("\n%d-APR-0%d\n", year, i + 1);
		break;
		case 5:printf("\n%d-MAY-0%d\n", year, i + 1);
		break;
		case 6:printf("\n%d-JUN-0%d\n", year, i + 1);
		break;
		case 7:printf("\n%d-JUL-0%d\n", year, i + 1);
		break;
		case 8:printf("\n%d-AUG-0%d\n", year, i + 1);
		break;
		case 9:printf("\n%d-SEP-0%d\n", year, i + 1);
		break;
		case 10:printf("\n%d-OCT-%d\n", year, i + 1);
		break;
		case 11:printf("\n%d-NOV-0%d\n", year, i + 1);
		break;
		case 12:printf("\n%d-DEC-0%d\n", year, i + 1);
		break;
		default:
		break;
	}


		do
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%f", &r);
			if (r < 0.0 || r > 5.01)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (r < 0.0 || r > 5.01);
		tm = tm + r;
		do
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf("%f", &r);
			if (r < 0 || r > 5.01)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		}while (r < 0.0 || r > 5.01);
		te = te + r;
	}
	otr = te + tm;
	am = tm / i;
	am =(int) (am * 10+.5);
	ae = te / i;
	ae = (int)(ae * 10 + .5);
	atr = (ae + am) / 2;
	printf("\nSummary\n=======\n");
	printf("Morning total rating: %.3f\n",tm);
	printf("Evening total rating: %.3f\n",te);
	printf("----------------------------\n");
	printf("Overall total rating: %.3f\n\n",otr);
	printf("Average morning rating:  %.1f\n",(float)am/10);
	printf("Average evening rating:  %.1f\n",(float)ae/10);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1f\n",atr/10);	
	return 0;

}

