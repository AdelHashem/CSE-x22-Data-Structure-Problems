#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void arrayGet(int size , int *Arr){
    for(int i = 0;i < size;i++){
        scanf("%d",&Arr[i]);
    }
}

int FullTreeCheck(int size , int *arr)
{
    if (arr[0]==-1) return 1;
    else{
        int h = (int) log2(size + 1) - 1;
        for (int i=1;i<=h ;i++)
        {
            int correction = (int) pow(2,i) -1;
            for (int j = correction ; j<=(correction*2) ; j = j+2)
            {
                if (arr[j]!=-1 && arr[j+1]!= -1) continue;
                else if (arr[j]==-1 && arr[j+1]== -1) continue;
                else return 0;

            }


        }

        int size_correction = (int) pow(2,h+1) -1;
        if (size == size_correction) return 1;
        else
            {
                if((size-size_correction)%2 == 0)
                {
                    for (int k=size-1 ; k > size_correction -1;k=k-2)
                    {
                    if(arr[k]!=-1 && arr[k-1]!=-1) continue;
                    else if (arr[k]==-1 && arr[k-1]== -1) continue;
                    else return 0;
                    }
                return 1;
                }
                else{
                    if (arr[size] != -1) return 0;
                    else
                    {
                        for (int k=size-1 ; k > size_correction -1;k=k-2)
                        {
                             if(arr[k]!=-1 && arr[k-1]!=-1) continue;
                             else if (arr[k]==-1 && arr[k-1]== -1) continue;
                             else return 0;
                    }
                    return 1;
                    }
                }

            }

        return 1;
    }
}


int main()
{
    int N;
    scanf("%d",&N);
    int treeArr[N];
    arrayGet(N,treeArr);
    int check = FullTreeCheck(N,treeArr);
    if (check == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
