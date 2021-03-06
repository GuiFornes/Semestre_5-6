#include <stdio.h>

int pgcd_rec(int a,int b)
{
  if (b == 0){
    return a;
  }
  return pgcd_rec(b,a % b);   
}

int pgcd_iter(int a,int b){
  if (b == 0){
    return a;
  }
  int r = 0;
  while (1){
    r = a % b;
    if (r == 0){
      return b;
    }
    a = b;
    b = r;
  } 
  
}

int main(int argc, char * argv[])
{
  int a = 963;
  int b = 741;
  
  printf("le PGCD de %d et %d  est %d\n", a, b, pgcd_iter(a,b));
  return 0;
}
