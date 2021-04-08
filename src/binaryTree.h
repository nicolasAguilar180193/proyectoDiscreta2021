#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node *binaryTree;


// Retora una arbol vacio.
binaryTree newTree(void);

// Inserta un elemento al arbol.
binaryTree insertElemnt(binaryTree tree, int e1, int e2);

// Libera la memoria de un arbol.
binaryTree destroyTree(binaryTree tree);

// buscar retorna la posicion de element. Si no existe retorna -1 
int searchTree(binaryTree tree, int element);

#endif
