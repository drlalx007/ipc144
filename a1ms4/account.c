/*
    ==================================================
    Assignment1 Milestone4:
    ==================================================
    Name   : Daryl Alex
    ID     : 143691202
    Email  : dalex4@myseneca.ca
    Section: ZBB
*/

#include "commonHelpers.h"
#include "account.h"


void getAccount(Account* a)
{
    printf("Account Data: New Record\n");                   // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    // Add the necessary code to get user input for each Account member:
    printf("Enter the account number: ");
    a->acc_no = getPositiveInteger();
    printf("\nEnter the account type (A=Agent | C=Customer): ");
    a->acc_type = getCharOption("AC");
    printf("\n");
}

void getUserLogin(UserLogin* u)
{
    printf("User Login Data Input\n");                 // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each UserLogin member:
    printf("Enter user login (10 chars max): ");
    getCString(u->user_name, MINUSER_NAME, MAXUSER_NAME);
    printf("Enter the display name (30 chars max): ");
    getCString(u->customer_name, MINUSER_ACC, MAXUSER_ACC);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(u->password, USERPASS, USERPASS);
    printf("\n");
}

void getDemographic(Demographic* demoPtr)
{
    // Demographic Data: get user input
    // ---------------------------------------------------------
    printf("Demographic Data Input\n");                // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Demographic member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the 
    //       commonHelpers library that gives you this!
    printf("Enter birth year (current age must be between %d and %d): ", MINYEARS, MAXYEARS);
    demoPtr->birth_year = getIntFromRange(currentYear() - MAXYEARS, currentYear() - MINYEARS);
    printf("Enter the household Income: $");
    demoPtr->household_income = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    getCString(demoPtr->country, MINCOUNTRY_NAME, MAXCOUNTRY_NAME);
    printf("\n");
}

void displayAccountSummaryHeader(void)
{
    printf("Acct# Acct.Type Birth\n");
    printf("----- --------- -----\n");
}


void displayAccountSummaryRecord(const Account* a)
{
    printf("%5d %-9s %5d\n", a->acc_no, a->acc_type == 'C' ? "CUSTOMER" : "AGENT", a->demographic.birth_year);
}

void displayAccountDetailHeader(void)
{
    printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountDetailRecord(const Account* a)
{
    int i = 0;
    char temppass[USERPASS + 1] = { 0 };
    for (i = 0; i < 8; i++)
    {
        if (i % 2)
        {
            temppass[i] = '*';
        }
        else
        {
            temppass[i] = a->login.password[i];
        }
    }
    printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", a->acc_no, a->acc_type == 'C' ? "CUSTOMER" : "AGENT", a->demographic.birth_year, a->demographic.household_income, a->demographic.country, a->login.customer_name, a->login.user_name, temppass);
}
