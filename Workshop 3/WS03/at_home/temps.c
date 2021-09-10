//==============================================
// Name:           Zian Choudhury
// Student Number: 131048209
// Email:          zchoudhury@myseneca.ca
// Section:        NVV
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#define NUMS 4
#include<stdio.h>

int main() {
	int high = 0, low = 0, i, min = 0, max = 0, day_l = 0, day_h = 0;
	double mean = 0.0, mean_h = 0.0, mean_l = 0.0;

	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 1; i <= NUMS; i++) {

		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &low);

		if (high > 40 || low < -41 || high < low) { 
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			i = i - 1;
			continue;
		}
		
		if (i == 1) {
			min = low;
			max = high;
			day_l = i;
			day_h = i;
		}
		else {
			if (low < min) {
				min = low;
				day_l = i;
			}
			if (high > max) {
				max = high;
				day_h = i;
			}
		}

		mean_h = mean_h + (double)high;
		mean_l = mean_l + (double)low;
	}
	mean = (mean_l + mean_h) / (NUMS * 2);
	mean_l = mean_l / NUMS;
	mean_h = mean_h / NUMS;
	NUMS = 4;
	printf("\nThe average (mean) LOW temperature was: %.2lf\n", mean_l);
	printf("The average (mean) HIGH temperature was: %.2lf\n", mean_h);
	printf("The average (mean) temperature was: %.2lf\n", mean);
	printf("The highest temperature was %d, on day %d\n", max, day_h);
	printf("The lowest temperature was %d, on day %d\n", min, day_l);
	printf("%d", NUMS);
	return 0;
}