/**
 *
 * @filename myatoi.c
 * @date 2019-10-18 15:13
 * @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
 *
 */
#include <stdlib.h>
#include <stdio.h>

#define _NB_MIN_PARAMS_ 2

void print_usage( char *argv[] ) {
	fprintf( stderr, "Usage: %s change une chaine de caractère en le nombre correspondant\n", argv[0] );
	return;
}

int myatoi(char * strn)
{
	int negatif = 1;
	int nb = 0;
	int i = 0;
	if(*strn == '-'){
		strn++;
		negatif=-1;
	}
	if(*strn == 0){
		printf("test");
		return 0;
	}
	while(*strn != 0){
		if(*strn < 48 || *strn > 57){
			printf("%d test %d\n",*strn, strn[i]); 
			return 0;
		}
		nb=nb*10+(*strn-48);
		strn++;
	}
	return nb*negatif;
}

int main( int argc, char *argv[] )
{
	if ( argc < _NB_MIN_PARAMS_ ) {
		print_usage( argv );
		return EXIT_FAILURE;
	}
	printf("%s est égal à %d\n", argv[1], myatoi(argv[1])); 
	
	return EXIT_SUCCESS;
}
