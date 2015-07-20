/**************************************************************
 * *  Filename: changedp.c
 * *  Coded by: Frank Eslami
 * *  Purpose - Dynamic programming implementation of coin change
 * *
 * ***************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "filefunctions.h"

void executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount, char *inputFileName);

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
		
		int i;
		int numberOfElements = 0;
		int changeAmount = 0;
		int lineContainingArray = 0;
		int lineContainingChangeAmount = 0;
		char *inputFileName = argv[1];

		int numberOfLines = numberOfLinesInFile(inputFileName);
		int numberOfProblemsToProcess = numberOfLines / 2;

		// Run the algorithm problem in the input file. A problem
		//	consists of the array of denominations and the amount
		//  of change.
		for (i = 0; i < numberOfProblemsToProcess; i++)
		{
			lineContainingArray = i + i;
			numberOfElements = getNumberOfElementsInLine(inputFileName, lineContainingArray);

			int *inputArray = malloc(numberOfElements * sizeof(int));

			// Fill the input array with the numbers from line i in the file
			fillIntArray(inputFileName, lineContainingArray, inputArray, numberOfElements);

			lineContainingChangeAmount = (2 * i) + 1;
			changeAmount = getChangeAmount(inputFileName, lineContainingChangeAmount);

			executeAlgorithm(inputArray, numberOfElements, changeAmount, inputFileName);

			// Cleanup dynamically allocated strings
			free(inputArray);
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
void executeAlgorithm(int *inputArray, int numberOfElements, int changeAmount, char *inputFileName)
{
	// Write algorithm here
	int i, j;
	int *C = malloc( (changeAmount + 1) * sizeof(int));
	int *minArrIndex = malloc( (changeAmount + 1) * sizeof(int));


	C[0] = 0;	//base case
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
//	printf("min =%d\n", minNumberOfCoins);
	
	int *resultChangeArray = malloc( numberOfElements * sizeof(int));
	memset (resultChangeArray, 0, numberOfElements);

	//Output occurences of each arrayInput index
	while(changeAmount) {
		int index = minArrIndex[changeAmount];
		resultChangeArray[index] += 1;
//		printf("%d ", resultChangeArray[index]);	//occurences of each inputArray index
//		printf("%d ", index);	//occurences of each inputArray index
//		printf("%d ", inputArray[index]);	//values of inputArray 
		changeAmount = changeAmount - inputArray[minArrIndex[changeAmount]];
	}
//	printf("\n");

	/*
	//Output inputArray values as they occur in sequence for minimum array 
	while(changeAmount) {
//		printf("%d ", minArrIndex[changeAmount]);	//occurences of each inputArray index
		printf("%d ", inputArray[minArrIndex[changeAmount]]);	//values of inputArray 
		changeAmount = changeAmount - inputArray[minArrIndex[changeAmount]];
	}
	printf("\n");
	*/

	// Output the result to results file
	outputResultToFile(resultChangeArray, numberOfElements, minNumberOfCoins, inputFileName);

	free(resultChangeArray);
}
