/**
 *
 * @filename itoa.c
 * @date 2019-10-18 15:13
 * @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _NB_MIN_PARAMS_ 2 

void print_usage( char *argv[] ) {
	fprintf( stderr, "Usage: %s ....\n", argv[0] );
	return;
}

void myitoa(int nbr, char *strn)
{
	int i = 255;
	sprintf(strn,i, "%d", nbr); 
}

int main( int argc, char *argv[] )
{
	if ( argc < _NB_MIN_PARAMS_ ) {
		print_usage( argv );
		return EXIT_FAILURE;
	}
	char strn[256];
	int nbr = atoi(argv[1]);
	myitoa(nbr, &strn);
	printf("%d est égal à %s\n", nbr, strn); 
	return EXIT_SUCCESS;
}
