#include <stdio.h>
#include <string.h>

void array_zero(void * vptr, unsigned nb_bytes)
{
  char * ptr = vptr;
  for (unsigned i = 0 ; i < nb_bytes ; i++){
    ptr[i] = 0;
  }
}

int main(int argc, char **argv)
{
  int t[4] = {1, 2, 3, 4};

  printf("%d %d %d %d\n", t[0], t[1], t[2], t[3]);

  array_zero(t, 4 * sizeof(int));

  printf("%d %d %d %d\n", t[0], t[1], t[2], t[3]);
  return 0;
}
