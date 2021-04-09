#include "list.h"


struct _node_t {
    int i;
    list_t next; // Puntero al siguente nodo.
};

list_t listEmpty(void) {
    list_t l = NULL;
    return(l);
}

list_t listDestroy(list_t list) {

    list_t aux = NULL;
    while (list != NULL) {
        aux = list;
        list = list->next;
        free(aux);
    }
    return list;
}

list_t listAppend(list_t list, int i) {

    list_t new = calloc(1, sizeof(struct _node_t));
    new->i = i;
    new->next = list;
    return(new);
}

list_t listPop(list_t list) {
    if (list != NULL) {
        list_t aux = list;
        list = list->next;
        free(aux);
    }
    return(list);
}

int listTop(list_t list) {
    return list->i;
}

list_t next(list_t list) {
    return(list->next);
}

bool listIsEmpty(list_t list) {
  return list == NULL;
}
