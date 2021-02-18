/**
 *
 * @filename TD1.c
 * @date 2019-10-18 15:13
 * @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define _NB_MIN_PARAMS_ 2

void print_usage( char *argv[] ) {
	fprintf( stderr," Usage: %s attends le numéro de l'exercice\n", argv[0] );
	return;
}

void Exercice1()
{
	char c = 0;
	while (c>=0){
		c++;
	}
	char c2 = 0;
	while (c2<=0){
		c2--;
	}
	printf("les char vont de %d à %d et sont définis sur 8 bit\n", c, c2); 
	unsigned char u = 0;
	do{
		u++;
	} while (u!=0);
	u--;
	printf("les unsigned char vont de %d à %d et sont définis sur 8 bit\n", 0, u); 
	short s = 0;
	while (s>=0){
		s++;
	}
	short s2 = 0;
	while (s2<=0){
		s2--;
	}
	printf("les short vont de %d à %d et sont définis sur 16 bit\n", s, s2); 
	int i = 0;
	while (i>=0){
		i++;
	}
	printf("les int vont de %d à %d et sont définis sur 32 bit\n", i, i-1);
	char x = 120;
	printf("x = %d\n",x);
	x=x+120;
	printf("x = %d\n",x);
	x=x-75;
	printf("x = %d\n",x);
	x=x-87;
	printf("x = %d\n",x);
	printf("il y a 2 overflow, un dans chaque sens donc on ne les voit pas sur le resultat final\n");
}

void Exercice2()
{
	float s = 1;
	int n = 128;
	for ( int i = 1 ; i<=n ; i++){
		s = 2 * s + 1;
		printf("s%d = %f\n", i, s);
	}
	printf("un overflow se produit à n = 127\nLes éléments sont impairs jusqu'à n = 24\nLes float son codés sur 16 bit et quand on a besoin d'un 17e, tout est décalé et on perds le bit (2^0) et donc ça deviens pair\nOn est toujours sur 16bit mais chacun de ces bits se déplacent pour pouvoir représenter des nombre plus grand (en étant moins précis ducoup)\nd'où le nom float\n");
	double d = 1;
	for ( int i = 1 ; i<=n ; i++){
		d = 2 * d + 1;
		printf("f%d = %f\n", i, d);
	}
	printf("pas d'overflow\nLes éléments sont impairs jusqu'à n = 53\nLes double fonctionne de la même manière que float mais sur 32 bits\n");
}

#define N 10
void Exercice3()
{
	int count;
	int s1 = 0;
	for (int i = 0 ; i<=N ; i++)
	{
		count = 1;
		for (int k = 1; k <= i ; k++)
			count*=2;
		s1+=count;
		printf("%d\n",s1);
	}
	int s2 = 0;
	for (int j = 0 ; j <= N ; j++){
		count = 1;
		for ( int k = 1 ; k <= j ; k++)
			count*=3;
		s2+=count;
		printf("%d\n",s2);
	}
	printf("(s1) * (s2) = %d\n", s1+s2);
}

int main( int argc, char *argv[] )
{
	if ( argc < _NB_MIN_PARAMS_ ) {
		print_usage( argv );
		return EXIT_FAILURE;
	}
	if (atoi(argv[1]) == 1)
		Exercice1();
	if (atoi(argv[1]) == 2)
		Exercice2();
	if (atoi(argv[1]) == 3)
		Exercice3();
	return EXIT_SUCCESS;
}
