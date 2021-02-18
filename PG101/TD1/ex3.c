#include <stdio.h>

void print_tab(int size, int t[])
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
void somme_tab(int n, int t[])
{
  int s = 0;
  int i = 0;
  for (i = 0 ; i<n ; i++){
    s=s+t[i];
    }
  printf("la somme des éléments est %d \n",s);
}

void prod_scal(int n, int t1[], int t2[])
{
  int t[n];
  int i = 0;
  for (i = 0 ; i<n ; i++){
    t[i]=t1[i]*t2[i];
  }
  printf("le produit scalaire donne : ");
  print_tab(n,t);
}

void somme_mam(int n, int t1[], int t2[])
{
  int t[n];
  int i = 0;
  for (i = 0 ;  i < n ; i++){
    t[i] = t1[i] + t2[i];
  }
  printf("la somme membre à membre donne : ");
  print_tab(n,t);
}

int main(int argc, char * argv[])
{
  int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print_tab(10,t);
  int n = 10;
  int tableau_pairs[n];
  create_tab(n,tableau_pairs);
  print_tab(n,tableau_pairs);
  somme_tab(n,tableau_pairs);
  prod_scal(n,tableau_pairs,t);
  somme_mam(n,tableau_pairs,t);
  return 0;
}
