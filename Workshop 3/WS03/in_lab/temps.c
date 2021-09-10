//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:	
#define NUMS 3
#include <stdio.h>

int main() {
	int high = 0, low = 0, i;
	double mean = 0;
	printf("---=== IPC Temperature Analyzer ===---");
	for (i = 1; i <= NUMS; i++) {
		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &low);
		while (high > 40 || low < -41 || high < low) {
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &low);
		}
		mean = mean + (double) high + (double) low;
	}
	mean = mean / (NUMS * 2);
	printf("\nThe average (mean) temperature was: %.2lf\n", mean);
	return 0;
}