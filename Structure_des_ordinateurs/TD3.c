#include <stdio.h>

void print(int x);

void invtab(long long int*, int n);

int main() {
    print(6);
    int n = 4;
    long long int t[12];

    printf("t = [");
    for (int i = 0; i < 12; i++)
    {
        t[i] = i;
        printf("%d,", (int)t[i]);
    }
    printf("]\n");

    invtab(t, 12-1);

    printf("t = [");
    for (int i = 0; i < 12; i++)
    {
        printf("%d,", (int)t[i]);
    }
    printf("]\n");
}
