#include <stdio.h>
#include <stddef.h>

char *stp_copy(char *dst, const char *src)
{
    // Rappel *src++, le ++ est fait en premier
    // mais son évaluation retourne la valeur
    // AVANT la modification du pointeur
    // En cas de doute, effectuez les ++ sur des lignes différentes
    do { // Le do while est utilisé pour ne pas avoir à copier manuellement le zéro terminal
        *dst ++ = *src;
    } while (*src++ != 0);
    return dst;
}

size_t strlen(const char *s)
{
  size_t i = 0;
  while(*s !=0){
    i++;
    s++;
  }
  return i;
}

char * strcat(char * s1, const char * s2)
{
  char * output = s1;
  s1 += strlen(s1);
  stp_copy(s1, s2);
  return output;
}

int main(int argc, char **argv)
{
  char * sstr = "Hello !";
  const char cstr[100];
  stp_copy(sstr, cstr);
  printf("la taille est %lu\n", strlen(sstr));
  strcat(sstr, cstr);
  printf("%s est pareil que %s\n", sstr ,cstr);
  printf("la taille est %lu\n", strlen(sstr));
  return 0;
}
