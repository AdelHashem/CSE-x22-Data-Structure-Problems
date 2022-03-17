#include <stdio.h>
#include <stdlib.h>
//priority Queue
typedef struct qnode{
int data;
int priority;
struct qnode* next ;
}Qnode;

typedef struct {
Qnode* top;
Qnode *rear;
int size;
}Queue;

int IsEmpty(Queue*);
void CreateQueue(Queue*);
Qnode* NewNode(int,int);
void QueueIn(Queue* q ,int ndata,int pri);
int QueueOut(Queue*q);
int priorityOut(Queue *q);
//End Queue


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

Tree binaryArray_Tree(Tree t,int size,int k,int arr[])
{
    if(k < size)
    {
        Tree Newnode;
        if(arr[k]==-1) return NULL;
        else Newnode = CreatNode(arr[k]);
        t=Newnode;
        t->left=binaryArray_Tree(t->left,size,(k*2)+1,arr);
        t->right=binaryArray_Tree(t->right,size,(k*2)+2,arr);
    }
    return t;
}

void freqTree(Tree t,Tree *pre,Queue *q,int *freq,int *data,int *datapre,int *freqpre)
{
    if(!t){
        if ((*freq)>=(*freqpre) && (*data)!=(*datapre))
        {
            (*freqpre) = (*freq);
            (*datapre) = (*data);
        }
        return;
    }
    freqTree(t->left,pre,q,freq,data,datapre,freqpre);
    if(!(*pre))
    {
        (*pre) = t;
        *freq = 1;
        *data = t->data;
        *datapre = t->data;
        return;
    }
    //printf("\n data %d \n",t->data);
    if((*pre)->data == t->data)
    {
        (*freq)++;
        (*data)=(*pre)->data;
        (*pre) = t;
    }
    else
    {
        if ((*freq)>(*freqpre))
        {
            (*freqpre) = (*freq);
            (*datapre) = (*data);
        }
        else if ((*freq)==(*freqpre) && (*freq) > 1)
        {
            QueueIn(q,(*datapre),(*freq));
            //printf("\n queue %d %d feq %d pre %d \n",*datapre,*data,*freq,*freqpre);
            (*freqpre) = (*freq);
            (*datapre) = (*data);

        }


        (*freq)=1;
        *data = t->data;
        (*pre) = t;
    }

    freqTree(t->right,pre,q,freq,data,datapre,freqpre);
}


void inorder(Tree root,Tree pre,Queue *q,int *freq,int *data,int *datamx,int *freqmx)
{
    // If root is NULL then return
    if (root == NULL) {
        return;
    }
    inorder(root->left, pre,q,freq,data,datamx,freqmx);
    if (pre != NULL) {
        // If the previous value is equal to the current value
        // then increase the count
        if (root->data == pre->data) {
            (*freq)++;
        }
        // Else initialize the count by 1
        else {
            (*freq) = 1;
        }
    }
    // If current count is greater than the max count
    // then update the mx value
    if ((*freq) > (*freqmx)) {
        *freqmx = (*freq);
        *datamx = root->data;
    }
    if((*freq) == (*freqmx) && (*freq) > 1 && root->data != (*datamx))
        {
            QueueIn(q,(*datamx),(*freqmx));
            printf("\n queue %d %d feq %d pre %d \n",*datamx,*data,*freq,*freqmx);
            (*freqmx) = (*freq);
            (*datamx) = root->data;

        }

    // Make the current Node as previous
    pre = root;
    inorder(root->right,pre,q,freq,data,datamx,freqmx);
}





// end Tree

void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
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


int main()
{
    int N;
    Tree t,pre=NULL;
    Queue q;
    CreateQueue(&q);
    Queue *qp;
    t =NULL;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    t=binaryArray_Tree(t,N,0,arr);
    int data=0,freq=0,a=1,b=0;
    //freqTree(t,&pre,&q,&a,&b,&data,&freq);
    inorder(t,&pre,&q,&a,&b,&data,&freq);
    QueueIn(&q,data,freq);
    a=priorityOut(&q);
    b=q.size;

    //printf("%d\n",data);
    if(!IsEmpty(&q))
    {
        for(int i=0;i<b;i++)
        {
            if(a == priorityOut(&q))
                printf("%d\n",QueueOut(&q));
        }
    }

    return 0;
}

//p Queue
//Building Queue
int IsEmpty(Queue*q)
{
return !q->size;
}
void CreateQueue(Queue *q)
{
    q->top = NULL;
    q->rear = NULL;
    q->size = 0;
}

Qnode* NewNode(int ndata,int prio)
{
    Qnode *temp = (Qnode*) malloc(sizeof(Qnode));
    temp->data = ndata;
    temp->priority = prio;
    temp->next = NULL;
    return temp;
}


void QueueIn(Queue* q ,int ndata,int pri)
{
Qnode *newn = (Qnode*)malloc(sizeof(Qnode));
newn->data = ndata;
newn->priority = pri;
newn->next=NULL;

if (IsEmpty(q))
{
q->top = newn;
q->rear = newn;
q->size ++;
}
else if (q->top->priority < pri)
{
newn->next=q->top;
q->top = newn;
q->size ++;
}
else
{
Qnode *temp = q->top;
while(temp->next != NULL && pri >= temp->next->priority)
{
temp=temp->next;

}
newn->next = temp->next;
temp->next =newn;
q->size++;
}
}

int priorityOut(Queue *q)
{
    return q->top->priority;
}

int QueueOut(Queue*q)
{
    Qnode *qtemp = q->top;
    int temp;
    temp= qtemp->data;
    q->top = qtemp->next;
    q->size --;
    free(qtemp);
    return temp;
}

//End Queue
