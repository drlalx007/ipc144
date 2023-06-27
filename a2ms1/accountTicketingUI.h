/*
	==================================================
	Assignment 2 Milestone 1:
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
#include "account.h"
#include "ticket.h"
void applicationStartup(AccountTicketingData* accounttickettingdata);
int menuLogin(const Account accounts[], int arrSize);
void menuAgent(AccountTicketingData* accountticketingdata, const Account* account);
int findAccountIndexByAccountNumOfYour(int account, const Account accounts[], int arrSize, int needAcctNum);
int findAccountIndexByAccountNumOfThe(int account, const Account accounts[], int arrSize, int needAcctNum);
void displayAllAccountSummaryRecords(const Account accounts[], int arrSize);
void displayAllAccountDetailRecords(const Account accounts[], int arrSize);
void pauseExecution(void);
void updateAccount(Account* account);
void updateUserLogin(UserLogin* userInfo);
void updateDemographic(struct Demographic* demo);
void meanucustomer(AccountTicketingData* accountticketingdata, const Account* account);


#endif // ACCOUNTTICKETINGUI_H_