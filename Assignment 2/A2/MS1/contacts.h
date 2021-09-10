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


//--------------------------------
// Structure Types
//--------------------------------

// Structure type Name declaration (Milestone 1)
struct Name
{
    char firstName[31];
    // char middleInitial[5]; // <- NO! Must accommodate 6 character + null terminator byte = 7
    char middleInitial[15];
    char lastName[36];
};

// Structure type Address declaration (Milestone 1)
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration (Milestone 1)
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration (Milestone 3)
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name);

// Get and store from standard input the values for Address
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);

// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 1 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function prototypes here...              |
// +-------------------------------------------------+

void getContact(struct Contact* contact);

// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 3 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

void getTenDigitPhone(char phoneNum[]);