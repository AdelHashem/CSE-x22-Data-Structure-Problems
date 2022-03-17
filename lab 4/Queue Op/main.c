#include <stdio.h>
#include <stdlib.h>

//Build Queue
typedef struct {
    int front;
    int rear;
    int size;
    int *data;
}Queue;

void CreateQueue(Queue* q ,int n)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->data = (int*)malloc(n * sizeof(int));
}

int IsEmpty(Queue* q)
{
    return !q->size;
}

void QueueAdd(Queue* q , int ndata)
{
    q->size ++;
    q->rear ++;
    q->data[q->rear]= ndata;
}

int QueueOut(Queue* q)
{
    int temp = q->data[q->front];
    q->size --;
    q->front ++;
    return temp;
}

void QueuePrint (Queue q)
{
    if (IsEmpty(&q))
    {
        printf("Empty\n");
        return;
    }
    printf("%d",q.data[q.front]);
    q.front ++;
    for (int i=0; i<q.size-1;i++)
    {
        printf(",%d",q.data[q.front]);
        q.front ++;
    }
    printf("\n");
}
//End of Queue Functions


int main()
{
    int Q , E,input;
    scanf("%d",&Q);
    if (Q<0 || Q> 10000000)
        exit(1);
    Queue q ; //use Q to build The Queue
    CreateQueue(&q,Q);

    for(int i = 1;i <=Q;i++)
    {
        scanf("%d",&input);
        if ((input>0) && (input<4))
        {
            switch (input)
            {
            case 1: // Add Queue
                scanf("%d",&E);
                if (E>1000000000 || E < 1)
                    exit(1);
                QueueAdd(&q,E);
                break;
            case 2://delete form the queue
                if (IsEmpty(&q))
                    break;
                else
                    QueueOut(&q);
                break;
            case 3://Print Queue
                QueuePrint(q);
                break;
            }
        }
        else
            exit(1);
    }
    return 0;
}
