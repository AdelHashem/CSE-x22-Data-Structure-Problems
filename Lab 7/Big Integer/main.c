#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrayGet(int size , int *Arr);
void Swap(int*,int*);
void printArray(int*,int);
int combine_check(int a, int b);

unsigned int combine(int a, int b);

void quickSort(int arr[],int start,int end)
{
    if(start < end){
   int pivot = arr[end];
   int ptr = start - 1;

   for (int i = start ; i<end; i++)
   {
       if (combine_check(arr[i], pivot))
       {
           ptr++;
           Swap(&arr[ptr],&arr[i]);
       }
   }
   Swap(&arr[ptr+1],&arr[end]);
   ptr++;

        quickSort(arr,start,ptr -1);
        quickSort(arr,ptr+1,end);
    }


}

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    arrayGet(N,arr);
    quickSort(arr,0,N-1);
    printArray(arr,N);
    return 0;
}

void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}

void printArray(int arr[],int N)
{
    for(int i =0;i<N;i++)
        printf("%d",arr[i]);
}

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned int combine(int a, int b){
    if(b == 0)
        return a*10;
    else if(a ==0)
        return b;


   unsigned int times = 1;
   while (times <= b)
      times *= 10;
   return ((unsigned int) a*times + (unsigned int) b);
}


int combine_check(int a, int b)
{
    int length = snprintf( NULL, 0, "%d", a );
    char* num1 = malloc( length + 1 );
    snprintf( num1, length + 1, "%d", a );

    length = snprintf( NULL, 0, "%d", b );
    char* num2 = malloc( length + 1 );
    snprintf( num2, length + 1, "%d", b );

    if(strcmp(strcat(num1,num2) , strcat(num2,num1)) >= 0 )
    {
        free(num1);free(num2);
        return 1;
    }
    else
    {
       free(num1);free(num2);
        return 0;
    }

}


