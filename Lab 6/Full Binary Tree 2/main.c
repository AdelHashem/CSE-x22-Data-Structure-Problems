#include <stdio.h>
#include <stdlib.h>

void arrayGet(int, int*);
//tree Build and func
typedef struct Tnode{
    int data;
    struct Tnode *left,*right;
}tnode;
typedef tnode *Tree;

//Building Queue for the Tree

typedef struct qnodet{
Tree data;
struct qnodet* next ;
}Qtnode;

typedef struct {
Qtnode* top;
Qtnode *rear;
int size;
}TQueue;

void CreateTQueue(TQueue *q)
{
    q->top = NULL;
    q->rear = NULL;
    q->size = 0;
}
int IsqtEmpty(TQueue*q)
{
return !q->size;
}
void QueueTIN(TQueue *q,Tree node)
{
    Qtnode *Nnode = (Qtnode*) malloc(sizeof(Qtnode));
    Nnode->data = node;
    Nnode->next =NULL;
    if(IsqtEmpty(q))
    {
        q->top =Nnode;
        q->rear = Nnode;
        q->size++;
    }
    else
    {
        q->rear->next =Nnode;
        q->rear = Nnode;
        q->size ++;
    }
}
Tree QueueTOut(TQueue *q)
{
    Tree node;
    node = q->top->data;
    Qtnode *temp = q->top;
    q->top = q->top->next;
    q->size--;
    free(temp);
    return node;
}
//End Queue for tree
//TREE

Tree CreatTNode(int data)
{
    Tree newnode = (Tree) malloc(sizeof(tnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Tree BuildTree(int arr[],int n)
{
    TQueue qp;
    CreateTQueue(&qp);
    int i = 0;
    Tree root = CreatTNode(arr[i]);
    QueueTIN(&qp,root);
    //printf("\n %d\n",qp.top->data->data);
    i++;
    while(i < n)
    {
        Tree cur = QueueTOut(&qp);
        if (i < n && arr[i]!=-1)
        {
            Tree temp = CreatTNode(arr[i]);
            //printf("\n %d\n",arr[i]);
            cur->left = temp;
            QueueTIN(&qp,temp);
        }
        if(i+1<n && arr[1+i]!= -1)
        {
            Tree temp = CreatTNode(arr[i+1]);
            //printf("\n %d\n",arr[i+1]);
            cur->right = temp;
            QueueTIN(&qp,temp);
        }
        i+=2;
    }
    return root;
}

int checkFullTree(Tree t)
{
    if(t==NULL)
        return 1;
    else if(t->left ==NULL && t->right ==NULL)
        return 1;
    else if(t->left ==NULL && t->right !=NULL)
        return 0;
    else if (t->left !=NULL && t->right ==NULL)
        return 0;
    else
        return(checkFullTree(t->left) && checkFullTree(t->right));
    return 0;
}


int main()
{
    int N;
    Tree t;
    t =NULL;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    t=BuildTree(arr,N);
    if(checkFullTree(t))
        printf("YES");
    else
        printf("NO");
    return 0;
}

void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}

