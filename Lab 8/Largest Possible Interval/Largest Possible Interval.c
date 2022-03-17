#include <stdio.h>
#include <stdlib.h>

void arrayGet(int size , int *Arr);
void Swap(int*,int*);

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

int Interval(int arr[],int N,int i)
{
    if(i+1 < N )
    {
        int cur = arr[i+1] - arr [i] ;
        int next = Interval(arr,N,i+1);
        if(next > cur )
            return next;
        else return cur;
    }
    return 0;

}

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    if(N == 0)
    {
        printf("0");
        return 0;
    }

    heapSort(arr,N);

    printf("%d",Interval(arr,N,0));

    return 0;
}


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
