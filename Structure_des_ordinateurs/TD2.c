/**
 *
 * @filename TD2.c
 * @date 2019-10-18 15:13
 * @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int plusun(int);
int fact(int);
int syracuse(int);
void syracuse2(int u)
{
	printf("  %d\n", u);
	while (u > 1){
		if (u%2 == 0)
			u = u/2;
		else
			u = 3*u+1;
		printf("  %d\n", u);
	}
}

int main( int argc, char *argv[] )
{
	printf("Exercice 1\n");
	int x = 5;
	int y = plusun(x);
	printf("%d + 1 = %d\n", x, y);
	int a = 4;
	int b = fact(a);
	printf("fact(%d) = %d\n", a, b);

	printf("Exercice 2\n");
	int r = 93;
	int r2 = syracuse(r);
	printf("pour u0 = %d, la suite de syracuse à un temps de vol égal à %d\n Les étapes sont :\n", r, r2);
	syracuse2(r);
	return EXIT_SUCCESS;
}
