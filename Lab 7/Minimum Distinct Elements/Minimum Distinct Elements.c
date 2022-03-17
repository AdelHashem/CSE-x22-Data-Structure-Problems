#include <stdio.h>
#include <stdlib.h>
void arrayGet(int ,int*);


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
int pop_map(Map *m);
void Mapkill(Map *m);

typedef struct
{
    int val;
    int count;
}freq;
void printele(freq arr[],int N);

void merge(freq arr[],int a,int b , int c)
{
    int size1 = b - a + 1;
    int size2 = c - b;

    freq arr1[size1] , arr2[size2];

    for (int i = 0; i < size1; i++)
        arr1[i] = arr[a + i];
    for (int j = 0; j < size2; j++)
        arr2[j] = arr[b + 1 + j];

    int i =0,j=0,k=a;

    while(i < size1 && j < size2){
        if(arr1[i].count <= arr2[j].count){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
     while(j < size2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(freq arr[],int start,int end)
{
    if(start < end)
    {
        int half = start + (end - start) / 2;
        mergeSort(arr,start,half);
        mergeSort(arr,half+1,end);
        merge(arr,start,half,end);
    }
}

int main()
{
    int N , r;
    scanf("%d %d",&N,&r);
    int arr[N];
    arrayGet(N,arr);
    Map m;
    creatMap(&m);
    for(int i = 0 ;i<N;i++)
        push_map(&m,arr[i]);
    int n2 =m.size;
    freq arrfreq[n2];
    for(int i = 0 ;i<n2;i++){
        arrfreq[i].count = m.front->count;
        arrfreq[i].val = pop_map(&m);
    }

    mergeSort(arrfreq,0,n2-1);
    printele(arrfreq,n2);

    int i = 0;
    while (r > 0)
    {
        if(arrfreq[i].count <= r)
        {
            r = r - arrfreq[i].count;
            i++;
        }else
        {
            break;
        }

    }

    if ( n2-i > 0)
        printf("%d",n2-i);
    else
        printf("0");



    return 0;
}

void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}

void printele(freq arr[],int N)
{
    for(int i = 0 ; i< N; i++)
        printf("val %d count %d \n",arr[i].val,arr[i].count);
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
int pop_map(Map *m)
{
    NodeM *temp = m->front;
    int val = m->front->val;
    //*count = m->front->count;
    m->front = m->front->next;
    free(temp);
    return val;
}
void Mapkill(Map *m)
{
    for(int i = 0 ; i< m->size ;i++)
        pop_map(m);
}

