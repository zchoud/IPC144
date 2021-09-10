//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Date:           11/30/2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contacts.h"

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

void init_cell(struct Contact contacts[]) {
	int i;
	char init[] = "-1";
	for (i = 0; i < MAXCONTACTS; i++) {
		strcpy(contacts[i].numbers.cell, "-1");
	}
}

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
		while (getchar() != '\n')
			;
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	while (getchar() != '\n')
		;
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int value, valid = 1, check;
	char vc;
	//printf("<Please enter an integer>: ");
	do {
		check = scanf("%d%c", &value, &vc);
		if (vc != '\n') {
			printf("*** TRAIL CHAR *** <Please enter an integer>: ");
			clearKeyboard();
		}
		else if (check == 0) {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else {
			valid = 0;
		}
	} while (valid);
	return value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int inRange;
	int valid = 1;

	do {
		//get a valid number
		inRange = getInt();
		if (inRange < min || inRange > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
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
	char yesNo, check;
	do {
		scanf("%c%c", &yesNo, &check);

		if (check != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else if (yesNo == 'y' || yesNo == 'Y')
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
	option = getIntInRange(0, 6);
	return option;
}


void getTenDigitPhone(char phoneNum[])
{
	int i = 0, valid = 0, check;
	char hold;
	check = scanf("%10[^\n]%c", phoneNum, &hold);
	if (hold != '\n') {
		hold = '\n';
		clearKeyboard();
	}
	while (i < 10)
	{
		if (phoneNum[i] < '0' || phoneNum[i] > '9')
		{
			printf("Enter a 10-digit phone number: ");
			scanf("%10[^\n]%c", phoneNum, &hold);
			if (hold != '\n') {
				hold = '\n';
				clearKeyboard();
			}
			i = -1;
		}
		i = i + 1;
	}
}

//check if A1A 1A1 format
void getPost(char post[])
{
	int i = 0;
	char hold;
	scanf("%7[^\n]%c", post, &hold);
	hold = '\n';
	clearKeyboard();

	while (i < 7)
	{
		if (i == 0 || i == 2 || i == 5) {
			if (post[i] < 'A' || post[i] > 'Z')
			{
				printf("***INVALID POSTAL CODE*** <Only A1A 1A1 format>: ");
				scanf("%7[^\n]%c", post, &hold);
				hold = '\n';
				clearKeyboard();
				i = -1;
			}
		}
		else if (i == 1 || i == 4 || i == 6) {
			if (post[i] < '0' || post[i] > '9')
			{
				printf("***INVALID POSTAL CODE*** <Only A1A 1A1 format>: ");
				scanf("%7[^\n]%c", post, &hold);
				hold = '\n';
				clearKeyboard();
				i = -1;
			}
		}
		else if (i == 3) {
			if (post[i] != ' ')
			{
				printf("***INVALID POSTAL CODE*** <Only A1A 1A1 format>: ");
				scanf("%7[^\n]%c", post, &hold);
				hold = '\n';
				clearKeyboard();
				i = -1;
			}
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

void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
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
// displayContact does not return a value and receives a constant Contact pointer (cannot be updated) parameter.
// The details on how this function should work is described in Milestone 4.

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
// displayContacts does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void searchContacts(const struct Contact contacts[], int size)
{
	int index;
	char phone_s[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone_s);
	index = findContactIndex(contacts, size, phone_s);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		displayContact(&contacts[index]);
	}
}
// searchContacts does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

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
		printf("*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n");
	}
}
// addContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void updateContact(struct Contact contacts[], int size)
{
	int index;
	char phone[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone);
	index = findContactIndex(contacts, MAXCONTACTS, phone);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("Contact found:\n\n");
		displayContact(&contacts[index]);
		printf("Do you want to update the name? (y or n): ");
		if (yes()) {
			getName(&contacts[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes()) {
			getAddress(&contacts[index].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes()) {
			getNumbers(&contacts[index].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
}
// updateContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void deleteContact(struct Contact contacts[], int size)
{
	int index;
	char phone[11];
	printf("Enter a 10-digit phone number: ");
	getTenDigitPhone(phone);
	index = findContactIndex(contacts, MAXCONTACTS, phone);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("Contact found:\n\n");
		displayContact(&contacts[index]);
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes()) {
			strcpy(contacts[index].numbers.cell, "-1");
			printf("--- Contact deleted! ---\n");
		}
	}
}
// deleteContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void sortContacts(struct Contact contacts[], int size)
{
	struct Contact contact_h[5];
	int valid[5] = { -1 }, sum[5] = { 0 };
	int i, j = 0, count = 0, k;

	int min, temp;
	for (i = 0; i < 5; i++) {
		if (strcmp(contacts[i].numbers.cell, "-1") != 0) {
			valid[j] = i;
			for (k = 0; k < 9; k++) {
				sum[j] = sum[j] + contacts[i].numbers.cell[k];
			}
			j = j + 1;
		}
	}
	count = j;

	for (i = 0; i < count; i++) {
		min = Sort(sum, i, count, valid);
		if (min != i)
		{
			temp = sum[i];
			sum[i] = sum[min];
			sum[min] = temp;

			temp = valid[i];
			valid[i] = valid[min];
			valid[min] = temp;
		}
	}
	for (i = 0; i < count; i++) {

		strcpy(contact_h[i].name.firstName, contacts[valid[i]].name.firstName);
		strcpy(contact_h[i].name.middleInitial, contacts[valid[i]].name.middleInitial);
		strcpy(contact_h[i].name.lastName, contacts[valid[i]].name.lastName);
		strcpy(contact_h[i].numbers.cell, contacts[valid[i]].numbers.cell);
		strcpy(contact_h[i].numbers.home, contacts[valid[i]].numbers.home);
		strcpy(contact_h[i].numbers.business, contacts[valid[i]].numbers.business);
		contact_h[i].address.streetNumber = contacts[valid[i]].address.streetNumber;
		strcpy(contact_h[i].address.street, contacts[valid[i]].address.street);
		contact_h[i].address.apartmentNumber = contacts[valid[i]].address.apartmentNumber;
		strcpy(contact_h[i].address.city, contacts[valid[i]].address.city);
		strcpy(contact_h[i].address.postalCode, contacts[valid[i]].address.postalCode);
	}

	for (i = 0; i < count; i++) {

		strcpy(contacts[i].name.firstName, contact_h[i].name.firstName);
		strcpy(contacts[i].name.middleInitial, contact_h[i].name.middleInitial);
		strcpy(contacts[i].name.lastName, contact_h[i].name.lastName);
		strcpy(contacts[i].numbers.cell, contact_h[i].numbers.cell);
		strcpy(contacts[i].numbers.home, contact_h[i].numbers.home);
		strcpy(contacts[i].numbers.business, contact_h[i].numbers.business);
		contacts[i].address.streetNumber = contact_h[i].address.streetNumber;
		strcpy(contacts[i].address.street, contact_h[i].address.street);
		contacts[i].address.apartmentNumber = contact_h[i].address.apartmentNumber;
		strcpy(contacts[i].address.city, contact_h[i].address.city);
		strcpy(contacts[i].address.postalCode, contact_h[i].address.postalCode);
	}

	printf("--- Contacts sorted! ---\n");
}
// sortContacts does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

int Sort(int arr[], int j, int size) {
	int min = j, i = j + 1;
	for (; i < size; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	return min;
}

// contactManagerSystem: Empty function definition goes here:
int contactManagerSystem(void)
{
	struct Contact contacts[5] = { {
								{ "Rick", "-1", "Grimes" },
								{ 11, "Trailer Park", -1, "A7A 2J2", "King City" },
								{ "4161112222", "4162223333", "4163334444" }
								},
								{
								{ "Maggie", "R.", "Greene" },
								{ 55, "Hightop House", -1, "A9A 3K3", "Bolton" },
								{ "9051112222", "9052223333", "9053334444" } },
								{
								{ "Morgan", "A.", "Jones" },
								{ 77, "Cottage Lane", -1, "C7C 9Q9", "Peterborough" },
								{ "7051112222", "7052223333", "7053334444" } },
								{
								{ "Sasha", {"-1"}, "Williams" },
								{ 55, "Hightop House", -1, "A9A 3K3", "Bolton" },
								{ "9052223333", "9052223333", "9054445555" }
								},
								{
								{ "", "-1", "" },
								{ 0, "", -1, "", "" },
								{ "-1", "", "" }
								} };
	int feature, valid = 1;
	while (valid) {
		printf("\n");
		feature = menu();
		printf("\n");
		switch (feature)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);

			break;
		case 2:
			addContact(contacts, MAXCONTACTS);

			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);

			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);

			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);

			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes()) {
				printf("\nContact Management System: terminated");
				valid = 0;
			}
			break;
		default:
			break;
		}
		printf("\n");
		if (valid) {
			pause();
		}
	}
	return 0;
}