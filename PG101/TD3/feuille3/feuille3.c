#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bissextile(int annee)
{
  return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

void table_caractere()
{
  printf("Car.\t dec. \t hexa. \t octal \t\n");
  for (int i = 27; i < 127; i = i + 1)
    printf("\'%c\' \t %d \t 0x%d \t 0%d \n", i, i, i, i);
}

void table_caractere_V2(int n)
{
  for (int i = 0; i < n; i = i + 1)
    printf("Car.\t dec. \t hexa. \t octal \t");
  printf("\n");
  for (int i = 0; i < 255; i = i + 1){
    printf("\'%c\' \t %d \t 0x%d \t 0%d \t", i, i, i, i);
    if ((27 - i) % n == 0)
      printf("\n");
  }
  printf("\n");
}

void table_caractere_V3(int n, int* min, int* max)
{
  if (min == NULL)
    *min = 0;
  if (max == NULL)
    *max = 127;
  for (int i = 0; i < n; i = i + 1)
    printf("Car.\t dec. \t hexa. \t octal \t");
  printf("\n");
  for (int i = *min; i < *max + 1; i = i + 1){
    printf("\'%c\' \t %d \t 0x%d \t 0%d \t", i, i, i, i);
    if ((27 - i) % n == 0)
      printf("\n");
  }
  printf("\n");
}

int bit_count_1(int n)
{
  int somme = 0;
  while (n != 0){
    if (n & 1)
      somme = somme + 1;
    n = n >> 1;
  }
  return somme;
}

void affiche_grille(char tableau[])
{
  printf("                   Modèle\n");
  printf("%c  %c  %c \t 7   8   9\n", tableau[6], tableau[7], tableau[8]);
  printf("%c  %c  %c \t 4   5   6   0 - EXIT\n", tableau[3], tableau[4], tableau[5]);
  printf("%c  %c  %c \t 1   2   3\n", tableau[0], tableau[1], tableau[2]);
}

int victoire(char tableau[])
{
  for (int i = 0; i < 9; i = i + 3){
    if (tableau[i] == tableau[i + 1] && tableau[i] == tableau[i + 2] && tableau[i] != '.')
      return 1;
  }
  for (int i = 0; i < 3; i = i + 1){
    if (tableau[i] == tableau[i + 3] && tableau[i] == tableau[i + 6] && tableau[i] != '.')
      return 1;
  }
  if ((tableau[0] == tableau[4] && tableau [0] == tableau[8] && tableau[0] != '.') || (tableau[2] == tableau[4] && tableau [2] == tableau[6] && tableau[2] != '.'))
    return 1;
  return 0;
}

void morpion()
{
  char tableau[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
  affiche_grille(tableau);
  int i = 0;
  int a;
  while (i < 9){
    printf("(Joueur %d) Entrez un nombre entre 1 et 9 : \n", i % 2 + 1);
    scanf("%d", &a);
    if (a == 0)
      i = 10;
    if (i % 2 == 0 && a < 10 && a > 0 && tableau[a - 1] == '.'){
      tableau[a - 1] = 'X';
      affiche_grille(tableau);
      i = i + 1;}
    else if (i % 2 == 1 && a < 10 && a > 0 && tableau[a - 1] == '.'){
      tableau[a - 1] = 'O';
      i = i + 1;
      affiche_grille(tableau);
    }
    if (victoire(tableau)){
      printf("Le joueur %d a gagné.\n", (i - 1) % 2 + 1 );
      i = 10;
    }
    if (i == 9)
      printf("Egalité.\n");
  }
  printf("Rejouer ? y or n\n");
  int b;
  scanf("%d", &b);
  if (b)
    morpion();
}


int main(int argc, char *argv[])
{
  morpion();
  //table_caractere();
  if (argc > 1){
    //printf("Le nombre de bit à 1 est de : %d\n", bit_count_1(atoi(argv[1])));
    //int min = atoi(argv[2]);
    //int max = atoi(argv[3]);
    //table_caractere_V2(atoi(argv[1]));
    //table_caractere_V3(atoi(argv[1]), &min, &max);
    /*  if (bissextile(atoi(argv[1])))
	printf("L'année %d est bissextile.\n", atoi(argv[1]));
	else
	printf("L'année %d n'est pas bissextile.\n", atoi(argv[1]));*/
  }
  return 0;
}

