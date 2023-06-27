// ===================================================================================
//  Assignment: 1 
//  Milestone : 2
// ===================================================================================
//  Student Name  : DAryl Alex
//  Student ID    : 143691202
//  Student Email : dalex4@myseneca.ca
//  Course Section: ZBB
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "account.h"                         // *** DO NOT MODIFY THIS LINE ***
#include "commonHelpers.h"                   // *** DO NOT MODIFY THIS LINE ***

// ------------------------------------------------------------------
// Function Prototypes:

// Confirm MS1 stuff still works and grades can be applied to MS1
void commonHelpersTest(void);                   // *** DO NOT MODIFY THIS LINE ***

// Display Account details                              // *** DO NOT MODIFY THIS PROTOTYPE ***
void displayAccount(const struct Account account, const struct UserLogin login, const struct Demographic demo);


// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    struct Account account = { 0 };            // *** DO NOT MODIFY THIS LINE ***
    struct UserLogin login = { {0} };          // *** DO NOT MODIFY THIS LINE ***
    struct Demographic demographic = { 0 };    // *** DO NOT MODIFY THIS LINE ***

    // Declare other variables you may need here:


    printf("Assignment 1 Milestone 2\n");                    // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n\n"); // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Confirm MS1 deliverables - Test commonHelper functions
    // ---------------------------------------------------------
    commonHelpersTest();     // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("Account Data Input\n");                   // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    printf("Enter the account number: ");
    account.acc_no = getInteger();
    printf("Enter the account type (A=Agent | C=Customer): ");
    account.account_type[0] = getCharOption("AC");
    if (account.account_type[0] == 'A')
    {
        account.account_type[1] = 'G';
        account.account_type[2] = 'E';
        account.account_type[3] = 'N';
        account.account_type[4] = 'T';
        //strcpy(account.account_type, "Agent");
    }
    else
    {
        account.account_type[1] = 'U';
        account.account_type[2] = 'S';
        account.account_type[3] = 'T';
        account.account_type[4] = 'O';
        account.account_type[5] = 'M';
        account.account_type[6] = 'E';
        account.account_type[7] = 'R';
        //strcpy(account.account_type, "Customer");
    }
    // Add the necessary code to get user input for each Account member:


    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("\n");
    printf("User Login Data Input\n");                 // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    printf("Enter user login (10 chars max): ");
    getCString(login.user_name, 3, 10);
    printf("Enter the display name (30 chars max): ");
    getCString(login.customer_name, 5, 30);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(login.password, 8, 8);
    // Add the necessary code to get user input for each UserLogin member:


    // ---------------------------------------------------------
    // Demographic Data: get user input
    // ---------------------------------------------------------
    printf("\n");
    printf("Demographic Data Input\n");                // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    printf("Enter birth year (current age must be between 18 and 110): ");
    demographic.birth_year = getIntFromRange(1911, 2003);
    printf("Enter the household Income: $");
    demographic.income = getDouble();
    if (demographic.income <= 0)
    {
        printf("ERROR: Value must be a positive double floating-point number: ");
        demographic.income = getPositiveDouble();
    }
    printf("Enter the country (30 chars max.): ");
    getCString(demographic.resident_country, 5, 30);
    printf("\n");

    // Add the necessary code to get user input for each Demographic member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the 
    //       commonHelpers library that gives you this!


    // ---------------------------------------------------------
    // Display all the entered data
    // ---------------------------------------------------------
    displayAccount(account, login, demographic);
    
    // Call function to display the Account record (see function prototype above and definition below):
    //________________(__________________________________________);

    printf("\nAssignment #1 Milestone #2 completed!\n"); // *** DO NOT MODIFY THIS LINE ***

    return 0; // *** DO NOT MODIFY THIS LINE ***
}


// ------------------------------------------------------------------
// Function definitions:


// Display Account details: Add the missing code!
void displayAccount(const struct Account account, const struct UserLogin login, const struct Demographic demo)
{
    // Give this formatting to the student
    printf("Acct# Acct.Type Birth Household-Income Country         Disp.Name       Login      Password\n");
    printf("----- --------- ----- ---------------- --------------- --------------- ---------- --------\n");
    printf("%05d %-9s %5d $%15.2lf %-15s %-15s %-10s %8s\n", account.acc_no, account.account_type, demo.birth_year, demo.income, demo.resident_country, login.customer_name, login.user_name, login.password);

    // Display the respective data to align to the table header above:
}


// Confirm MS1 stuff still works so grades may be applied to MS1
// *** DO NOT MODIFY THIS FUNCTION DEFINITION ***
void commonHelpersTest(void)
{
    int intValue;
    double dblValue;
    char charValue, cstringValue[7];

    printf("TEST #1: Enter the word 'error' [ENTER], then the number -100: ");
    intValue = getInteger();
    if (intValue == -100)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #2: Enter the number -100 [ENTER], then the number 200: ");
    intValue = getPositiveInteger();
    if (intValue == 200)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #3: Enter the number -4 [ENTER], then 12 [ENTER], then -3: ");
    intValue = getIntFromRange(-3, 11);
    if (intValue == -3)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #4: Enter the word 'error' then, the number -150.75: ");
    dblValue = getDouble();
    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #5: Enter the number -22.11 [ENTER], the number 225.55: ");
    dblValue = getPositiveDouble();
    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #6: Enter the word 'error' then, the number 11: ");
    intValue = getIntFromRange(-3, 11);
    if (intValue == 11)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #7: Enter the character 'R' [ENTER], then 'p' [ENTER], then 'r': ");
    charValue = getCharOption("qwerty");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #8: Enter the word 'horse' [ENTER], then 'SENECA': ");
    getCString(cstringValue, 6, 6);
    printf("Your Result: %s (Answer: SENECA)\n\n", cstringValue);

    printf("TEST #9: Enter the words 'Seneca College' [ENTER], then 'IPC': ");
    getCString(cstringValue, 3, 6);
    printf("Your Result: %s (Answer: IPC)\n\n", cstringValue);

    printf("TEST #10: Enter the words 'ipc' [ENTER], then 'SCHOOL': ");
    getCString(cstringValue, 4, 6);
    printf("Your Result: %s (Answer: SCHOOL)\n\n", cstringValue);
}