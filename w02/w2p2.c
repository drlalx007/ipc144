/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Toonie 200
#define Toonie_str "Toonies" 
#define Loonies 100
#define Loonies_str "Loonies" 
#define Quarter 25
#define Quarter_str "Quarters" 
#define Dimes 10
#define Dimes_str "Dimes" 
#define Nickels 5
#define Nickels_str "Nickels" 
#define Pennies 1
#define Pennies_str "Pennies" 


int cal_coins(int money, int value, char* coin_name)
{
	int coin_value = 0;
	if (money >= value)
	{
		coin_value =(int) (money / value);
		money = money % value;
		printf("$%.2lf %s  X %d (remaining: $%.2lf)\n", (double)value/100, coin_name, coin_value, (double)money/100);
	}
	
	return coin_value;
}

int main()
{
	float d = 0;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%f", &d);
	float service_fee = d * 0.05;
	printf("Service fee (5.0 percent): %.2f\n", service_fee);
	d = d - d * 0.05;
	printf("Balance to dispense: $%.2f\n", d);
	printf("\n");
	int r = d * 100;
	r = r - cal_coins(r, Toonie, Toonie_str) * Toonie;
	r = r - cal_coins(r, Loonies, Loonies_str) * Loonies;
	int coin_value = 0;
	if (r >= Quarter)
	{
		coin_value = r / Quarter;
		r = r % Quarter;
	}
	printf("$%.2lf %s X %d (remaining: $%.2f)\n", (double)Quarter/100, Quarter_str, coin_value, (double)r/100);
	coin_value = 0;
	if (r >= Dimes)
	{
		coin_value = r / Dimes;
		r = r % Dimes;
	}
	printf("$%.2f %s    X %d (remaining: $%.2f)\n",(double) Dimes/100, Dimes_str, coin_value, (double)r/100);
	r = r - cal_coins(r, Nickels, Nickels_str) * Nickels;
	r = r - cal_coins(r, Pennies, Pennies_str) * Pennies;
	printf("\n");
	printf("All coins dispensed!\n");
	return 0;
}