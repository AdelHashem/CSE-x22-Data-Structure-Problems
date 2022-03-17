#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int front;
    int rear;
    int size;
    int *data;
}Queue;

void CreateQueue(Queue* q ,int n);
int IsEmpty(Queue* q);
int QueueOut(Queue* q);
void QueueAdd(Queue* q , int ndata);

void Swap(int *a,int *b);
void heapify(int arr[],int size , int i);
void heapSort(int arr[],int size);

int degree_out(int v,int N,int adj[N][N]);
int topological(Queue *q,int N ,int adj[N][N],int degree[],Queue *res);


int main()
{
    int N,E;
    scanf("%d %d",&N,&E);
    int adj[N][N];
    for(int i = 0 ; i<N ;i++)
        for(int j = 0 ; j<N ;j++)
            adj[i][j] = 0;
    int a,b;
    for(int i =0 ; i<E ; i++)
    {
        scanf("%d %d",&a,&b);
        adj[a-1][b-1]=1;
    }
    int degree[N];
    Queue q ,res ; //use N to build The Queue
    CreateQueue(&q,N);
    CreateQueue(&res,N);
    for(int i = 0 ; i<N ;i++)
    {
        degree[i] = degree_out(i,N,adj);
    }

    if (topological(&q,N,adj,degree,&res) == -1)
    {
        printf("-1");
    }
    else
    {
        int result[res.size];
        int i =0;
        while(!IsEmpty(&res))
        {
            result[i++] = QueueOut(&res);
        }
        heapSort(result,i);

        for(int k = 0; k<i ; k++)
        {
            if(k != 0)
                printf("\n");
            printf("%d",result[k]);

        }
    }



    return 0;
}

int degree_out(int v,int N,int adj[N][N])
{
        int i,deg = 0;
        for(i=0; i<N; i++)
                if(adj[v][i] == 1)
                        deg++;
        return deg;
}

int topological(Queue *q,int N ,int adj[N][N],int degree[],Queue *res)
{
   for(int i = 0 ; i<N ;i++)
    {
        if(degree[i] == 0)
        {
            QueueAdd(q,i);
            QueueAdd(res,i+1);
        }
    }
    if(IsEmpty(q))
    {
        return -1;
    }
    int a;
    while(!IsEmpty(q))
    {
        a = QueueOut(q);

        for(int i=0; i<N; i++){
            if(adj[i][a] == 1)
            {
                degree[i]--;
                if(degree[i] == 0)
                {
                    QueueAdd(q,i);
                    QueueAdd(res,i+1);
                }
            }
        }

    }
    return 1;
}



//Queue
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

//sort
void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int size , int i)
{
    int biggest = i, left = i*2+1, right = i*2+2;

    if(left < size && arr[left] > arr[biggest]) biggest = left;

    if(right < size && arr[right] > arr[biggest]) biggest = right;

    if(biggest != i)
    {
        Swap(&arr[i],&arr[biggest]);
        heapify(arr,size,biggest);
    }
}

void heapSort(int arr[],int size)
{
    for(int i = size/2 -1 ; i>=0 ;i--) heapify(arr,size,i);

    for(int i= size - 1; i>=0 ; i--){
        Swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

