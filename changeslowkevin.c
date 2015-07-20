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

int executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount, int cw, int cm, int *lowestDepth, int *currLowestDepth);
void resetArrays(int *array, int arrLen);
void pushArr(int *array, int arrLen, int value);
void popArr(int *array, int arrLen);

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

		int i, j, k;
		int numberOfElements = 0;
		int changeAmount = 0;
		int lineContainingArray = 0;
		int lineContainingChangeAmount = 0;
		char *inputFileName = argv[1];

		int numberOfLines = numberOfLinesInFile(inputFileName);
		int numberOfProblemsToProcess = numberOfLines / 2;
		int minNumberOfCoins = INT_MAX;

		// Initiate Arrays to hold the tree path
		int cw[1000];
		int cm[1000];
		resetArrays(cw, 1000);
		resetArrays(cm, 1000);

		pushArr(cw, 1000, 100);
		popArr(cw, 1000);

		// For debug
		displayIntArray(cw, 1000);

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

			int lowestDepth = INT_MAX;
			int currLowestDepth = 0;
			minNumberOfCoins = executeAlgorithm(inputArray, numberOfElements, changeAmount, 1, 1, &lowestDepth, &currLowestDepth);
			printf("minNumberOfCoins: %d\n", minNumberOfCoins);

			// TODO
			// 1. rename cw, cm
			// 2. initite arrays cw and cm
			// 3. write push, pop, and clear for cw and cm

			// Output the result to results file
			//outputResultToFile(resultChangeArray, numberOfElements, minNumberOfCoins, inputFileName);

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
int executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount, int cw, int cm, int *lowestDepth, int *currLowestDepth)
{
	int minNumberOfCoins = INT_MAX;
	int i = 0;
	int temp_min;
	int temp_changeAmount;
	for (i = 0; i < numberOfElements; i++)
	{
		if (inputArray[i] == changeAmount)
		{
			// The current denom to the current denom tracker 
			// cw.Add(inputArray[i]);

			// If we found a depth that is lower then the lowest found depth
			//  then save our current denom path
			if (currLowestDepth < lowestDepth)
			{
				lowestDepth = currLowestDepth;

				// Clear our min path
				// cm.Clear();

				// Copy over the current path to the min path
				// foreach (var item in cw)
				// {
				// 	cm.Add(item);
				// }
			}
			// cw.RemoveAt(cw.Count - 1); // Remove the newly added item.

			minNumberOfCoins = 1;
			return minNumberOfCoins;
		}
		else if (inputArray[i] < changeAmount)
		{
			temp_changeAmount = changeAmount - inputArray[i];

			currLowestDepth++;

			// Add the current node to the path before recursing
			// cw.Add(inputArray[i]);

			int recursiveResult = executeAlgorithm(inputArray, numberOfElements, temp_changeAmount, cw, cm, lowestDepth, currLowestDepth);
			temp_min = 1 + recursiveResult;

			if (recursiveResult != 0)
			{
				// cw.RemoveAt(cw.Count - 1);
			}

			if (temp_min < minNumberOfCoins)
			{
				minNumberOfCoins = temp_min;
			}

			if (currLowestDepth != 0)
			{
				currLowestDepth--;
			}
		}
	}
	return minNumberOfCoins;
}

void resetArrays(int *array, int arrLen)
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		array[i] = -1;
	}
}

void pushArr(int *array, int arrLen, int value)
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		if (array[i] == -1)
		{
			array[i] = value;
			break;
		}
	}
}

void popArr(int *array, int arrLen)
{
	int i;
	int idxOfNegative = -1;
printf("in pop\n");
	// Find the index of -1, if it exists
	for (i = 0; i < arrLen; i++)
	{
		if (array[i] == -1)
		{
			idxOfNegative = i;
			break;
		}
	}

	// If we found a negative number, when replace the position before with a negative number.
	if (idxOfNegative != -1)
	{
		array[idxOfNegative - 1] = -1;
	}
}
