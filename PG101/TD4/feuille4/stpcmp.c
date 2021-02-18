#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stpcmp(const char* s1, const char* s2)
{
  while (*s1 != 0) {
    if (*s2 == 0)
      return 1;
    if (*s1 - *s2 != 0)
      return *s1 - *s2;
    s1 ++;
    s2 ++;
  }
  return *s1 - *s2;
}


int main(int argc, char* argv[])
{
  if (argc == 3) {
    const char* s1 = argv[1];
    const char* s2 = argv[2];
    int x = stpcmp(s1, s2);
    if (x > 0)
      printf("Le mot \"%s\" est après le mot \"%s\" dans le dictionnaire.\n", s1, s2);
    if (x < 0)
      printf("Le mot \"%s\" est après le mot \"%s\" dans le dictionnaire.\n", s2, s1);
    if (x == 0)
      printf("Les deux mots sont identiques.\n");
  }
  return 0;
}
