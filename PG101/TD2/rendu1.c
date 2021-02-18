#include <stdio.h>

int sym_array(int n, int t[])
{
  int i = 0;
  for (i = 0;i < (n/2);i++){
    if (t[i] != t[n-1-i]){
      return i;
    }
  }
  return -1;
}

int main(int argc, char * argv[])
{
  int t[] = {8, 2, 8, 4};
  printf("Soit t=[8, 2, 8, 4]\n");
  int n = 0;
  for (n = 0;n <= 4;n++){
    printf("En considérant une taille n = %d, sym_array(n,t) renvoi %d\n", n, sym_array(n,t));
  }
  return 0;
}
