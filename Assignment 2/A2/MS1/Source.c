//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include <string.h>


// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 1 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n')
		;
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press enter to continue)");
	while (getchar() != '\n')
		;
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int value, valid = 1, check;
	char vc;
	printf("<Please enter an integer>: ");
	do {
		check = scanf("%d%c", &value, &vc);
		if (check == 0) {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
		else if (vc != '\n') {
			printf("*** TRAIL CHAR *** ");
			clearKeyboard();
		}
		else {
			valid = 0;
		}
	} while (valid);
	return value;
}


// getIntInRange: Empty function definition goes here:
int getIntRange(int min, int max)
{
	int inRange;
	int valid = 1;
	printf("<Enter a number between %d and %d>: ", min, max);
	do {
		//get a valid number
		inRange = getInt();
		if (inRange < min || inRange > max) {
			printf(">*** OUT OF RANGE ***> ");

		}
		else {
			valid = 0;
		}
	} while (valid);
	return inRange;
}


// yes: Empty function definition goes here:
int yes(void)
{
	int ans, valid = 1;
	char yesNo;
	do {
		scanf("%c%*c", &yesNo);

		if (yesNo == 'y' || yesNo == 'Y')
		{
			ans = 1;
			valid = 0;
		}
		else if (yesNo == 'n' || yesNo == 'N')
		{
			ans = 0;
			valid = 0;
		}
		else {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	} while (valid);
	return ans;
}

// menu: Empty function definition goes here:
int menu(void)
{
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
	option = getIntRange(0, 6);
	return option;
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int feature, exit;
	feature = menu();
	switch (feature)
	{
	case 1:
		printf("<<< Feature 1 is unavailable >>>\n\n\n");
		pause();
		printf("\n");
		break;
	case 2:
		printf("<<< Feature 2 is unavailable >>>\n\n\n");
		printf("\n");
		pause();
		break;
	case 3:
		printf("<<< Feature 3 is unavailable >>>\n\n\n");
		printf("\n");
		pause();
		break;
	case 4:
		printf("<<< Feature 4 is unavailable >>>\n\n\n");
		pause();
		printf("\n");
		break;
	case 5:
		printf("<<< Feature 5 is unavailable >>>\n\n\n");
		pause();
		printf("\n");
		break;
	case 6:
		printf("<<< Feature 6 is unavailable >>>\n\n\n");
		pause();
		printf("\n");
		break;
	case 0:
		printf("Exit the program? (Y)es/(N)o: ");
		exit = yes();
		if (exit) {
			printf("Contact Management System: terminated\n");
		}
		break;
	default:
		break;
	}
}

void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}
// displayContactHeader does not return a value and has no parameters.
// The details on how this function should work is described in Milestone 4.

void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
}
// displayContactFooter does not return a value and receives one integer parameter.
// The details on how this function should work is described in Milestone 4.


void init_cell(struct Contact contacts[]) {
	int i;
	char init[] = "-1";
	for (i = 0; i < 5; i++) {
		strcpy(contacts[i].numbers.cell, "-1");
	}
}

void getTenDigitPhone(char phoneNum[])
{
	int i = 0, valid = 1;
	char hold;
	scanf("%10[^\n]%c", phoneNum, &hold);
	if (hold != '\n') {
		hold = '\n';
		clearKeyboard();
	}
	while (i < 10)
	{
		if (phoneNum[i] < '0' || phoneNum[i] > '9')
		{
			printf("***INVALID PHONE NUMBER*** <Only 10 Digets>: ");
			scanf("%10[^\n]%c", phoneNum, &hold);
			if (hold != '\n') {
				hold = '\n';
				clearKeyboard();
			}
			i = 0;
		}
		i = i + 1;
	}
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int index = -1;
	while (i < size)
	{
		if (!strcmp(contacts[i].numbers.cell, cellNum))
		{
			index = i;
			break;
		}
		i = i + 1;
	} 
	return index;
}

void displayContact(const struct Contact* contact)
{
	if (!strcmp(contact->name.middleInitial, "-1")) {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	printf("    C: %-10s H: %-10s B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

void displayContacts(const struct Contact contacts[], int size)
{
	displayContactHeader();
	int i = 0, count = 0;
	while (i < size) {
		if (strcmp(contacts[i].numbers.cell, "-1") != 0) {
			displayContact(&contacts[i]);
			count = count + 1;
		}
		i = i + 1;
	}
	displayContactFooter(count);
}

void searchContacts(const struct Contact contacts[], int size)
{
	int index;
	char phone_s[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone_s);
	index = findContactIndex(contacts, size, phone_s);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		displayContact(&contacts[index]);
	}
}

void addContact(struct Contact contacts[], int size)
{
	int i = 0;
	while (i < size)
	{
		if (strcmp(contacts[i].numbers.cell, "-1") == 0)
		{
			break;
		}
		i = i + 1;
	}
	if (i == size) {
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	else
	{
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n\n");
	}
}

int main() {
	int ans;
	struct Contact contacts[5] = { {0} };
	char phoneNum[11];

	init_cell(contacts);

	strcpy(contacts[0].name.firstName, "Bov");
	strcpy(contacts[0].name.middleInitial, "ads");
	strcpy(contacts[0].name.lastName, "Aov");
	strcpy(contacts[0].numbers.cell, "1112223333");
	strcpy(contacts[0].numbers.home, "2223334444");
	strcpy(contacts[0].numbers.business, "3334445555");
	contacts[0].address.streetNumber = 123;
	strcpy(contacts[0].address.street, "asdfasd");
	contacts[0].address.apartmentNumber = 654;
	strcpy(contacts[0].address.city, "asdfa");
	strcpy(contacts[0].address.postalCode, "asdf21");

	strcpy(contacts[1].name.firstName, "Cov");
	strcpy(contacts[1].name.middleInitial, "asd");
	strcpy(contacts[1].name.lastName, "Aov");
	strcpy(contacts[1].numbers.cell, "asdf");
	strcpy(contacts[1].numbers.home, "2223334444");
	strcpy(contacts[1].numbers.business, "3334445555");
	contacts[0].address.streetNumber = 545;
	strcpy(contacts[1].address.street, "asdfasd");
	contacts[1].address.apartmentNumber = -1;
	strcpy(contacts[1].address.city, "asdfa");
	strcpy(contacts[1].address.postalCode, "asdf21");

	strcpy(contacts[2].name.firstName, "tov");
	strcpy(contacts[2].name.middleInitial, "dfg");
	strcpy(contacts[2].name.lastName, "Aov");
	strcpy(contacts[2].numbers.cell, "1112223333");
	strcpy(contacts[2].numbers.home, "2223334444");
	strcpy(contacts[2].numbers.business, "3334445555");
	contacts[2].address.streetNumber = 123;
	strcpy(contacts[2].address.street, "asdfasd");
	contacts[2].address.apartmentNumber = 321;
	strcpy(contacts[2].address.city, "asdfa");
	strcpy(contacts[2].address.postalCode, "asdf21");

	addContact(contacts, 5);
	//displayContact(&contacts[0]);
	//printf("%s", contacts[ans].name.firstName);
	//printf("What number: ");
	//getTenDigitPhone(phoneNum);
	displayContacts(contacts, 5);
	//searchContacts(contacts, 3);

	return 0;
}