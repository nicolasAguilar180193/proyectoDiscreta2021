#include "binaryTree.h"

struct node {
    int position;
    int name;
    binaryTree left;
    binaryTree right;
};

binaryTree newTree(void){
    binaryTree tree = NULL;
    return tree;
}

binaryTree insertElementTree(binaryTree tree, int name, int position){
    if(tree == NULL) { 
        tree = calloc(1 ,sizeof(struct node));
        tree->left = NULL;
        tree->right = NULL;
        tree->name = name;
        tree->position = position;
    } else {
        if (tree->name < name){
            tree->left = insertElemnt(tree->left, name, position);
        } else {
            tree->right = insertElemnt(tree->right, name, position);
        }
    }
    return tree;
}

int searchPositionElement(binaryTree tree, int name) {
    int position = -1;
    if (tree != NULL){
        if (tree->name == name) {
            position = tree->position;
        }
        else if (tree->name < name) {
            searchTree(tree->left , name);
        } else {
            searchTree(tree->right, name);
        }
    }
    return position;
}

binaryTree destroyTree(binaryTree tree) {
    if (tree != NULL) {
        tree->left = destroyTree(tree->left);
        tree->right = destroyTree(tree->right);
        free(tree);
        tree = NULL;
    }
    return tree;
}
