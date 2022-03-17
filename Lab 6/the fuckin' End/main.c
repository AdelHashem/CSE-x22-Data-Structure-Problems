#include <stdio.h>
#include <stdlib.h>

void arrayGet(int, int*);
//tree Build and func

typedef struct Tnode{
    int data;
    struct Tnode *left,*right;
}tnode;
typedef tnode *Tree;


//my own structure
typedef struct nodemap
{
    int val;
    int count;
    struct nodemap *next;
}NodeM;
typedef struct{
    NodeM *front,*rear;
    int size;
    int maxcount;
}Map;

void creatMap(Map *m);
NodeM* Mnodecreate(int val);
void push_map(Map *m,int val);
int pop_map(Map *m,int *count);
void maping_tree(Tree t,Map *m);


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
Tree BuildTree(int arr[],int n);



int main()
{
    int N;
    Tree t;
    Map m;
    creatMap(&m);
    t = NULL;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    t=BuildTree(arr,N);
    //printf("root %d",t->data);
    maping_tree(t,&m);
    int maxcount = m.maxcount,count=0;
    for(int i =0 ; i<m.size ;i++)
    {
        if(m.front->count == maxcount)
        {
            printf("%d\n",pop_map(&m,&count));
        }
        else pop_map(&m,&count);
    }
    return 0;
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
//map function
void creatMap(Map *m)
{
    m->front=NULL;m->rear = NULL; m->maxcount =0; m->size = 0;
}


NodeM* Mnodecreate(int val)
{
    NodeM *node = (NodeM*) malloc(sizeof(NodeM));
    node->val = val;
    node->count = 1;
    node->next = NULL;
    return node;
}
void push_map(Map *m,int val)
{
    if(m->size ==0)
    {
        NodeM* nodenew= Mnodecreate(val);
        m->size = 1;
        m->maxcount = 1;
        m->front = nodenew;
        m->rear = nodenew;
    }
    else{
        NodeM *temp = m->front;
        while (temp !=NULL && temp->val != val)
            temp = temp->next;
        if(temp != NULL)
        {
            temp->count++;
            if(temp->count > m->maxcount)
                m->maxcount = temp->count;
        }
        else
        {
            NodeM* nodenew= Mnodecreate(val);
            m->rear->next = nodenew;
            m->rear = nodenew;
            m->size ++;
        }
    }
}
int pop_map(Map *m,int *count)
{
    NodeM *temp = m->front;
    int val = m->front->val;
    *count = m->front->count;
    m->front = m->front->next;
    free(temp);
    return val;
}

void maping_tree(Tree t,Map *m)
{
    if (t==NULL) return;
    maping_tree(t->left ,m);
    push_map(m,t->data);
    maping_tree(t->right,m);
}

void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}
