#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node *binaryTree;


// Retora una arbol vacio.
binaryTree newTree(void);

// Inserta un elemento al arbol.
binaryTree insertElementTree(binaryTree tree, int element1, int element2);

// buscar retorna la posicion de element. Si no existe retorna -1 
int searchPositionElement(binaryTree tree, int element);

// Libera la memoria de un arbol.
binaryTree destroyTree(binaryTree tree);

#endif
