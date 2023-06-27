/*
    ==================================================
    Assignment 2 Milestone 1:
    ==================================================
    Name   : Daryl Alex
    ID     : 143691202
    Email  : dalex4@myseneca.ca
    Section: ZBB
*/

#include "commonHelpers.h"
#include "account.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i;

void getAccount(Account* a)
{
    printf("New Account Data (Account#:50600)\n");                   // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    // Add the necessary code to get user input for each Account member:
    //printf("Enter the account number: ");
    a->acc_no = 50600;
    printf("Enter the account type (A=Agent | C=Customer): ");
    a->acc_type = getCharOption("AC");
    printf("\n");
}

void getUserLogin(UserLogin* u)
{
    printf("User Login Data Input\n");                 // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    int s = 0, d = 0, uc = 0, l = 0, a;
    // Add the necessary code to get user input for each UserLogin member:
    do
    {
        s = 0;
        printf("Enter user login (10 chars max): ");
        getCString(u->user_name, MINUSER_NAME, MAXUSER_NAME);
        a = strlen(u->user_name);
        for (i = 0; i < a; i++)
        {
            if (u->user_name[i] == ' ')
                s += 1;
        }
        if (s > 0)
        {
            printf("ERROR:  The user login must NOT contain whitespace characters.\n");
        }
    } while (s > 0);
    printf("Enter the display name (30 chars max): ");
    getCString(u->customer_name, MINUSER_ACC, MAXUSER_ACC);
    do
    {
        s = 0, d = 0, uc = 0, l = 0;
        a = strlen(u->password);
        printf("Enter the password (must be 8 chars in length): ");
        getCString(u->password, USERPASS, USERPASS);
        for (i = 0; i < a; i++)
        {
            if (isdigit(u->password[i]))
               d++;
            else if (isupper(u->password[i]))
               uc++;
            else if (islower(u->password[i]))
               l++;
            else
               s++;
        }
        if (s != 2 || d != 2 || l != 2 || uc != 2)
        {
            printf("SECURITY: Password must contain 2 of each:\n");
            printf("          Digit: 0-9\n");
            printf("          UPPERCASE character\n");
            printf("          lowercase character\n");
            printf("          symbol character: !@#$%%^&*\n");
        }
    } while (s != 2 || d != 2 || l != 2 || uc != 2);
    printf("\n");
}

void getDemographic(Demographic* demoPtr)
{
    int a;
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
    a = strlen(demoPtr->country);
    for ( i = 0; i < a; i++)
    {
       demoPtr->country[i]=toupper(demoPtr->country[i]);
    }
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
void displayBodyOfMessages(void)
{
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
    printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
}
void displayMessages(const struct Ticket* t)
{
    printf("%06d %05d %-15s %-6s %-30s  %4d\n", t->ticket_no, t->customer_acc,t->message->customer_name, t->ticket_indic == 0 ? "CLOSED" : "OPEN", t->subject_line, t->counter);
}
void displaySummary(const struct Ticket* t)
{
    printf("\n================================================================================\n");
    printf("%06d (%-4s) Re: %s\n", t->ticket_no, t->ticket_indic == 0 ? "CLOSED" : "OPEN", t->subject_line);
    printf("================================================================================\n");
    for (i = 0; i < t->counter; i++)
    {
        printf("%s (%s):\n", t->message[i].acc_type == 'C' ? "CUSTOMER" : "AGENT", t->message[i].customer_name);
        printf("   %s\n\n", t->message[i].message);
    }
}
void customerBody()
{
    printf("------ ------ ------------------------------ --------\n");
    printf("Ticket Status Subject                        Messages\n");
    printf("------ ------ ------------------------------ --------\n");
}
void customerDetails(const struct Ticket* t)
{
    printf("%06d %-6s %-30s  %4d\n", t->ticket_no, t->ticket_indic == 0 ? "CLOSED" : "OPEN", t->subject_line, t->counter);
}