/*
	==================================================
	Assignment 2 Milestone 1:
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/

#include "accountTicketingUI.h"
#define arrsize 50
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i;
void applicationStartup(AccountTicketingData* accounttickettingdata)
{
	int result = -2;

	while (result != -1)
	{
		result = menuLogin(accounttickettingdata->accounts, arrsize);
		if (result > -1 && accounttickettingdata->accounts[result].acc_type != 'C')
		{
			printf("\n");
			menuAgent(accounttickettingdata, &accounttickettingdata->accounts[result]);
		}
		else if (result > -1 && accounttickettingdata->accounts[result].acc_type == 'C')
		{
			printf("\n");
			meanucustomer(accounttickettingdata, &accounttickettingdata->accounts[result]);
		}
	}
}

int menuLogin(const Account accounts[], int arrSize)
{
	int return_val = -1;
	char confirm = ' ';
	printf("==============================================\n");
	printf("Account Ticketing System - Login\n");
	printf("==============================================\n");
	printf("1) Login to the system\n");
	printf("0) Exit application\n");
	printf("----------------------------------------------\n\n");
	printf("Selection: ");
	int customer_selection = getIntFromRange(0, 1);
	if (1 == customer_selection)
	{
		int found_flag = findAccountIndexByAccountNumOfYour(0, accounts, arrSize, 1);

		if (found_flag > -1)
		{
			return_val = found_flag;
		}
		else
		{
			return_val = -2;
			printf("\nERROR:  Login failed!\n\n");
			pauseExecution();
		}

	}
	else
	{
		printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
		confirm = getCharOption("yYnN");
		if ('y' == confirm || 'Y' == confirm)
		{
			return_val = -1;
			printf("\n==============================================\n");
			printf("Account Ticketing System - Terminated\n");
			printf("==============================================\n");
		}
		else
		{
			return_val = -2;
		}
		printf("\n");
	}

	return return_val;
}

void menuAgent(AccountTicketingData* accountticketingdata, const Account* account)
{
	int selection = -1;
	//int i = 0;
	while (selection != 0)
	{
		printf("AGENT: %s (%05d)\n", account->login.customer_name, account->acc_no);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: summary view\n");
		printf("5) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("6) List new tickets\n");
		printf("7) List active tickets\n");
		printf("8) Manage a ticket\n");
		printf("9) Archive closed tickets\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 9);
		if (selection == 1)
		{
			int foundFlag = findAccountIndexByAccountNumOfThe(0, accountticketingdata->accounts, arrsize, 0);

			if (foundFlag < 0)
			{
				printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
				pauseExecution();
			}
			else
			{
				printf("\n");
				getAccount(&accountticketingdata->accounts[foundFlag]);
				getUserLogin(&accountticketingdata->accounts[foundFlag].login);
				getDemographic(&accountticketingdata->accounts[foundFlag].demographic);
				printf("*** New account added! ***\n\n");
				pauseExecution();
				//printf("\n");
			}
		}
		else if (selection == 2)
		{


			int found_flag = findAccountIndexByAccountNumOfThe(0, accountticketingdata->accounts, arrsize, 1);
			if (found_flag > -1)
			{
				printf("\n");
				updateAccount(&accountticketingdata->accounts[found_flag]);

			}
			else
			{
				printf("\nERROR:  Access Denied.\n\n");
				pauseExecution();
				//printf("\n");
			}
		}
		else if (selection == 3)
		{
			int found_flag = findAccountIndexByAccountNumOfThe(0, accountticketingdata->accounts, arrsize, 1);;

			if (found_flag > -1 && accountticketingdata->accounts[found_flag].acc_no == account->acc_no)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
			}
			else if (found_flag > -1)
			{
				int userInput = ' ';
				//printf("\n");
				displayAccountDetailHeader();
				displayAccountDetailRecord(&accountticketingdata->accounts[found_flag]);
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				userInput = getCharOption("YN");
				if (userInput == 'Y')
				{
					accountticketingdata->accounts[found_flag].acc_no = 0;
					printf("\n*** Account Removed! ***\n\n");
					pauseExecution();
				}
				else
				{
					printf("\n*** No changes made! ***\n\n");
					pauseExecution();
				}
			}
			else
			{
				printf("\nERROR:  Access Denied.\n\n");
				pauseExecution();
				//printf("\n");
			}
		}
		else if (selection == 4)
		{
			displayAllAccountSummaryRecords(accountticketingdata->accounts, 5);
		}
		else if (selection == 5)
		{
			displayAllAccountDetailRecords(accountticketingdata->accounts, 5);
		}
		else if (selection == 6)
		{
			//printf("\nFeature #6 currently unavailable!\n");
			int selection;
			int index;
			printf("\n");
			do
			{
				index = 0;
				displayBodyOfMessages();
				for (i = 0; accountticketingdata->tickets[i].counter > 0; i++)
				{
					if (accountticketingdata->tickets[i].counter == 1)
					{
						displayMessages(&accountticketingdata->tickets[i]);
					}
				}
				printf("------ ----- --------------- ------ ------------------------------ --------\n");
				printf("\nEnter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				selection = getPositiveInteger();
				for (i = 0; accountticketingdata->tickets[i].ticket_no > 0 && index == 0; i++)
				{
					if (selection == accountticketingdata->tickets[i].ticket_no)
					{
						displaySummary(&accountticketingdata->tickets[i]);
						index = 1;
					}
				}
				if (selection == 0)
				{
					printf("\n");
					goto label;
				}
				if (index == 0 )
				{
					printf("\nERROR: Invalid ticket number.\n\n");
				}
				pauseExecution();
			} while (selection != 0);
		label:;
		}
		else if (selection == 7)
		{
			//printf("\nFeature #7 currently unavailable!\n");
			int selection;
			int index;
			printf("\n");
			do
			{
				index = 0;
				displayBodyOfMessages();
				for (i = 0; accountticketingdata->tickets[i].counter > 0; i++)
				{
					if (accountticketingdata->tickets[i].ticket_indic == 1)
					{
						displayMessages(&accountticketingdata->tickets[i]);
					}
				}
				printf("------ ----- --------------- ------ ------------------------------ --------\n");
				printf("\nEnter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				selection = getPositiveInteger();
				for (i = 0; accountticketingdata->tickets[i].ticket_no > 0 && index == 0; i++)
				{
					if (selection == accountticketingdata->tickets[i].ticket_no)
					{
						displaySummary(&accountticketingdata->tickets[i]);
						index = 1;
					}
				}
				if (selection == 0)
				{
					printf("\n");
					goto labe;
				}
				if (index == 0)
				{
					printf("\nERROR: Invalid ticket number.\n\n");
				}
				pauseExecution();
			} while (selection != 0);
		labe:;
		}
		else if (selection == 8)
		{
			printf("\nFeature #8 currently unavailable!\n");
			printf("\n");
			pauseExecution();
		}
		else if (selection == 9)
		{
			printf("\nFeature #9 currently unavailable!\n");
			printf("\n");
			pauseExecution();
		}
		else
		{
			printf("\n");
			printf("### LOGGED OUT ###\n");
			printf("\n");
			//return;
		}
	}
	return;
}

int findAccountIndexByAccountNumOfYour(int account, const struct Account accounts[], int arrSize, int reAccNum)
{
	int i = 0;
	int flag = 0, flag1 = 0, flag2 = 0, check1, check2;
	char new_login[30] = { '\0' }, password[30]= { '\0' };
	int atempt = 3;
	int return_val = -1;
	do
	{
		if (reAccNum == 1)
		{
			printf("\nEnter the account#: ");
			account = (reAccNum == 1) ? getPositiveInteger() : account;
			printf("User Login    : ");
			getCString(new_login, 1, 30);
			printf("Password      : ");
			getCString(password, 1, 30);
		}
		flag = 0, flag1 = 0, flag2 = 0;
		//account = (reAccNum == 1) ? getPositiveInteger() : account;
		while (i < arrSize && !flag)
		{
			if (account==accounts[i].acc_no)
			{
				flag = 1;
				check1 = strcmp(accounts[i].login.user_name, new_login);
				if (check1 == 0)
				{
					flag1 = 1;
				}
				check2 = strcmp(accounts[i].login.password, password);
				if (check2 == 0)
				{
					flag2 = 1;
				}
			}
			else
			{
				i++;
			}
		}
		return_val = (flag == 1 && flag1 == 1 && flag2 == 1) ? i : -1;
		if (return_val == -1)
		{
			atempt--;
			printf("INVALID user login/password combination! [attempts remaining:%d]\n", atempt);
		}
		else
		{
			atempt = 0;
		}
	} while (atempt > 0);
	return return_val;
}
int findAccountIndexByAccountNumOfThe(int account, const struct Account accounts[], int arrSize, int reAccNum)
{
	int i = 0;
	int flag = 0;
	int return_val = -1;
	if (reAccNum == 1)
	{
		printf("\nEnter the account#: ");
	}
	account = (reAccNum == 1) ? getPositiveInteger() : account;
	while (i < arrSize && !flag)
	{
		if (accounts[i].acc_no == account)
		{
			flag = 1;
		}
		else
		{
			i++;
		}
	}
	return_val = (flag == 1) ? i : -1;
	return return_val;
}


void displayAllAccountSummaryRecords(const struct Account accounts[], int arrSize)
{
	int i = 0;
	printf("\n");
	displayAccountSummaryHeader();
	while (i < arrSize)
	{
		if (accounts[i].acc_no != 0)
		{
			displayAccountSummaryRecord(&accounts[i]);
		}
		i++;
	}
	printf("\n");
	pauseExecution();
}

void displayAllAccountDetailRecords(const struct Account accounts[], int arrSize)
{
	int i = 0;
	printf("\n");
	displayAccountDetailHeader();
	while (i < arrSize)
	{

		if (accounts[i].acc_no != 0)
		{
			displayAccountDetailRecord(&accounts[i]);
		}
		i++;
	}
	printf("\n");
	pauseExecution();
}

void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}

void updateAccount(Account* account)
{
	int selection = -1;
	while (selection != 0)
	{
		printf("Account: %05d - Update Options\n", account->acc_no);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", account->acc_type);
		printf("2) Login\n");
		printf("3) Demographics\n");
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		if (selection == 1)
		{
			printf("\n");
			printf("Enter the account type (A=Agent | C=Customer): ");
			account->acc_type = getCharOption("AC");
			printf("\n");
		}
		else if (selection == 2)
		{
			printf("\n");
			updateUserLogin(&account->login);
			printf("\n");
		}
		else if (selection == 3)
		{
			printf("\n");
			updateDemographic(&account->demographic);
			printf("\n");
		}
		else
		{
			printf("\n");
			//return;
		}
	}
}

void updateUserLogin(UserLogin* userInfo)
{
	int selection = -1;
	while (selection != 0)
	{
		printf("User Login: %s - Update Options\n", userInfo->user_name);
		printf("----------------------------------------\n");
		printf("1) Display name (current value: %s)\n", userInfo->customer_name);
		printf("2) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		if (selection == 1)
		{
			printf("\nEnter the display name (%d chars max): ", MAXUSER_ACC);
			getCString(userInfo->customer_name, MINUSER_ACC, MAXUSER_ACC);
			printf("\n");
		}
		else if (selection == 2)
		{
			printf("\n");
			int s = 0, d = 0, uc = 0, l = 0, i, a;
			do
			{
				s = 0, d = 0, uc = 0, l = 0;
				a = strlen(userInfo->password);
				printf("Enter the password (must be 8 chars in length): ");
				getCString(userInfo->password, USERPASS, USERPASS);
				for (i = 0; i < a; i++)
				{
					if (isdigit(userInfo->password[i]))
						d++;
					else if (isupper(userInfo->password[i]))
						uc++;
					else if (islower(userInfo->password[i]))
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
		else
		{
			//printf("\n");
			//return;
		}
	}
	return;
}

void updateDemographic(Demographic* demo)
{
	int selection = -1;
	while (selection != 0)
	{
		printf("Demographic Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Household Income (current value: $%.2lf)\n", demo->household_income);
		printf("2) Country (current value: %s)\n", demo->country);
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		if (selection == 1)
		{
			printf("\nEnter the household Income: $");
			demo->household_income = getPositiveDouble();
			printf("\n");
		}
		else if (selection == 2)
		{
			int i, a;
			printf("\nEnter the country (30 chars max.): ");
			getCString(demo->country, MINCOUNTRY_NAME, MAXCOUNTRY_NAME);
			a = strlen(demo->country);
			for (i = 0; i < a; i++)
			{
				demo->country[i] = toupper(demo->country[i]);
			}
			printf("\n");
		}
		else
		{
			//printf("\n");
			return;
		}
	}
	return;
}
void meanucustomer(AccountTicketingData* accountticketingdata, const Account* account)
{
	int selection = -1;
	//int i = 0;
	while (selection != 0)
	{
		printf("CUSTOMER: %s (%05d)\n", account->login.customer_name, account->acc_no);
		printf("==============================================\n");
		printf("Customer Main Menu\n");
		printf("==============================================\n");
		printf("1) View your account detail\n");
		printf("2) Create a new ticket\n");
		printf("3) Modify an active ticket\n");
		printf("4) List my tickets\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 4);
		if (selection == 1)
		{
			printf("\n"); 
			displayAccountDetailHeader();
			displayAccountDetailRecord(account);
			printf("\n");
			pauseExecution();
		}
		else if (selection == 2)
		{
			printf("\n"); 
			printf("Feature #2 currently unavailable!\n\n");
			pauseExecution();
		}
		else if (selection == 3)
		{
			printf("\n"); 
			printf("Feature #3 currently unavailable!\n\n");
			pauseExecution();
		}
		else if (selection == 4)
		{
			//printf("Feature #4 currently unavailable!\n\n");
			int selection;
			int index;
			printf("\n");
			do
			{
				index = 0;
				customerBody();
				for (i = 0; i < 5; i++)
				{
					if (accountticketingdata->tickets[i].customer_acc == account->acc_no)
					{
						customerDetails(&accountticketingdata->tickets[i]);
					}
				}
				
				printf("------ ------ ------------------------------ --------\n");
				printf("\nEnter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				selection = getPositiveInteger();
				for (i = 0; accountticketingdata->tickets[i].ticket_no > 0 && index == 0; i++)
				{
					if (selection == accountticketingdata->tickets[i].ticket_no)
					{
						displaySummary(&accountticketingdata->tickets[i]);
						index = 1;
					}
				}
				if (selection == 0)
				{
					printf("\n");
					goto label;
				}
				if (index == 0)
				{
					printf("\nERROR: Invalid ticket number.\n\n");
				}
				pauseExecution();
			} while (selection != 0);
		label:;
		}
		else
		{
			printf("\n");
			printf("### LOGGED OUT ###\n");
			printf("\n");
		}
	}
}
