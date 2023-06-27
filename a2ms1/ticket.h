#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#ifndef TICKET_H_
#define TICKET_H_
typedef struct Message {
	char acc_type;
	char customer_name[30];
	char message[150];
}Message;
typedef struct Ticket {
	int ticket_no;
	int customer_acc;
	int ticket_indic;
	char subject_line[30];
	int counter;
	struct Message message[20];
}ticket;
typedef struct AccountTicketingData
{
	struct Account* accounts; // array of accounts
	const int ACCOUNT_MAX_SIZE; // maximum elements for account arrayy
	struct Ticket* tickets
		; // array of tickets
	const int TICKET_MAX_SIZE; // maximum elements for ticket array
}AccountTicketingData;

#endif // !TICKET_H_

