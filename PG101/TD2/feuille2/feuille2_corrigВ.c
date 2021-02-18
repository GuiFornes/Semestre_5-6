#include <stdio.h> // pour printf
#include <stdlib.h> // pour atoi
#include <string.h> // pour strcmp, strlen, strcpy

int strlength(char *str)
{
    int len = 0;
    while (str[len])
        len = len + 1;
    return len;
}

// retourne -1 si s1 est plus courte que s2
int strlencmp(char *s1, char *s2)
{
    int i = 0;
    while (s2[i]) {
        if (!s1[i])
            return -1;
        i = i + 1;
    }
    return s1[i] != 0;
}

// Fonction recupere de la feuille precedente
int member(int k, int l, int tab[])
{
    int i = 0;
    while (i < l) {
        if (tab[i] == k)
            return 1;
        i = i + 1;
    }
    return 0;
}

int voyelle(char c)
{
    int _voyelles[] = {
        'A', 'E', 'I', 'O', 'U', 'Y',
        'a', 'e', 'i', 'o', 'u', 'y',
    }; // on met les majs. avant les mins. pour que la dichotomie marche
    return member(c, 12, _voyelles);
}

int voyelles(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i]) {
        if(voyelle(str[i]))
            count = count + 1;
        i = i + 1;
    }
    return count;
}

int palindrome(char *str)
{
    int l = strlen(str);
    int m = l / 2; // la division entiere est tres bien car la lettre du millieu est identique a elle meme 
    int i = 0;
    while (i < m) {
        if(str[i] != str[l - i - 1])
            return 0;
        i = i + 1;
    }
    return 1;
}

void mirror(char *str)
{
    int l = strlen(str);
    int m = l / 2; // meme remarque
    int i = 0;
    char tmp;
    while (i < m) {
        tmp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = tmp;
        i = i + 1;
    }
}

void mirror2(char *dst, char *src)
{
    int l = strlen(src);
    int i = 0;
    dst[l] = src[l]; // on copie le 0 terminal
    l = l - 1;
    while (l >= 0) {
        dst[i] = src[l];
        i = i + 1;
        l = l - 1;
    }
}

void itoa(int val, char *dst)
{
    int i = 0;
    int neg = val < 0;


    if(neg) // Sinon le modulo est negatif
        val = - val;

    do {
        dst[i] = (val % 10) + '0';
        val = val / 10;
        i = i + 1;
    } while (val);

    if (neg) { // cas particulier pour le signe
        dst[i] = '-';
        i = i + 1;
    }

    dst[i] = 0;
    mirror(dst);
}

void bubble_sort(int l, char* tab[])
{
    int done;
    do {
        done = 1;
        for(int i = 0; i < l - 1 ; i++)
            if(strcmp(tab[i], tab[i + 1]) > 0) {
                char* tmp = tab[i]; // echanger tab[i] <=> tab[i + 1]
                tab[i] = tab [i + 1];
                tab[i + 1] = tmp;

                done = 0; // on a fait une permutation, on a donc pas fini
            }
    } while(!done);
}

int main(int argc, char* argv[])
{
    char * egales[] = {"plus courte", "egale", "plus longue"};
    char buffer[100];
    int val;

    if (argc <= 1) {
        printf("Pas assez de parametres \n ");
        return 1;
    }

    printf("la taille de '%s' est %zu (%d)\n",
            argv[1], strlen(argv[1]), strlength(argv[1])); // le %zu affiche un size_t ... pas oblige d'insister sur celui la

    if (argc <= 2) {
        printf("Pas assez de parametres pour comparer\n ");
        return 2;
    }

    printf("la chaine '%s' est %s que '%s'\n",
            argv[1], egales[strlencmp(argv[1], argv[2]) + 1], argv[2]);

    printf("la chaine '%s' a %d voyelles et '%s' en a '%d'\n", argv[1], voyelles(argv[1]), argv[2], voyelles(argv[2]));

    printf("la chaine '%s' est elle un palindrome: %d\n",
            argv[1], palindrome(argv[1])); // on aurait pu faire ce tableau oui/non mais bon en vrai on utiliserais l'operateur ?: donc je ne le fais pas
    printf("la chaine '%s' est elle un palindrome: %d\n",
            argv[2], palindrome(argv[2]));

    strcpy(buffer, argv[1]); // on doit faire une copie ... sinon c'est segfault !
    mirror(buffer);
    printf("la chaine '%s' a pour mirroir : %s\n", argv[1], buffer);
    mirror2(buffer, argv[2]);
    printf("la chaine '%s' a pour mirroir : %s\n", argv[2], buffer);

    if (argc <= 3) {
        printf("Pas assez de parametres pour transofrmer\n ");
        return 3;
    }

    val = atoi(argv[3]);
    printf("la chaine '%s' vaut : %d\n", argv[3], val);
    itoa(val, buffer);
    printf("la valeur %d vaut : '%s'\n", val, buffer);

    char* tab[argc]; // on ne peut pas modifier argv ... sinon segfault
    for (int i = 0; i < argc; i = i + 1) {
        tab[i] = argv[i];
    }
    bubble_sort(argc, tab);

    printf("parametres triés:\n");
    for (int i = 0; i < argc; i = i + 1) {
        printf("%s\n", tab[i]);
    }
}
