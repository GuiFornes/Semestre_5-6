#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int longueur(char s0[])
{
  int i = 0;
  while (s0[i] != 0)
    i = i + 1;
  return i;
}

int longueur_compare(char s1[], char s2[])
{
  int i = longueur(s1) - longueur(s2);
  return i;
}

int est_voyelle(char s0[], int position)
{
  int i = 0;
  char voyelle[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
  while (i < 12){
    if (voyelle[i] == s0[position])
      return 1;
    i = i + 1;
  }
  return 0;
}

int nombre_voyelle(char s0[])
{
  int taille = longueur(s0);
  int i = 0;
  int somme = 0;
  while (i < taille){
    somme = somme + est_voyelle(s0, i);
    i = i + 1;
  }
  return somme;
}

void chaine_miroir(char s0[])
{
  int taille = longueur(s0);
  int temp;
  int i = 0;
  while (i < taille / 2){
    temp = s0[i];
    s0[i] = s0[taille - i - 1];
    s0[taille - i - 1] = temp;
    i = i + 1;
  }
}

void chaine_miroir2(char s0[], char s1[])
{
  int taille = longueur(s0);
  int i = 0;
  while (i < taille / 2){
    s1[i] = s0[taille - i - 1];
    s1[taille - i - 1] = s0[i];
    i = i + 1;
  }
  s1[taille] = 0;
}

void conversion_entier(int entier, char s0[])
{
  if (entier == 0)
    s0[0] = '0';
  else {
    int i = 0;
    while (entier != 0){
      s0[i] = '0' + entier % 10;
      entier = entier / 10;
      i = i + 1;
    }
    chaine_miroir(s0);
  }
}

void conversion_entier_signe(int entier, char s0[])
{
  if (entier == 0)
    s0[0] = '0';
  else {
    int i = 0;
    int signe;
    if (entier < 0){
      signe = 0;
      entier = - entier;
    } else
      signe = 1;
    while (entier != 0){
      s0[i] = '0' + entier % 10;
      entier = entier / 10;
      i = i + 1;
    }
    if (signe == 0)
      s0[i] = '-';
    else
      s0[i] = '+';
    s0[i + 1] = 0;
    chaine_miroir(s0);
  }
}

void affiche_tableau(int taille, int a0[])
{
  int i = 0;
  while (i < taille){
    printf("%d    ", a0[i]);
    i = i + 1;
  }
  printf("\n");
}

int compteur_espace(char s0[])
{
  int i = 0;
  int somme;
  while (s0[i] != 0){
    if (s0[i] == ' ')
      somme = somme + 1;
    i = i + 1;
  }
  return somme;
}

void tableau_entier(char s0[], int a0[])
{
  chaine_miroir(s0);
  int i = - 1;
  int j = 1;
  int k = 0;
  int entier = 0;
  while (i <= 0 || s0[i] != 0){
    i = i + 1;
    if (s0[i] == ' ' || s0[i] == 0){
      a0[k] = entier;
      entier = 0;
      j = 1;
      k = k + 1;	
    } else {
      entier = entier + (s0[i]-48) * j;
    j = j * 10;
    }
  }
}

int compteur_separateur(char s0[], char separateur[])
{
  int i = 0;
  int somme;
  while (s0[i] != 0){
    if (s0[i] == separateur[0])
      somme = somme + 1;
    i = i + 1;
  }
  return somme;
}

void tableau_entier_V2(char s0[], int a0[], char separateur[])
{
  chaine_miroir(s0);
  int i = - 1;
  int j = 1;
  int k = 0;
  int entier = 0;
  while (i <= 0 || s0[i] != 0){
    i = i + 1;
    if (s0[i] == separateur[0] || s0[i] == 0){
      a0[k] = entier;
      entier = 0;
      j = 1;
      k = k + 1;
    } else {
      entier = entier + (s0[i]-48) * j;
    j = j * 10;
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc > 2){
    //int x = compteur_espace(argv[1]);
    int x = compteur_separateur(argv[1], argv[2]);
    int a0[x + 1];
    //tableau_entier(argv[1], a0);
    tableau_entier_V2(argv[1], a0, argv[2]);
    affiche_tableau(x + 1, a0);
    //char s0[longueur(argv[1])];
    //conversion_entier_signe(atoi(argv[1]), s0);
    //printf("%s\n", s0);
    //chaine_miroir2(argv[1], s0);
    //chaine_miroir(argv[1]);
    //printf("%s, %s\n", argv[1], s0);
    //printf("Le nombre de voyelles dans %s est : %d\n", argv[1], nombre_voyelle(argv[1]));
    //printf("La longueur de la chaine est : %d\n", longueur(argv[1]));
    //printf("La chaine %s est plus longue que la chaine %s : %d\n", argv[1], argv[2], longueur_compare(argv[1], argv[2]));
  }
}
