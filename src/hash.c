#include "hash.h"
#include <math.h>

struct hashTableSt {
    int length;
    binaryTree* array; // Arbol para colisiones.
};


hashTable newHash(int length){
    hashTable hash = calloc(1, sizeof(struct hashTableSt));
    hash->array = calloc(length, sizeof(binaryTree));
    hash->length = length;
    return hash;
}


unsigned int hashFunction(unsigned int x, int length) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return (x % length);
}

hashTable insertElemntHash(hashTable hash, unsigned int name, int position) {
    int pos = hashFunction(name, hash->length);
    hash->array[pos] = insertElementTree(hash->array[pos], name, position);
    return hash;
}

int searchElemntHash(hashTable hash, unsigned int name) {
    int pos = hashFunction(name, hash->length);
    return searchPositionElement(hash->array[pos], name);
}

hashTable destroyHash(hashTable hash) {
    int i = 0;
    while (i < hash->length) {
        hash->array[i] = destroyTree(hash->array[i]);
        i++;
    }
    free(hash->array);
    free(hash);
    hash = NULL;
    return hash;
}
