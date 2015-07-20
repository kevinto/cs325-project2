/**************************************************************
 * *  Filename: timer.c
 * *  Coded by: Frank Eslami 
 * *  Purpose - Timer changedp inputs 
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

void executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount);

// Program entry point
int main()
{
	clock_t timer;  

	// Values for the divide and conquer
//	int array_n_vals[] = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}; //v1 = prob 6
//	int array_n_vals[] = {1, 2, 6, 12, 24, 48, 60};	//v2 = prob 5 v1
//	int array_n_vals[] = {1, 6, 13, 37, 150};	//v3 = prob 5 v2
	int array_n_vals[] = {1, 5, 10, 25, 50};	//v4 = prob 4 

	int arr_size = sizeof(array_n_vals) / sizeof(array_n_vals[0]);
	printf("size = %d\n", arr_size);
	int initialAmt = 1000000;
	int numberOfIncrements = 19;
	int changeAmount = 0;

	FILE *output_file = fopen("changedp_time_Results.txt", "w");  //create output file for greedy algo

	int i;
	for (i = 1; i <= numberOfIncrements; i++)
	{
		changeAmount = (i * initialAmt);

		// Time the greedy algo
		timer = clock();
		executeAlgorithm(array_n_vals, arr_size, changeAmount);
		timer = clock() - timer;
		float time_amount = (float)timer / (float)CLOCKS_PER_SEC;
		printf("%d = %.2f\n", changeAmount, time_amount);
		fprintf(output_file, "%d = %.2f\n", changeAmount, time_amount); 
	}

	// Close output files
	fclose(output_file);
}

void executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount){
    // Write algorithm here
    int i, j;
    int *C = malloc( (changeAmount + 1) * sizeof(int));
    int *minArrIndex = malloc( (changeAmount + 1) * sizeof(int));

    C[0] = 0;   //base case
    for (i = 1; i <= changeAmount; i++) {
        C[i] = INT_MAX;
        for (j = 0; j < numberOfElements; j++) {
            if (i >= inputArray[j] && (1 + C[i - inputArray[j]]) < C[i]) {
                C[i] = 1 + C[i - inputArray[j]];
                minArrIndex[i] = j;
            }
        }
    }
    int minNumberOfCoins = C[changeAmount];
}

