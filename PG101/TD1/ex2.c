#include <stdio.h>

void print_tab(int t[], int size)
{
  int i = 0;
  printf("{");
  for (i = 0 ; i<size ; i++){
      if (i!=0){
	printf(", ");
      }
      printf("%d",t[i]);
    }
  printf("}\n");  
}

void create_tab(int n, int t[])
{
  int i = 0;
  for (i = 0 ; i<n ; i++)
    {
      t[i]=2*i;
    }
}

int main(int argc, char * argv[])
{
  int t[4] = {1, 2, 3, 4};
  print_tab(t,4);
  int n = 10;
  int tableau_pairs[n];
  create_tab(n,tableau_pairs);
  print_tab(tableau_pairs,10);
  return 0;
}
