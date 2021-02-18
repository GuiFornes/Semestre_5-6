#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stpcpy(char* dst, const char* src)
{
  int x = strlen(src);
  for (int i = 0; i < x; i++) {
    *dst = *src;
    dst ++;
    src ++;
  }
  dst = 0;
}


int main(int argc, char *argv[])
{
  if (argc == 2) {
  const char* src = argv[1];
  char dst[strlen(src) + 1];
  stpcpy(dst, src);
  printf("La copie est égale à \"%s\".\n", dst);
  }
  return 0;
}
