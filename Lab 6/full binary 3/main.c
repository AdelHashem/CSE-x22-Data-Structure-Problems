#include <stdio.h>
#include <stdlib.h>

//Building Binary Tree

typedef struct tnode{
    int data;
    struct tnode *left, *right, *parent;
}Tnode;

typedef Tnode * Tree;

void CreateTree(Tree *t)
{
    *t = NULL;
}

int IsEmpty(Tree *t)
{
    return (!*t);
}

Tree creatTnode(char s)
{
    Tree newNode = (Tnode*)malloc(sizeof(Tnode));
    newNode->data = s;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}
// End Tree



int main()
{
    printf("Hello world!\n");
    return 0;
}
