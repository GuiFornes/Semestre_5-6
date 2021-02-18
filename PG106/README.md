

# Coding Convention
- english language for structure names and comments
- *Variables* without capital letters (i, x, cmp, temp, ...)
- *function* names separated with *_* (number_of_tile, get_score, quick_sort) *snake case*
- adding *rec* for recursives func (id_rec, sort_rec)
- *macros* full caps and *_* (NB_PLAYERS, MAX_LENGTH)
- les *accolades*: style *K&R*
    - pour les functions : à la ligne
```c
void fun()
{
    *code*
}
```
    - pour les boucles : que la 2e à la ligne
```c
for (int i = 0 ; i < n ; i++){
    *code*
}
```
- header comme *<stdio.h>*, next **
