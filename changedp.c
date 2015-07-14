/**************************************************************
 * *  Filename: changedp.c
 * *  Coded by:
 * *  Purpose -
 * *
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Program entry point
int main(int argc, char *argv[])
{
	if ( argc != 2 )
	{
		// A file name was not entered as a program argument
		printf( "usage: %s filename\n", argv[0] );
	}
	else
	{
		// Check if input file exists
	}

	printf("Hello world from changedp\n");
	return 0;
}
