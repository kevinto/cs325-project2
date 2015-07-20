/**************************************************************
 * *  Filename: timer.c
 * *  Coded by: Kevin To
 * *  Purpose - To time project 2 algos
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

void executeGreedy(int *inputArray, int numberOfElements, int changeAmount);

// Program entry point
int main()
{
	clock_t timer;  

	// Values for the divide and conquer
	int array_n_vals[16] = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}; // 16 denominations
	// int array_n_vals[7] = {1, 2, 6, 12, 24, 48, 60}; // 7 denominations
	// int array_n_vals[5] = {1, 5, 10, 25, 50}; // 5 denominations

	int initialAmt = 100000000;
	int numberOfIncrements = 20;
	int changeAmount = 0;

	FILE *outputGreedy = fopen("Greedy_Timing_Results.txt", "w");  //create output file for greedy algo

	int i;
	for (i = 0; i < numberOfIncrements; i++)
	{
		changeAmount = (i * initialAmt);
		if (changeAmount == 0)
		{
			continue;
		}

		// Time the greedy algo
		timer = clock();
		executeGreedy(array_n_vals, 16, changeAmount);
		timer = clock() - timer;
		fprintf(outputGreedy, "amount: %d\n", changeAmount);
		fprintf(outputGreedy, "%f\n", (float)timer / (float)CLOCKS_PER_SEC);
	}

	// Close output files
	fclose(outputGreedy);
}


/**************************************************************
 * * Entry:
 * *  inputArray - The input array containing the coin denominations.
 * *  numberOfElements - The number of elements in the array.
 * *  changeAmount - The change amount.
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Executes the Greedy algorithm
 * *
 * ***************************************************************/
void executeGreedy(int *inputArray, int numberOfElements, int changeAmount)
{
	int i;
	int *resultChangeArray = malloc(numberOfElements * sizeof(int));
	for (i = 0; i < numberOfElements; i++)
	{
		resultChangeArray[i] = 0;
	}

	int minNumberOfCoins = 0;
	for (i = numberOfElements - 1; i >= 0; i--)
	{
		while (inputArray[i] <= changeAmount)
		{
			changeAmount -= inputArray[i];
			resultChangeArray[i]++;
			minNumberOfCoins++;
		}
	}

	free(resultChangeArray);
}