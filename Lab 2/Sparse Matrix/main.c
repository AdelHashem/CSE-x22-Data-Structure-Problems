#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GetSize(int n,int m,int arr[n][m])
{
    int size=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (arr[i][j] != 0)
                size ++;
        }

    }
return size;
}


int main()
{
    int m,n,k,w;
    //first array
    scanf("%d %d",&n,&m);
    int X[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&X[i][j]);
            int temp = pow(2,31);
            if (X[i][j]>=temp-1 || X[i][j]<=-temp )
                printf("Not Valid");
        }

    }
    //second array
    scanf("%d %d",&k,&w);
    int Y[k][w];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&Y[i][j]);
            int temp = pow(2,31);
            if (Y[i][j]>=temp-1 || Y[i][j]<=- temp )
                printf("Not Valid");
        }
    }


    //Sparse Array
    int size_x = GetSize(n,m,X);
    int SP_X[3][size_x];
    int size_y = GetSize(k,w,Y);
    int SP_Y[3][size_y];
    //Make sp of X
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (X[i][j] != 0)
                {
                    SP_X[0][c] = i;
                    SP_X[1][c] = j;
                    SP_X[2][c] = X[i][j];
                    c++;
                }
        }
    }
//Make sp of Y
    c=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<w;j++)
        {
            if (Y[i][j] != 0)
                {
                    SP_Y[0][c] = i;
                    SP_Y[1][c] = j;
                    SP_Y[2][c] = Y[i][j];
                    c++;
                }
        }

    }

//Multiply
if (m == k)
{


int result[n][w];

for (int i = 0; i < n; i++)
  for (int j = 0; j < w; j++)
    result[i][j] = 0;

for (int i = 0;i < size_x;i++)
{
    for (int j = 0;j < size_y;j++)
    {
        if (SP_X[1][i] == SP_Y[0][j])
            result[SP_X[0][i]][SP_Y[1][j]] = result[SP_X[0][i]][SP_Y[1][j]] + (SP_X[2][i] *  SP_Y[2][j] );
    }
}
//print
for(int i=0;i<n;i++)
    {
        for(int j=0;j<w;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");

    }
}
else
    printf("Not Valid");
    return 0;
}
