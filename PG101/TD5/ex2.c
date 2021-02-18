#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct coefs {
  double a;
  double b;
  double c;
};

struct roots {
  double r1;
  double r2;
};

double poly(struct coefs f, double x)
{
  double output = f.a*x*x+f.b*x+f.c;
  return output;
} 

double polypoint(struct coefs * f, double x)
{
  return f->c + x * ( f->b + f->a * x);
}

struct roots racine(struct coefs f)
{
  struct roots output;
  double delta = f.b * f.b - 4 * f.a * f.c;
  if(delta >= 0){
    output.r1=(-f.b+sqrt(delta))/(2*f.a);
    output.r2=(-f.b-sqrt(delta))/(2*f.a);
    return output;
  }
  if(delta < 0){
    output.r1=NAN;
    output.r2=NAN;
    return output;
  }
}

void print_root(struct roots * r)
{
  if(isnan(r->r1)){
    printf("no real root\n");
    return;
  }
  if(r->r1==r->r2){
    printf("one root : %lf\n",r->r1);
    return;
  }
  printf("two roots : %lf and %lf\n", r->r1, r->r2);
  return;
}

int main(int argc, char * argv[])
{
  double x;
  struct coefs f;
  if(argc!=5){
    printf("donnez dans l'ordre a, b c puis x\n");
    scanf("%lf", &(f.a));
    scanf("%lf", &(f.b));
    scanf("%lf", &(f.c));
    scanf("%lf", &x);
    
  }
  else {
  
    f.a = atof(argv[1]);
    f.b = atof(argv[2]);
    f.c = atof(argv[3]);
    x = atof(argv[4]);
  }
  printf("f(%lf) = %lf*%lf² + %lf*%lf + %lf = %lf\n", x, f.a, x, f.b, x, f.c, poly(f, x));
  struct roots r = racine(f);
  print_root( &r );
  return 0;
}
