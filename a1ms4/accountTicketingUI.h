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
#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_0
#include <stdio.h>

void applicationStartup(Account accounts[], int arrSize);
int menuLogin(const Account accounts[], int arrSize);
void menuAgent(Account accounts[], int arrSize, const Account* account);


int findAccountIndexByAccountNumOfYour(int account, const Account accounts[], int arrSize, int needAcctNum);

int findAccountIndexByAccountNumOfThe(int account, const Account accounts[], int arrSize, int needAcctNum);

void displayAllAccountSummaryRecords(const Account accounts[], int arrSize);

void displayAllAccountDetailRecords(const Account accounts[], int arrSize);

void pauseExecution(void);

void updateAccount(Account* account);

void updateUserLogin(UserLogin* userInfo);

void updateDemographic(Demographic* demo);
#endif // ACCOUNTTICKETINGUI_H_