#include <stdio.h>
#include <stdlib.h>

void arrayGet(int, int*);
//tree Build and func
typedef struct Tnode{
    int data;
    struct Tnode *left,*right;
}tnode;
typedef tnode *Tree;


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
void clrQ(Queue *q);
//End p Queue

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
    //CreateTQueue(&qp);
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

//problem func
void freqTree(Tree t,Tree *pre,Queue *q,int *freq,int *data,int *datapre,int *freqpre)
{
    if(!t){
        if ((*freq)>=(*freqpre) && (*data)!=(*datapre) && (*freq)!=1)
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
        *freq = 0;
        *data = t->data;
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






void inorderFreq(Tree t ,int *curVal ,int *curFreq,int *maxval,int *maxfreq,Queue *q)
{
    if(t == NULL)
    return;
    inorderFreq(t->left,curVal ,curFreq,maxval,maxfreq,q);
    if((*curVal) != t->data){

    (*curVal) = t->data;
    (*curFreq) = 1;
    }else{
    (*curFreq)++;
    if((*curFreq) > (*maxfreq)){
        (*maxval) = (*curVal);
        (*maxfreq) = (*curFreq);
    }
    if ((*curFreq) == (*maxfreq) && (*curFreq) !=1 && (*curVal)!= (*maxval))
        {
            QueueIn(q,(*maxval),(*maxfreq));
            (*maxval) = (*curVal);
            (*maxfreq) = (*curFreq);
        }
    }
    inorderFreq(t->right,curVal ,curFreq,maxval,maxfreq,q);
}


void freq2(Tree t ,int *curVal ,int *curFreq,int *maxval,int *maxfreq,Queue *q)
{
    if(t == NULL)
        return;
    static Tree pre=NULL;
    freq2(t->left,curVal ,curFreq,maxval,maxfreq,q);
    if(!pre)
    {
        (*curVal) = t->data;
        *curFreq = 1;
    }
    else
    {
        if(pre->data == t->data) (*curFreq)++;
        else{
            if((*curFreq) > (*maxfreq)){
                    (*maxval) = (*curVal);
                    (*maxfreq) = (*curFreq);
            }
            if ((*curFreq) == (*maxfreq) && (*curFreq) !=1 && (*curVal)!= (*maxval))
                {
                    QueueIn(q,(*maxval),(*maxfreq));
                    (*maxval) = (*curVal);
                    (*maxfreq) = (*curFreq);
                }
                *curVal = t->data;
                *curFreq = 1;
    }
        }
        if ((*curFreq) == (*maxfreq) && (*curFreq) !=1 && (*curVal)!= (*maxval))
        {
            QueueIn(q,(*maxval),(*maxfreq));
            (*maxval) = (*curVal);
            (*maxfreq) = (*curFreq);
        }

        pre = t;
        freq2(t->right,curVal ,curFreq,maxval,maxfreq,q);

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

Tree mostleft(Tree t)
{
    if(t->left == NULL) return t;
    t=mostleft(t->left);

}


/////
int maxCount = 0;
    int curVal = -90;
    int curCount = 0;

    void findMaxCount(int val,Queue *q) {
        if (val != curVal) {
            curVal = val;
            curCount = 0;
        }
        curCount++;
        if (maxCount < curCount) {
            maxCount = curCount;
            QueueIn(q,val,maxCount);
        }
        else if (maxCount == curCount) {
            QueueIn(q,val,maxCount);
        }
    }

    void inorderTraversal (Tree root,Queue *q) {
        if (root == NULL) return;
        inorderTraversal(root->left,q);
        findMaxCount(root->data,q);
        inorderTraversal(root->right,q);
    }





















int main()
{
    int N;
    Tree t,pre=NULL;
    Queue q;
    CreateQueue(&q);
    t =NULL;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    t=BuildTree(arr,N);
    Tree left = mostleft(t);
    printf("left %d \n",left->data);
    //treeprintprefix(t);
    int data=t->data,freq=1,a=t->data,b=1;
    freqTree(t,&pre,&q,&a,&b,&data,&freq);
    inorderFreq(t,&a,&b,&data,&freq,&q);
    //printf("%d",data);
    //int data=0,freq=0,a=0,b=0;
    //freq2(t,&a,&b,&data,&freq,&q);
    inorderTraversal(t,&q);
    //QueueIn(&q,maxval,maxCount);
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


//// P Queue Func

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
void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}
