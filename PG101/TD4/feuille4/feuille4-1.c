#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void order(int* a, int* b, int*c)
{
  if (*b > *a)
    swap(a, b);
  if (*c > *a)
    swap(a, c);
  if (*c > *b)
    swap(b, c);
}

int main(int argc, char *argv[])
{
  if (argc == 3){
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("Les nombres a=%d et b=%d.\n", a, b);
  swap(&a, &b);
  printf("Les nombres a=%d et b=%d.\n", a, b);
  }
  if (argc == 4){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    printf("Les nombres a=%d, b=%d et c=%d.\n", a, b, c);
    order(&a, &b, &c);
    printf("Les nombres a=%d, b=%d et c=%d.\n", a, b, c);
  }
  return 0;
}
