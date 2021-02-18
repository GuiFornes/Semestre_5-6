#include <stdio.h>
#include <string.h>

int longueur(char * str)
{
  int i = 0;
  while (str[i] != 0){

    i++;
  }
    return i;
}

int lenghtcompare(char * str1, char * str2)
{
  int s1 = longueur(str1);
  int s2 = longueur(str2);
  return s1-s2;
}

int est_voyelle(char c)
{
  char * voyelles = "aeiouyAEIOUY";
  int i = 0;
  while(voyelles[i] != 0){
    if (voyelles[i]==c){
      return 1;
    }
    i++;
  }
  return 0;
}

int contient_voyelle(char * s)
{
  int i = 0;
  int j = 0;
  while (s[i] != 0){
    if (est_voyelle(s[i]) == 1){
      j++;
      }
    i++;
  }
  return j;
}

int est_palyndrome(char * s)
{
  int len = longueur(s);
  int milieu = len/2;
  int i=0;
  while (i<milieu){
    if (s[i] != s[len-1-i]){
      return 0;
    }
    i++;
  }
  return 1;
}

int est_lettre(char c)
{
  int ascii = c;
  if (64<ascii && ascii<91 || 96<ascii && ascii<123){
    return 1;
  }
  return 0;
}

int maj_to_min(char c)
{
  int ascii = c;
  if (64<ascii && ascii<91){
    return c;
  }
  if (96<ascii && ascii<123){
    char cbis = ascii+32;
    return cbis;
  }
  printf("erreur de maj_to_min");
  return 0;
}

int est_palindrome_phrase(char * pal)
{
  int len = longueur(pal);
  int milieu = len/2;
  int i = 0;
  for (i = 0;i < milieu;i++){
    if (est_lettre(pal[i])){
      pal[i] = maj_to_min(pal[i]);
    }
    if (est_lettre(pal[len-1-i])){
      pal[len-1-i] = maj_to_min(pal[len-1-i]);
    }
    if (pal[i] != pal[len-1-i]){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char * argv[])
{
  if (argc < 2){
    printf("Usage : %s argument\n", argv[0]);
    return 1;
  }
  int i = 0;
  for (i=1;i<argc;i++){
    char * str=argv[i];
    printf("La longueur de la chaine %s est : %d\n", str, (int) strlen(str));
    printf("La longueur de la chaine %s (avec ma fonction) est : %d\n", str,longueur(str));
    printf("il y a %d voyelles dans %s\n", contient_voyelle(str), str);
  }
  
  if (argc !=3){
    printf("rentrez exactement 2 chaines de caractères si vous voulez savoir laquelle est la plus grande\n");
  }
  if (argc == 3){
    char * str1 = argv[1];
    char * str2 = argv[2];
    if (lenghtcompare(str1,str2)<0){
      printf("%s est plus petit que %s\n", str1, str2);
    }
    if (lenghtcompare(str1,str2)>0){
      printf("%s est plus grand que %s\n",str1, str2);
    }
    if (lenghtcompare(str1,str2)==0){
      printf("%s est de la même taille que %s\n", str1, str2);
    }
  }
  if (argc == 2){
    char * str3 = argv[1];
    if (est_palindrome_phrase(argv[1])){
      printf("%s est un palindrome\n", str3);
    }
    else {
      printf("%s n'est pas un palindrome\n",str3);
    }
  }
  return 0;
}
