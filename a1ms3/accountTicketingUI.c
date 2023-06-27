#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

void displayAccountSummaryHeader()
{
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");

}
void displayAccountDetailHeader()
{
	printf("\nAcct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

}
void displayAccountSummaryRecord(const account* a)
{
	printf("%05d %-9s %5d\n", a->acc_no, a->account_type, a->demographic.birth_year);
}
void displayAccountDetailRecord(const account* a)
{
	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s", a->acc_no, a->account_type, a->demographic.birth_year, a->demographic.income, a->demographic.resident_country, a->login.customer_name, a->login.user_name, a->login.password);
}