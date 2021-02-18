#include "hash.h"

// Create and return a new cell filled with donnee in param
struct cell *hash_newcell(void *donnee)
{
  struct cell *c=malloc(sizeof(*c));
  c->donnee=donnee;
  c->next=c->prev=NULL;
  return c;
}

//
struct hash_table *hash_init(int (*cmp)(void *,void *), int (*hash)(void *))
{
  struct hash_table *hasht;
  int i;
  assert(cmp!=NULL);
  assert(hash!=NULL); 
  hasht = malloc(sizeof(*hasht));
  if (hasht==NULL) return NULL;
  hasht->cmp=cmp;
  hasht->hash=hash;
  hasht->entry=malloc(sizeof(*(hasht->entry))*HASH_SIZE);
  if (hasht->entry==NULL){
    free(hasht);
    return NULL;
  }
  hasht->size=HASH_SIZE;
  for(i=0;i<hasht->size;++i) hasht->entry[i]=NULL;
  return hasht;
}

//adding donnee in a new cell of hash table
int hash_add(struct hash_table *hash,void *donnee)
{
  int value;
  int c;
  struct cell *cell=hash_newcell(donnee);
  assert(hash!=NULL);
  value=hash->hash(donnee);  
  fprintf(stderr,"DEBUG: hash value is %d \n",value);
  if (hash->entry[value%hash->size]==NULL){
    hash->entry[value%hash->size]=cell;
  } else {
    struct cell *q=NULL,*p=hash->entry[value%hash->size];
    while((p!=NULL) && ((c=hash->cmp(donnee,p->donnee))>0)){
      q=p;
      p=p->next;    
    }
    if (c==0)
	return 1; // element is already in the table
    if (q==NULL){
      p->prev=cell; cell->next=p;
      hash->entry[value%hash->size]=cell;
    }else{
      q->next = cell; cell->prev=q;
    } 
  }
  return 0;
}

//search for donnee in the hash table (return 1 if found)
int hash_cherche(struct hash_table *hash,void *donnee){
  int r=0,value;
  assert(hash!=NULL);
  value=hash->hash(donnee);  
  struct cell *p=hash->entry[value%hash->size];
  while((p!=NULL) && (r=hash->cmp(donnee,p->donnee)<0))
    p=p->next;
  if (r==0) return 0;
  if (p==NULL) return 1;
  return 1;
}

//erase the hash table and free the memory used by malloc
void hash_free(struct hash_table *hash, void (*release)(void *)){
  int i;
  assert(hash!=NULL);
  for(i=0;i<hash->size;++i){
    struct cell *p=hash->entry[i];
    if (p==NULL) continue;
    while(p->next!=NULL){
      p=p->next;
      if (release!=NULL)
	release(p->prev->donnee);
      free(p->prev);
    }
  }
  free(hash->entry);
  free(hash);    
}

