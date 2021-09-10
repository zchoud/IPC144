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

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks. 
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

void validEnd(char hold);

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

void displayContactHeader(void);
// displayContactHeader does not return a value and has no parameters.
// The details on how this function should work is described in Milestone 4.

void displayContactFooter(int count);
// displayContactFooter does not return a value and receives one integer parameter.
// The details on how this function should work is described in Milestone 4.

void displayContact(const struct Contact *contact);
// displayContact does not return a value and receives a constant Contact pointer (cannot be updated) parameter.
// The details on how this function should work is described in Milestone 4.

void displayContacts(const struct Contact contacts[], int size);
// displayContacts does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void searchContacts(const struct Contact contacts[], int size);
// searchContacts does not return a value and receives a constant Contact array (cannot be updated), and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void addContact(struct Contact contacts[], int size);
// addContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void updateContact(struct Contact contacts[], int size);
// updateContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void deleteContact(struct Contact contacts[], int size);
// deleteContact does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void sortContacts(struct Contact contacts[], int size);
// sortContacts does not return a value and receives a Contact array, and an integer for parameters.
// The details on how this function should work is described in Milestone 4.

void getPost(char post[]);
//check if A1A 1A1 format