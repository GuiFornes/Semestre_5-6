#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void table_ascii(int n)
{
  int i;
  for(i = 1;i <= n;i++){
    printf("Car.\tdec.\thexa\toctal\t");
  }
  printf("\n");
  for(i = 0;i <= 127;i++){
    printf("%c\t%d\t%x\t%o", i, i, i, i);
    printf("%c", (i%n==n-1 || i = 127) ? '\n' : '\t');   
  }
}
 

int main(int argc, char * argv[])
{
  int n=1;
  if(argc >= 2){    
    char * str=argv[1];
    n=atoi(str);
  }
  table_ascii(n);
  printf("\n");
  return 0;  
}
  
