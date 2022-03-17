#include <stdio.h>
#include <stdlib.h>
void Swap(int *a,int *b);
void arrayGet(int ,int*);
void shellSort(int arr[],int n)
{
    for(int i = n/2 ; i > 0; i=i/2)
    {
        for(int k = i;k < n ; k++)
        {
            int j,temp = arr[k];
            for(j = k; j <= i && arr[j-i]< temp; j= j-i )
               arr[j]=arr[j-i];
            arr[j] = temp;

        }
    }
}


int main()
{
    int N , k;
    scanf("%d %d",&N,&k);
    int arr[N];
    arrayGet(N,arr);
    shellSort(arr,N);
    printf("%d",arr[k-1]);

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
