/**************************************************************
 * *  Filename: changegreedy.c
 * *  Coded by: Kevin
 * *  Purpose -
 * *
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "filefunctions.h"

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
		// Check if input file exists
		// Get the number of lines in the file
		// Calculate how many problem sets are in the file.
		//	- In the file, a problem should consist of two lines:
		//		1. The array of denomination amounts
		//		2. The actual amount we need to add up to using the denomination amounts
	}

	testfunction();
	printf("Hello world changegreedy\n");
	return 0;
}

/**************************************************************
 * * Entry:
 * *  inputArray - The input array to run the algo on.
 * *  numberOfElements - The number of elements in the array
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Executes the divide and conquer algorithm and puts the results
 * *  to the MSS_Results.txt file
 * *
 * ***************************************************************/
void executeAlgorithm(int *inputArray, int numberOfElements)
{
	// int i;
	// int currentInputArrayIdx = 0;
	// int lastLow = 0;
	// int lastHigh = 0;
	// int finalSum = 0;

	// // Run the divide and conquer algo
	// maxSubArray(inputArray, 0, numberOfElements - 1, &lastLow, &lastHigh, &finalSum);

	// // Check if the number of result elements is within the bounds
	// int numberOfResultElements = lastHigh - lastLow + 1;
	// if (numberOfResultElements <= 0)
	// {
	// 	printf("Error: invalid amount of result elements\n");
	// 	return;
	// }

	// // Generate the results array
	// int *resultArray = malloc(numberOfResultElements * sizeof(int));
	// for (i = 0; i < numberOfResultElements; i++)
	// {
	// 	currentInputArrayIdx = lastLow + i;
	// 	if ((currentInputArrayIdx >= numberOfElements) || (currentInputArrayIdx < 0))
	// 	{
	// 		printf("Error: Out of bounds of the input array\n");
	// 	}

	// 	resultArray[i] = inputArray[lastLow + i];
	// }

	// // Output the result to results file
	// outputResultToFile(resultArray, numberOfResultElements, inputArray, numberOfElements);

	// // For debugging purposes only
	// // displayIntArray(resultArray, numberOfResultElements);
	// // printf("\n");

	// free(resultArray);
}