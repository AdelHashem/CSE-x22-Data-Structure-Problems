#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapr(int* ,int*);
void bbsort(int ,int*);
int main()
{
    int N,Q;
    scanf("%d %d",&N,&Q);
    int temp = pow(10,4);
    if(0 >= N || N >= 4 * temp)
    {
        printf("Not Valid");
                return 0;
    }
    if(Q >= 4 * temp)
    {
        printf("Not Valid");
                return 0;
    }
    if (Q==0)
    {
        printf("0");
        return 0;
    }

    int h[N],t[Q];
    //Scan h
    for(int j=0;j<N;j++)
        {
            scanf("%d",&h[j]);
            temp = pow(2,31);

        }
        //Scan t
    for(int j=0;j<Q;j++)
        {
            scanf("%d",&t[j]);
            temp = pow(2,31);
            if (t[j]<=0 || t[j]>=temp-1 )
            {
                printf("Not Valid");
                return 0;
            }
        }

        //Sort Data Using Bubble Sort
        bbsort(N,h);
        bbsort(Q,t);


        //maximum number of working developers
        int count=0,j=0;
        for(int i=0;i<N;i++)
        {
            if (t[j]<=h[i])
            {
                count++;
                j++;
            }
            if(j==Q)
            {
                break;
            }
        }

        printf("%d",count);


    return 0;
}
void swapr(int*x ,int*y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void bbsort(int n,int a[n])
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if (a[j] > a[j+1])
                swapr(&a[j],&a[j+1]);
        }
    }
}
