#include <stdio.h>
#include <stdlib.h>

//tree Build and func
typedef struct Tnode{
    int data;
    struct Tnode *left,*right;
}tnode;
typedef tnode *Tree;

Tree CreatNode(int data)
{
    Tree newnode = (Tree) malloc(sizeof(tnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int IsTEmpty(Tree* t)
{
    return (!*t);
}

void InsertTree(Tree*t,int data)
{
    Tree newnode = CreatNode(data);
    if (IsTEmpty(t))
    {
        *t = newnode;
        return;
    }
    else if(data > (*t)->data)
        InsertTree(&(*t)->right,data);
    else if(data < (*t)->data)
        InsertTree(&(*t)->left,data);
    else
    {
        if(!((*t)->left))
            InsertTree(&(*t)->left,data);
        else
            InsertTree(&(*t)->right,data);
    }

}

void TreeBalancedBuild(Tree *t ,int start,int end ,int arr[])
{
   if(start > end) return;
   int root = (start + end)/2;
   InsertTree(t,arr[root]);
   TreeBalancedBuild(t,root+1,end,arr);
   TreeBalancedBuild(t,start,root-1,arr);
}

void treeprintprefix(Tree t)
{
    if(t)
    {
        printf(",%d",t->data);
        treeprintprefix(t->left);
        treeprintprefix(t->right);
    }
}
//End Tree


void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}



int main()
{
    int N;
    Tree t;
    t =NULL;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    TreeBalancedBuild(&t,0,N-1,arr);
    printf("%d",t->data);
    treeprintprefix(t->left);
    treeprintprefix(t->right);
    return 0;
}
