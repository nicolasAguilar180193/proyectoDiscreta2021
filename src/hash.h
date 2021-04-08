#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

// puntero a una hash table.
typedef struct hashTableSt *hashTable; 


// Retorna un hash table vacio del tamaño de length.
hashTable newHash(int length);

// Agrega un elemento a la hash Table.
hashTable insertElemntHash(hashTable hash, unsigned int name, int position);

// Busca un elemento en la hash Table.
int searchElemntHash(hashTable hash, unsigned int name);

// Libera la momoria de la hash Table.
hashTable destroyHash(hashTable hash);

#endif
