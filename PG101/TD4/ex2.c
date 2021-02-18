#include <stdio.h>

void min_max(int l, int t[], int *min ,int *max)
{
  *min = t[0];
  *max = t[0];
  for(int i = 1 ; i < l ; i++){
    if(t[i]<*min)
      *min = t[i];
    if(t[i]>*max)
      *max = t[i];
  }
}

int main(int argc, char *argv[])
{
  int min;
  int max;
  int l = 6;
  int t[] = { 3, 5, 1, 8, 2, 0 };
  min_max(l, t, &min, &max);
  printf("min = %d, max = %d\n", min, max);
  return 0;
}
