//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>
#include <math.h>

int main(void)
{
    int days = 0;
    char ch = 0;
    printf("How many days left? ");
    scanf("%d", &days);
    ch = days > 1 ? 's' : ' ';
    printf("%d day%c left.\n", days, ch);
    return 0;
}