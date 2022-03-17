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

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    if(N == 0)
    {
        printf("Not Exist");
        return 0;
    }

    heapSort(arr,N);

    int m = (N + 1) / 2;
    int rem = (N + 1) % 2;

    if(rem == 0) printf("%d",arr[m-1]);
    else
    {
        float med = arr[m-1] + arr[m];
        med /=2;
        if(med * 10 == (int)med * 10 )
            printf("%.0f",med);
        else
            printf("%.1f",med);
    }



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
