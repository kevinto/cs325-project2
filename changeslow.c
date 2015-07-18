/**************************************************************
 * *  Filename: changeslow.c
 * *  Coded by: Matt Walz
 * *  Purpose - Recursive/Brute-Force method of solving the minimum
 * *    number of coins of provided denominations to make change, k.
 * *
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "filefunctions.h"

int executeAlgorithm(int *inputArray, int *resultChangeArray, int numberOfElements, int changeAmount);

// Program entry point
int main(int argc, char *argv[])
{
	if ( argc != 2 )
	{
		// A file name was not entered as a program argument
		printf( "usage: %s filename\n", argv[0] );
		return 1;
	}
	else
	{
		// Check if file exists
		if (fileExists(argv[1]) == 0)
		{
			printf("Error: File does not exist\n");
			return 1;
		}
		
		int i, j;
		int numberOfElements = 0;
		int changeAmount = 0;
		int lineContainingArray = 0;
		int lineContainingChangeAmount = 0;
		char *inputFileName = argv[1];

		int numberOfLines = numberOfLinesInFile(inputFileName);
		int numberOfProblemsToProcess = numberOfLines / 2;
		int minNumberOfCoins;

		// Run the algorithm problem in the input file. A problem
		//	consists of the array of denominations and the amount
		//  of change.
		for (i = 0; i < numberOfProblemsToProcess; i++)
		{
			lineContainingArray = i + i;
			numberOfElements = getNumberOfElementsInLine(inputFileName, lineContainingArray);

			int *inputArray = malloc(numberOfElements * sizeof(int));
			int *resultChangeArray = malloc(numberOfElements * sizeof(int));
			for (j = 0; j < numberOfElements; j++) {
				resultChangeArray[j] = 0;
			}

			// Fill the input array with the numbers from line i in the file
			fillIntArray(inputFileName, lineContainingArray, inputArray, numberOfElements);

			lineContainingChangeAmount = (2 * i) + 1;
			changeAmount = getChangeAmount(inputFileName, lineContainingChangeAmount);

			minNumberOfCoins = executeAlgorithm(inputArray, resultChangeArray, numberOfElements, changeAmount);

			// Output the result to results file
			outputResultToFile(resultChangeArray, numberOfElements, minNumberOfCoins, inputFileName);
			
			// Cleanup dynamically allocated arrays
			free(inputArray);
			free(resultChangeArray);
		}
	}

	return 0;
}

/**************************************************************
 * * Entry:
 * *  inputArray - The input array containing the coin denominations.
 * *  numberOfElements - The number of elements in the array.
 * *  changeAmount - The change amount.
 * *  inputFileName - The input file name.
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Executes the algorithm
 * *
 * ***************************************************************/
int executeAlgorithm(int *inputArray, int *resultChangeArray, int numberOfElements, int changeAmount)
{
	// Write algorithm here
	int minNumberOfCoins = INT_MAX;
	int i = 0;
	int temp_i;
	int temp_min;
	int temp_changeAmount;
	for (i = 0; i < numberOfElements; i++) {
	    if (inputArray[i] == changeAmount) {
		    resultChangeArray[i] = resultChangeArray[i] + 1;
			minNumberOfCoins = 1;
			return minNumberOfCoins;
		}
		else if (inputArray[i] < changeAmount) {
			temp_changeAmount = changeAmount - inputArray[i];
		    temp_min = 1 + executeAlgorithm(inputArray, resultChangeArray, numberOfElements, temp_changeAmount);
			if (temp_min < minNumberOfCoins) {
				minNumberOfCoins = temp_min;
				temp_i = i;
			}
		}
	}
	resultChangeArray[temp_i] = resultChangeArray[temp_i] + 1;
	return minNumberOfCoins;
}
