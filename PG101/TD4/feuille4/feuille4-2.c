#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void min_max(int l, int t[], int* min, int* max)
{
  int i = 0;
  if (max != NULL){
    *max = t[0];
    while (i < l){
      if (t[i] > *max)
	*max = t[i];
      i = i + 1;
    }
  }
  i = 0;
  if (min != NULL){
    *min = t[0];
    while (i < l){
      if (t[i] < *min)
	*min = t[i];
      i = i + 1;
    }
  }
}


int main(int argc, char *argv[])
{
  if (argc > 1){
    int minimum = 0;
    int maximum = 0;
    int* min = NULL;
    int* max = NULL;
    if (!strcmp(argv[argc - 2], "NULL"))
       min = NULL;
    else {
      minimum = atoi(argv[argc- 2]);
      min = &minimum;
    }
    if (!strcmp(argv[argc - 1], "NULL"))
      max = NULL;
    else {
      maximum = atoi(argv[argc- 1]);
      max = &maximum;
    }
    int tableau[argc - 3];
    for (int i = 1; i < argc - 2; i++)
      tableau[i - 1] = atoi(argv[i]);
    min_max(argc - 3, tableau, min, max);
    if (min != NULL)
      printf("Le minimum du tableau est %d.\n", *min);
    if (max != NULL)
      printf("Le maximum du tableau est %d.\n", *max);
  }
  return 0;
}
