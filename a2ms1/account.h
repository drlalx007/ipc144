/*
	==================================================
	Assignment 2 Milestone 1:
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#ifndef ACOUNT_H_
#define ACCOUNT_H_
#include <stdio.h>

#include "commonHelpers.h"

#define MAXUSER_NAME 10
#define MINUSER_NAME 1
#define MAXUSER_ACC 30
#define MINUSER_ACC 1
#define USERPASS 8
#define MAXYEARS 110
#define MINYEARS 18
#define MAXCOUNTRY_NAME 30
#define MINCOUNTRY_NAME 1

typedef struct Demographic
{
	int birth_year;
	double household_income;
	char country[MAXCOUNTRY_NAME + 1];
}Demographic;

typedef struct UserLogin
{
	char customer_name[MAXUSER_ACC + 1];
	char user_name[MAXUSER_NAME + 1];
	char password[USERPASS + 1];
} UserLogin;


typedef struct Account
{
	int acc_no;
	char acc_type;
	UserLogin login;
	Demographic demographic;
} Account;

void getAccount(Account* a);
void getUserLogin(UserLogin* u);
void getDemographic(Demographic* d);
void displayAccountSummaryHeader(void);
void displayAccountSummaryRecord(const Account* a);
void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const Account* a);


#endif // !ACCOUNT_H_