//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main() {

	//declare variables:
	//number of days, counter 
	int days = 0, i = 0;

	//array for high and low
	int high[10], low[10];
	
	//print title 
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	
	//ask for number
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	//obtain valid number
	while (1) {
		scanf("%d", &days);
		//check if number is valid
		//if valid exit loop
		if (days >= 3 && days <= 10) {
			break;
		}
		//if not vailid stay in loop and re-enter
		else {
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			continue;
		}
	}
	printf("\n");
	
	//start loop, make loop for so long as the final recording day is reached
	for (i = 0; i <= (days - 1); i++) {
		//take the ith day recoding for high and low [i] at i = day - 1
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	
	//print outputs results using a loop going through each day using i + 1 days
	printf("\nDay  Hi  Low\n");
	for (i = 0; i <= (days - 1); i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}

	return 0;
}
/*scanf("%d", &days);
	//check if number is valid	
	if (days >= 3 && days <= 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}*/