#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_int(char *nbr)
{
  int i = 0;
  int s = 0;
  int entier = 0;
  while(nbr[i]){
    char c = nbr[i];
    s = 10*s + (c-'0');
    i++;
  }
  return s;
}

int main(int argc, char *argv[])
{
  if(argc<=2){
    fprintf(stderr, "il faut mettre deux nombre en argument");
    return 0;
  }
  char *nbr=argv[1];
  char *nbr2=argv[2];
  printf("la somme de %d et %d est %d\n",str_to_int(nbr),str_to_int(nbr2),str_to_int(nbr)+str_to_int(nbr2));
  return 0;
}
