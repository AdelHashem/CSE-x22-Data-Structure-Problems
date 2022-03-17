#include <stdio.h>
#include <stdlib.h>


//Building Queue

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
else if (q->top->priority >= pri)
{
newn->next=q->top;
q->top = newn;
q->size ++;
}
else
{
Qnode *temp = q->top;
while(temp->next != NULL && pri > temp->next->priority)
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



int main()
{
    Queue Q;
    CreateQueue(&Q);

    int n,d,i;
    scanf("%d",&n);
    if (n>10000 || n < 0)
            exit(1);
    int n2 = n;

    for (int k= 0; k<n; k++)
    {
        scanf("%d %d",&d,&i);
        if (i>10000 || i < 1)
            exit(1);
        if (d>10000 || d < 1)
            exit(1);

        if (i<d)
        {
            n2 --;
            continue;
        }
        QueueIn(&Q,d,i);
    }

    int course = 0,pr=0 ,days=0;

    for (int k=0;k<n2;k++)
    {
        int temp;
        pr = priorityOut(&Q);
        temp = QueueOut(&Q);
        if (days + temp <= pr)
        {
            days = days + temp;
            course ++;
        }
    }
    printf("%d",course);

    return 0;
}
