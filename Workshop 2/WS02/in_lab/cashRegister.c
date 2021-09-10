//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>

int main() {
	double cost;
	int loonies=0, quarters=0;
	printf("Please enter the amount to be paid:\n$");
	scanf("%lf", &cost);
	/*while (cost >= 1.0) {
		cost = cost - 1;
		loonies += 1;
	}
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, cost);
	while (cost >= 0.25) {
		cost = cost - 0.25;
		quarters += 1;
	}
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, cost);
	*/
	loonies = cost;
	printf("%d", loonies);
	return 0;
}