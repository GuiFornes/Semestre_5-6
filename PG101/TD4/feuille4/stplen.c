#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t stplen(const char* s)
{
  size_t compteur = 0;
  while (*s != 0) {
    s++;
    compteur++;
  }
  return compteur;
}

int main(int argc, char* argv[])
{
  if (argc == 2) {
    const char* s = argv[1];
    size_t compteur = stplen(s);
    printf("La taille de la chaine de caractère est %lu.\n", compteur);
  }
  return 0;
}
