#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int est_bissextile(int an)
{
  if (an%4 == 0 && an%100 !=0 || an%400 == 0){
    return 1;
  }
  return 0;
}

int nbr_jours(int mois, int an)
{
  if (mois>7){
    mois++;
  }
  if (mois == 2){
    if (est_bissextile(an)){
      return 29;
    }
    return 28;
  }
  if (mois%2){
    return 31;
  }
  return 30;
}


int longueur(char * str)
{
  int i = 0;
  while (str[i] != 0){
    i++;
  }
    return i;
}

int day_of_a_date(int jour, int mois, int an)
{
  int j = 0;
  if (mois >= 3){
    int z = an;
    j = (23*mois/9+jour+4+an+z/4-z/100+z/400-2)%7;
  }
  if (mois < 3){
    int z = an-1;
    j = (23*mois/9+jour+4+an+z/4-z/100+z/400)%7;
  }
  if (!j){
    j=7;
  }
  return j;
}     

int main(int argc, char * argv[])
{
  char * str_mois = argv[2];
  char * str_an = argv[3];
  char * str_jour = argv[1];
  if (argc != 4 || longueur(str_mois)!=2 || longueur(str_an)!=4 || longueur(str_jour)!=2){
    printf("Ce programme attends en arguments : 'Jours Mois Année' sous la forme '.. .. ....'\n");
    return 0;
  }
  int mois = atoi(str_mois);
  int an = atoi(str_an);
  int jour = atoi(str_jour);
  printf("il y a %d jours dans le %dème mois de %d\n", nbr_jours(mois,an), mois, an);  
  printf("le %d/%d/%d correspond au %de jour de la semaine !\n", jour, mois, an, day_of_a_date(jour,mois,an));
  return 0;
}
