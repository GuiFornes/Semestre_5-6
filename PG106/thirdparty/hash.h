#ifndef __HASH_H_
#define __HASH_H_
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define HASH_SIZE 13 // prime number

struct cell {
  void *donnee;
  struct cell *next,*prev;
};

struct hash_table{
  int (*cmp)(void *,void *);
  int (*hash)(void *);
  struct cell **entry;
  int size;
};

//Create and return a new cell filled with donnee in param
struct cell *hash_newcell(void *donnee);

//Create and return the hash table with reserved memory thanks to malloc
struct hash_table *hash_init(int (*cmp)(void *,void *), int (*hash)(void *));

//adding donnee in a new cell of hash table
int hash_add(struct hash_table *hash,void *donnee);

//search for donnee in the hash table (return 1 if found)
int hash_cherche(struct hash_table *hash,void *donnee);

//erase the hash table and free the memory used by malloc
void hash_free(struct hash_table *hash, void (*release)(void *));

#endif // __HASH_H_
