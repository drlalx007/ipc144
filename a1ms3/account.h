// ===================================================================================
//  Assignment: 1 
//  Milestone : 3
// ===================================================================================
//  Student Name  : DAryl Alex
//  Student ID    : 143691202
//  Student Email : dalex4@myseneca.ca
//  Course Section: ZBB
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <stdio.h>
typedef struct Demographic {
	int birth_year;
	double income;
	char resident_country[200];
}demographic;
typedef struct UserLogin {
	char customer_name[200];
	char user_name[200];
	char password[200];
}userlogin;
typedef struct Account {
	int acc_no;
	char account_type[200];
	demographic demographic;
	userlogin login;
}account;
void getAccount(account* a);
void getUserLogin(account* a);
void getDemographic(account* a);
#endif // !ACCOUNT_H_