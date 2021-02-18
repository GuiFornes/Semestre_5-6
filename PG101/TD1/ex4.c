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
void croissant(int t[], int n)
{
  int i;
  int j=0;
  for (i = 1;i < n; i++){
    if (t[i]<t[i-1]){
      j++;
	}
  }
  if(j!=0){
    printf("le tableau n'est pas dans l'ordre croissant\n");
  }
  else{
    printf("le tableau est dans l'ordre croissant\n");
  }
}
int present(int t[], int n, int x)
{
  int i;
  for (i = 0;i < n; i++){
    if (x==t[i]){
      printf("%d et %d\n",t[i],i);
      return 1;
    }
  }
  return 0;
}
int present_dicho(int t[], int n, int x)
{

}

int main(int argc, char *argv[])
{
  int x = 51;
  int n=8;
  int t1[]={1, 5, 6, 8, 9, 15, 51, 100};
  int t2[]={3, 5, 4, 9, 65, 21, 13, 42};
  printf("t1= ");
  print_tab(t1,n);
  croissant(t1,n);
  if (present(t1,n,x))
    printf("%d est dans t1\n",x);
  else
    printf("%d n'est pas dans t1\n",x);

  printf("t2= ");
  print_tab(t2,n);
  croissant(t2,n);
  if (present(t2,n,x))
    printf("%d est dans t2\n",x);
  else
    printf("%d n'est pas dans t2\n",x);  
  return 0;
}
