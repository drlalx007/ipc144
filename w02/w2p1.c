/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   :Daryl Alex
	ID     :143691202
	Email  :dalex4@myseneca.ca
	Section:ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Toonie 2.00
#define Toonie_str "Toonies" 
#define Loonies 1.00
#define Loonies_str "Loonies" 
#define Quarter 0.25
#define Quarter_str "Quarters" 



int cal_coins(double money, double value, char *coin_name)
{
	int coin_value = 0;
	if (money >= value)
	{
		coin_value = money / value;
		money = money - coin_value * value;
	}
		printf("$%.2lf %s  X %d (remaining: $%.2lf)\n",value ,coin_name, coin_value, money);
	return coin_value;
}

int main()
{
	double d=0.0;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf",&d);
	printf("\n");
	d = d - cal_coins(d, Toonie, Toonie_str) * Toonie;
	d = d - cal_coins(d, Loonies, Loonies_str) * Loonies;
	int coin_value = 0;
	if (d >= Quarter)
	{
		coin_value = d / Quarter;
		d = d - coin_value * Quarter;
	}
	printf("$%.2lf %s X %d (remaining: $%.2lf)\n", Quarter, Quarter_str, coin_value, d);
	printf("\n");
	printf("Machine error! Thank you for letting me keep $%.2lf!\n", d);
	return 0;
}