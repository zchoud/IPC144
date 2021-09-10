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

#include <stdio.h>
#include <string.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name)
{

    char hold;
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf_s("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    
    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%c", name->middleInitial, &hold);
        if (hold != '\n') {
            hold = '\n';
            clearKeyboard();
        }
    }
    else { strcpy(name->middleInitial, "-1"); }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    char hold;
    
    printf("Please enter the contact's street number: ");
    do
    {
        address->streetNumber = getInt();
        if (address->streetNumber < 1) {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
        
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%c", address->street, &hold);
    if (hold != '\n') {
        hold = '\n';
        clearKeyboard();
    }

    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 1) {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
        } while (address->apartmentNumber < 1);
    }
    else { address->apartmentNumber == -1; }

    printf("Please enter the contact's postal code: ");
    getPost(&address->postalCode);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%c", address->city, &hold);
    if (hold != '\n') {
        hold = '\n';
        clearKeyboard();
    }

}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char hold;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    //scanf("%10[^\n]%*c", numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
        //scanf("%10[^\n]%c", numbers->home, &hold);
        
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
        //scanf("%10[^\n]%c", numbers->business, &hold);
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact) {

    getName(&contact->name);
    
    getAddress(&contact->address);
    
    getNumbers(&contact->numbers);
}

