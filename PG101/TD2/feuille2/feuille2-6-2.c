#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void tri_selection(char s1[][13], int taille)
{
  printf("test %s\n", s1[1]);
}

int main(int argc, char* argv[])
{
  int max = strlen(argv[1]);
  for (int i = 2; i < argc; i++) {
    if (max < strlen(argv[i]))
      max = strlen(argv[i]);
  }
  char s1[argc - 1][max];
  for (int i = 1; i < argc; i++)
    strcpy(s1[i - 1], argv[i]);
  tri_selection(s1, argc - 1);
  return 0;
}
