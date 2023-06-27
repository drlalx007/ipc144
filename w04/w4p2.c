/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_INC 500
#define MAX_INC 400000
#define MAX_ITEMS 10
#include <stdio.h>
int main()
{
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");
	double net_income = 0.0;
	int n = 0;
	int i = 0, k = 0, no_of_yrs = 0, no_of_months = 0;
	int imp[10];//priority of the item
	double item_cost[10];//cost of each item
	double total_cost = 0.0;
	char finance[10];
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &net_income);
		if (net_income <= MIN_INC)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		if (net_income > MAX_INC)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
	} while (net_income <= MIN_INC || net_income > MAX_INC);
	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &n);
		if (n < 1 || n > MAX_ITEMS)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

	} while (n < 1 || n > MAX_ITEMS);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("Item-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &item_cost[i]);
			if (item_cost[i] < 100.0)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (item_cost[i] < 100.0);
		total_cost = total_cost + item_cost[i];
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &imp[i]);
			if (imp[i] < 1 || imp[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (imp[i] < 1 || imp[i]>3);
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &finance[i]);
			if (finance[i] != 'y' && finance[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (finance[i] != 'y' && finance[i] != 'n');
		printf("\n");
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < n; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, imp[i], finance[i], item_cost[i]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", total_cost);
	int selection = 0;
	do
	{
		do
		{
			printf("\nHow do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)\n");
			printf(" 2. By priority\n");
			printf(" 0. Quit/Exit\n");
			printf("Selection: ");
			scanf("%d", &selection);
			if (selection < 0 || selection > 3)
			{
				printf("ERROR: Invalid menu selection.\n");
			}
			if (selection == 1)
			{
				printf("\n====================================================\n");
				printf("Filter:   All items\n");
				printf("Amount:   $%.2lf\n", total_cost);
				no_of_months = (int)(total_cost / net_income);
				no_of_yrs = no_of_months / 12;
				no_of_months = no_of_months % 12;
				printf("Forecast: %d years, %d months\n", no_of_yrs, no_of_months+1);
				for (i = 0; i < n; i++)
				{
					if (finance[i] != 'n')
					{
						k = i;
					}
				}
				if (finance[k] == 'y')
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");
			}
			else if (selection == 2)
			{
				int priority = 0;
				double total = 0;
				do
				{
					printf("\nWhat priority do you want to filter by? [1-3]: ");
					scanf("%d", &priority);
					for (i = 0; i < n; i++)
					{
						if (priority == imp[i])
						{
							total = total + item_cost[i];
						}
						no_of_months = (int)(total / net_income);
						no_of_yrs = no_of_months / 12;
						no_of_months = no_of_months % 12;
					}
					if (priority == 1)
					{
						printf("\n====================================================\n");
						printf("Filter:   by priority (1)\n");
						printf("Amount:   $%.2lf\n", total);
						printf("Forecast: %d years, %d months\n", no_of_yrs, no_of_months+1);
						for (i = 0; i < n; i++)
						{
							if (priority == imp[i] && finance[i] != 'n')
							{
								k = 1;
							}
						}
						if (k == 1)
						{
							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
						}
						printf("====================================================\n");
					}	
					else if (priority == 2)
					{
						printf("\n====================================================\n");
						printf("Filter:   by priority (2)\n");
						printf("Amount:   $%.2lf\n", total);
						printf("Forecast: %d years, %d months\n", no_of_yrs, no_of_months+1);
						k = 0;
						for (i = 0; i < n; i++)
						{
							if (priority == imp[i] && finance[i] != 'n')
							{
								k = 1;
							}
						}
						if (k == 1)
						{
							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
						}
						printf("====================================================\n");
					}
					else if (priority == 3)
					{
						printf("\n====================================================\n");
						printf("Filter:   by priority (3)\n");
						printf("Amount:   $%.2lf\n", total);
						printf("Forecast: %d years, %d months\n", no_of_yrs, no_of_months+1);
						k = 0;
						for( i = 0; i < n; i++)
						{
							if (priority == imp[i] && finance[i] != 'n')
							{
								k = 1;
							}
						} 
						if (k == 1)
						{
							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
						}
						printf("====================================================\n");
					}
					else
					{
						printf("ERROR: Invalid menu selection.\n");
					}	
				} while (priority<1||priority>3);
			}
			else if (selection == 0)
			{
				printf("\nBest of luck in all your future endeavours!\n");
			}
			else
			{
				printf("\nERROR: Invalid menu selection.\n");
			}
		} while (selection < 0 || selection > 2);
	} while (selection != 0);
	return 0;
}