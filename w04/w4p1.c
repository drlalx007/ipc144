/*
	==================================================
	Workshop #4 (Part-1):
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
#include<string.h>
int main()
{
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");
	double net_income = 0.0;
	int n = 0;
	int imp[10];//priority of the item
	double item_cost[10];
	double total_cost = 0.0;
	char finance[10];
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &net_income);
		if (net_income <= MIN_INC)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		if(net_income > MAX_INC)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");		
	} while (net_income<=MIN_INC||net_income>MAX_INC);
	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &n);
		if (n < 1 || n > MAX_ITEMS)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");

	} while (n < 1||n > MAX_ITEMS);
	int i;
	printf("\n");
	for (i = 0; i < n ; i++)
	{	
		printf("Item-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &item_cost[i]);
			if (item_cost[i] < 100.0)
				printf("      ERROR: Cost must be at least $100.00\n");
		} while (item_cost[i]<100.0);
		total_cost = total_cost + item_cost[i];
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &imp[i]);
			if (imp[i] < 1 || imp[i]>3)
				printf("      ERROR: Value must be between 1 and 3\n");
		} while (imp[i]<1||imp[i]>3);
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &finance[i]);
			if (finance[i] != 'y' && finance[i] != 'n')
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

		} while (finance[i]!='y'&&finance[i]!='n');
		printf("\n");
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for ( i = 0; i < n; i++)
	{
		printf("  %d      %d        %c   ", i + 1, imp[i], finance[i]);
		int temp = (int)item_cost[i] * 100;
		int count = 0;
		while (temp!=0)
		{
			temp /= 10;
			++count;
		}
		count = 11 - count;
		int j;
		for ( j = 0; j <count; j++)
		{
			printf(" ");
		}
		printf("%.2lf\n", item_cost[i]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $ %.2lf\n\n", total_cost);
	printf("Best of luck in all your future endeavours!\n");
	return 0;

}

