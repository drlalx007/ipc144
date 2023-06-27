/*
	==================================================
	Assignment1 Milestone4:
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/

#include "account.h"
#include "accountTicketingUI.h"

void applicationStartup(Account accounts[], int arrSize)
{
	int result = -2;
	while (result != -1)
	{
		result = menuLogin(accounts, arrSize);
		if (result > -1 && accounts[result].acc_type != 'C')
		{
			printf("\n");
			menuAgent(accounts, arrSize, &accounts[result]);
		}
		else if (result > -1 && accounts[result].acc_type == 'C')
		{
			printf("\nCUSTOMER: home menu currently unavailable...\n\n");
			pauseExecution();
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
			printf("\nERROR:  Access Denied.\n\n");
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

void menuAgent(Account accounts[], int arrSize, const Account* account)
{
	int customer_selection = -1;
	//int i = 0;
	while (customer_selection != 0)
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
		printf("0) Logout\n\n");
		printf("Selection: ");
		customer_selection = getIntFromRange(0, 5);
		if (1 == customer_selection)
		{
			int foundFlag = findAccountIndexByAccountNumOfThe(0, accounts, arrSize, 0);

			if (foundFlag < 0)
			{
				printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
				pauseExecution();
			}
			else
			{
				printf("\n");
				getAccount(&accounts[foundFlag]);
				getUserLogin(&accounts[foundFlag].login);
				getDemographic(&accounts[foundFlag].demographic);
				printf("*** New account added! ***\n\n");
				pauseExecution();
				//printf("\n");
			}
		}
		else if (2 == customer_selection)
		{


			int found_flag = findAccountIndexByAccountNumOfThe(0, accounts, arrSize, 1);
			if (found_flag > -1)
			{
				printf("\n");
				updateAccount(&accounts[found_flag]);

			}
			else
			{
				printf("\nERROR:  Access Denied.\n\n");
				pauseExecution();
				//printf("\n");
			}
		}
		else if (3 == customer_selection)
		{
			int found_flag = findAccountIndexByAccountNumOfThe(0, accounts, arrSize, 1);;

			if (found_flag > -1 && accounts[found_flag].acc_no == account->acc_no)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
			}
			else if (found_flag > -1)
			{
				int userInput = ' ';
				//printf("\n");
				displayAccountDetailHeader();
				displayAccountDetailRecord(&accounts[found_flag]);
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				userInput = getCharOption("YN");
				if (userInput == 'Y')
				{
					accounts[found_flag].acc_no = 0;
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
		else if (4 == customer_selection)
		{
			displayAllAccountSummaryRecords(accounts, arrSize);
		}
		else if (5 == customer_selection)
		{
			displayAllAccountDetailRecords(accounts, arrSize);
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

int findAccountIndexByAccountNumOfYour(int account, const Account accounts[], int arrSize, int reAccNum)
{
	int i = 0;
	int flag = 0;
	int return_val = -1;
	if (reAccNum == 1)
	{
		printf("\nEnter your account#: ");
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

int findAccountIndexByAccountNumOfThe(int account, const Account accounts[], int arrSize, int reAccNum)
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


void displayAllAccountSummaryRecords(const Account accounts[], int arrSize)
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

void displayAllAccountDetailRecords(const Account accounts[], int arrSize)
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
			printf("\nEnter the password (must be %d chars in length): ", USERPASS);
			getCString(userInfo->password, USERPASS, USERPASS);
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
			printf("\nEnter the country (30 chars max.): ");
			getCString(demo->country, MINCOUNTRY_NAME, MAXCOUNTRY_NAME);
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