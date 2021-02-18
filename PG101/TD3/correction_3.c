#include <stdio.h> // Pour les printf
#include <stdlib.h> // pour atoi
#include <string.h> // pour strcmp

int is_leap(int year) // Also called leap year
{
    return (year % 4 == 0 && year % 100) || year % 400;
}

int days_count(int mounth, int year)
{
    switch (mounth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        return is_leap(year) ? 29 : 28; // Note: 28 + is_leap(year) marche aussi
    case 4: // Pourquoi faire ces cas la, quand on pourrait tout mettre dans le default ?
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return -1;
    }
}

/* Personellement, j'aime moins cette solution. En effet les conditions sont moins claires
 * et deviendraient compliqué s'il y avait plus d'un cas particulier */
int days_count2(int month, int year)
{
    int day_by_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12)
        return -1;

    days = day_by_month[month - 1];

    if (days < 30)
        days += is_leap(year);
    return days;
}

int exo1(int argc, char* argv[])
{
    int month = (argc > 1) ? atoi(argv[1]) : 4;
    int year = (argc > 2) ? atoi(argv[2]) : 2013;

    printf("l'annee %d %s bissextile", year, is_leap(year) ? "est" : "n'est pas");
    printf("le mois '%d' a '%d' jours\n", month, days_count(month, year)); // exo 1
    return 0;
}

void print_ascii_table_1()
{
    printf("Char.\tdec.\thex\toct\n");
    for (int i = 32; i <= 0xFF; i = i + 1)
        printf("%c\t%d\t%x\t%o\n", i, i, i, i);
    //for(char i = 0; i <= 0xFF ; i = i + 1) // Avec des char au lieu des ints
    //      printf("%hhc\t%hhd\t%hhx\t%hho", i, i, i, i);
}

void print_ascii_table_2(int n)
{
    if (!n) n = 1; // Pour eviter la division par zero
    for (int i = 0; i < n; i = i + 1)
        printf("Char.\tdec.\thex\toct\t");  // note, on aura un tab de trop
                                            // ... mais c'est pas trop grave, sinon il faut faire un if.
    printf("\n");

    for (int i = 32; i <= 0xFF; i = i + 1) {
        printf("%c\t%d\t%x\t%o", i, i, i, i);
        printf((i % n == n - 1 || i == 0xFF) ? "\n" : "\t");
    }
}

void print_ascii_table_3(int n, int min, int max)
{
    if (n < 1) n = 1;
    if (n > (max - min)) // on s'assure qu'il n'y ai pas plus de colonnes que d'entrées à afficher
        n = max - min;
    for (int i = 0; i < n ; i = i + 1)
        printf("Char.\tdec.\thex\toct%s", (i % n == n - 1) ? "\n" : "\t");  // Cette fois on a pas le tab de trop
                                                                            // ... mais c'est nettement plus compliqué

    for (int i = min; i <= max; i = i + 1) {
        int c = (i < 32) ? 32 : i;
        printf("%c\t%d\t%x\t%o", c, c, c, c);
        printf((i % n == n - 1 || i == max) ? "\n" : "\t");
    }
}

int exo2(int argc, char* argv[])
{
    int nb = 4;
    int min = 32;
    int max = 255;

    if (argc > 1)  // Dans le cas du bonus, pour assurer qu'on lit bien tout le monde
        nb = atoi(argv[argc - 1]);
    for (int i = 1; i < argc - 1; i = i + 1)  // Pour le bonus
        if (strcmp(argv[i], "--min") == 0) {
            i = i + 1;
            min = atoi(argv[i]);
        } else if (strcmp(argv[i], "--max") == 0) {
            i = i + 1;
            max = atoi(argv[i]);
        } else
            nb = atoi(argv[i]);

    printf("%d %d %d \n", nb, min, max);

    print_ascii_table_1();
    printf("\n");
    print_ascii_table_2(nb);
    printf("\n");
    print_ascii_table_3(nb, min, max);
    printf("\n");
    return EXIT_SUCCESS;
}

// Avec un sizeof
// Complexite : sizeof(int)
int bit_count_1(int nb)
{
    int count = 0;
    for (int j = 0; j < sizeof(nb) * 8; j = j + 1) {
        if (nb & (1 << j))
            count = count + 1;
    }
    return count;
}

// Plus efficace en moyenne (pareil dans le pire des cas)
// Complexite : dernier bit a gauche (most significant bit)
int bit_count_2(unsigned nb)
{ // On est oblige de le considerer comme non-signe a cause du décalage a droite
    int count = 0;
    while (nb) {
        if (nb & 1)
            count = count + 1;
        nb = nb >> 1;
    }
    return count;
}

/* Ceci est une variation de bit_count_2, qui n'utilise pas de unsigned*/
int bit_count_2_2(int nb)
{
    int count = 0;
    if (nb < 0) {
        nb &= 1 << (sizeof(nb) * 8 - 1); // on enleve le bit de poit fort
        count = count + 1;
    }

    while (nb) {
        if (nb & 1)
            count = count + 1;
        nb = nb >> 1;
    }
    return count;
}

// La version du hackers delight
// Plus efficace en moyenne (pareil dans le pire des cas)
// Complexite : nombre de bit a 1
int bit_count_3(int nb)
{
    int count = 0;
    while (nb) {
        count = count + 1;
        nb = nb ^ (nb & -nb);
    }
    return count;
}

// La version qui marche que avec des entiers de 32bits et qui poutre, ditte 'parallel count'
// sur une machine moderne (i.e. temps constant et sans condition [sans branchement])
int bit_count_4(unsigned i) // Unsigned à cause des décallage à droite
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int exo3(int argc, char *argv[])
{
    for (int i = 1; i < argc; i = i + 1) {
        int nb = atoi(argv[i]);
        printf("%d contient %d %d %d bits a 1\n",
                nb, bit_count_1(nb), bit_count_2(nb), bit_count_3(nb));
    }
    return EXIT_SUCCESS;
}
