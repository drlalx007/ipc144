#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

void getAccount(account* a)
{
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    a->acc_no = getInteger();
    printf("Enter the account type (A=Agent | C=Customer): ");
    a->account_type[0] = getCharOption("AC");
    if (a->account_type[0] == 'A')
    {
        a->account_type[1] = 'G';
        a->account_type[2] = 'E';
        a->account_type[3] = 'N';
        a->account_type[4] = 'T';
    }
    else
    {
        a->account_type[1] = 'U';
        a->account_type[2] = 'S';
        a->account_type[3] = 'T';
        a->account_type[4] = 'O';
        a->account_type[5] = 'M';
        a->account_type[6] = 'E';
        a->account_type[7] = 'R';
    }
}
void getUserLogin(account* a)
{
    int i;
    printf("\n");
    printf("User Login Data Input\n");
    printf("----------------------------------------\n"); // 
    printf("Enter user login (10 chars max): ");
    getCString(a->login.user_name, 3, 10);
    printf("Enter the display name (30 chars max): ");
    getCString(a->login.customer_name, 5, 30);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(a->login.password, 8, 8);
    for ( i = 0; i < 8; i++)
    {
        if (i == 0)
        {
            ;
        }
        else if (i % 2 != 0)
        {
            a->login.password[i] = '*';
        }
        else;
    }
}
void getDemographic(account* a)
{
    printf("\n");
    printf("Demographic Data Input\n");
    printf("----------------------------------------\n"); // 
    printf("Enter birth year (current age must be between 18 and 110): ");
    a->demographic.birth_year = getIntFromRange(1911, 2003);
    printf("Enter the household Income: $");
    a->demographic.income = getDouble();
    if (a->demographic.income <= 0)
    {
        printf("ERROR: Value must be a positive double floating-point number: ");
        a->demographic.income = getPositiveDouble();
    }
    printf("Enter the country (30 chars max.): ");
    getCString(a->demographic.resident_country, 5, 30);
    printf("\n");
}