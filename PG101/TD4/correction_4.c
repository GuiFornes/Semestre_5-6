#include <stddef.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void order(int* a, int* b, int* c)
{
    if (*a > *b) {
        swap(a, b);
    }
    // now *a is < *b
    if (*b > *c) {
        swap(b, c);
        // now *b < *c ... but we don't know anymore for a
        if (*a > *b) {
            swap(a, b);
        }
    }
}

void min_max(int l, int t[], int* min, int* max)
{
    int m = t[0];
    int M = t[0];
    for (int i = 1; i < l; i++) {
        if (m > t[i])
            m = t[i];
        if (M < t[i])
            M = t[i];
    }
    if (min)
        *min = m;
    if (max)
        *max = M;
}

char* stp_copy(char* dst, const char* src)
{
    // Rappel *src++, le ++ est fait en premier
    // mais son évaluation retourne la valeur
    // AVANT la modification du pointeur
    // En cas de doute, effectuez les ++ sur des lignes différentes
    do { // Le do while est utilisé pour ne pas avoir à copier manuellement le zéro terminal
        *dst++ = *src;
    } while (*src++ != 0);
    return dst;
}

size_t str_lenght(const char* src)
{
    const char* p = src;
    while (*p) {
        p++;
    }
    return p - src;
}

int str_compare(const char* s1, const char* s2)
{
    while (*s1) {
        if (*s2 == 0) // s2 se termine avant s1
            return -1; // s2 est donc avant dans le dictionnaire
        if (*s1 != *s2) // Les deux chaines divergents
            return *s1 - *s2; // le signe de la différence donne l'ordre
        s1++;
        s2++;
    }
    // s1 est terminée donc soit s2 l'est aussi, soit s1 est après
    return *s2 != 0;
}

char* str_concat(char* s1, const char* s2)
{
    char* p = s1 + str_lenght(s1); // on avance s1 jusqu'à son zéro terminal
    stp_copy(p, s2); // on copie s2 à la fin de s1 (p)
    return s1; // on retourne l'original
}

void b_zero(char* p, size_t n)
{
    while (n--) {
        *p++ = 0; // En cas de doute sur ce qu'il se passe, faites le en deux lignes.
    }
}

void* mem_copy(void* dst, const void* src, size_t len)
{
    const char* s = src; // on transforme nos pointeurs génériques
    char* d = dst;    // vers des pointeurs de caractères (car leur taille est un octet)
    while (len--)
        *d++ = *s++;
    return dst;
}

int mem_compare(void* src, void* dst, size_t len)
{
    const unsigned char* s = src; // on transforme nos pointeurs génériques
    unsigned char* d = dst;    // vers des pointeurs de caractères non signées (cf. memcmp)
    while (len--) {
        if (*s != *d)
            return *s - *d;
        s++;
        d++;
    }
    return 0;
}

void* mem_set(void* src, int c, size_t len)
{
    unsigned char* p = src;
    unsigned char value = (unsigned char)c; // Cette notation horrible est un `cast`
    // Cela force la conversion vers un unsigned char (troncature des bits en trop etc.)
    // Les cast sont à proscrire tant que ce peut, nous sommes ici dans un des rares
    // cas qui en à besoin.
    while (len--) {
        *p++ = value;
    }
    return src;
}

void swab(const void* src, void* dest, size_t nbytes)
{
    const char* s = src;
    char* d = dest;
    while (nbytes > 1) {
        *d = *(s + 1);
        *(d + 1) = *s;
        s += 2;
        d += 2;
        nbytes -= 2;
    }
    if (nbytes) // le cas ou nbytes est impair
        *d = *s;
}
