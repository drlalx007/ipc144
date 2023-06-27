#define _CRT_SECURE_NO_WARNINGS
#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_
#include <stdio.h>

void displayAccountSummaryHeader();
void displayAccountDetailHeader();
void displayAccountSummaryRecord(const account *a);
void displayAccountDetailRecord(const account* a);
#endif // ACCOUNTTICKETINGUI_H_
