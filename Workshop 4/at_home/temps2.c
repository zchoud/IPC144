//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>
#include <math.h>

int main() {

	//declare variables:
	//number of days, counter
	int days = 0, i = 0, index;

	//array for hi and lo
	int high[10], low[10];

	//array for the max[number, day], min[0][number, day]
	int min[2], max[2];

	//average
	double mean = 0;

	//print title 
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	//ask for number
	printf("Please enter the number of days, between 3 and 10, inclusive: ");

	//start loop, make loop for so long as the final recording day is reached
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
		}
	}

	printf("\n");

	for (i = 0; i <= (days - 1); i++) {
		//take the ith day recoding for high and low [i] at i = day - 1
		do {
			printf("Day %d - High: ", i + 1);
			scanf("%d", &high[i]);
			printf("Day %d - Low: ", i + 1);
			scanf("%d", &low[i]);
			//check if valid
			if (high[i] < low[i])
				printf("\nIncorrect values, high must be greater than low.\n\n");
		} while (high[i] < low[i]);

	}

	max[0] = high[0];
	max[1] = 1;
	min[0] = low[0];
	min[1] = 1;

	//print outputs results using a loop going through each day using i + 1 days
	printf("\nDay  Hi  Low\n");
	for (i = 0; i <= (days - 1); i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
		//look for the highest and lowest
		if (low[i] < min[0]) {
			min[0] = low[i];
			min[1] = i + 1;
		}
		if (high[i] > max[0]) {
			max[0] = high[i];
			max[1] = i + 1;
		}
	}

	//print out the highest and lowest values
	printf("\nThe highest temperature was %d, on day %d\n", max[0], max[1]);
	printf("The lowest temperature was %d, on day %d\n", min[0], min[1]);

	//asking user for averages based on how many days of their choice
	while (1) {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);

		//obtain initial number
		scanf("%d", &index);

		//do they want to exit		
		if (index < 0) {
			printf("\nGoodbye!");
			break;
		}

		//check if number is valid
		while (index > days || index == 0) {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &index);
		}

		//get sum of values
		mean = 0;
		for (i = 0; i <= index - 1; i++) {
			mean = mean + high[i] + low[i];
		}

		//obtain average
		mean = mean / ((double)index * 2);

		//print result
		printf("\nThe average temperature up to day %d is: %.2lf\n", index, mean);
	}

	return 0;
}