#include <stdio.h>

long long int multiplie(int n);

int main(int argc, char *argv[]) {
    int n = 1000000;
    int x = multiplie(n);
    printf("Le temps en cycle est de %d\n", x);
    return 0;
}
