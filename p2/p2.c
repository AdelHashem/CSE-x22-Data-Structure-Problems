#include <stdio.h>
#include <stdlib.h>
int main()
{
    int saleRange[9]={0};
    int count=0,salary=0,gross=0;
    while (gross!=-1)
    {
        printf("Enter Employee gross sale (-1 to end) ==> ");
        scanf("%d",&gross);
        if (gross ==-1)
            break;

        salary = 200 + (0.09 * gross);
        printf("Employee salary is $%d \n",salary);
        count++;

        if (salary <300)
            saleRange[0]++;
        else if (salary <400)
            saleRange[1]++;
        else if (salary <500)
            saleRange[2]++;
        else if (salary <600)
            saleRange[3]++;
        else if (salary <700)
            saleRange[4]++;
        else if (salary <800)
            saleRange[5]++;
        else if (salary <900)
            saleRange[6]++;
        else if (salary <1000)
            saleRange[7]++;
        else
            saleRange[8]++;
    }
    printf("Total %d Employees Reported\n",count);
    printf("Employees in the range:\n");
    for(int k=0;k<8;k++)
    {
        printf("%d %d: %d\n",k*100+200,k*100+299,saleRange[k]);
    }

    printf("Over 1000: %d",saleRange[8]);

}
