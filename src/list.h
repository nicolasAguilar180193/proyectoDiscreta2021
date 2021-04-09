#ifndef _LIST_H
#define _LIST_H

// ------ TAD LISTA ------ //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node_t *list_t;


// Retorna una lista vacía.
list_t listEmpty(void);

// Libera la memoria de la lista.
list_t listDestroy(list_t list);

//Agrega un elemento a la lista.
list_t listAppend(list_t list, int i);

// Borra el primer elemento de la lista.
list_t listPop(list_t list);

// Retorna el primer elemento de la lista.
int listTop(list_t list);

// Retorna el siguiente nodo apuntado por list.
list_t next(list_t list);

// Retorna True si la lista es vacía, false en caso contrario.
bool listIsEmpty(list_t list);
#endif
