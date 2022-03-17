#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct linkedlist {
    int data;
    struct linkedlist *next;

};
typedef struct linkedlist Lnode;


void insertAtHead(Lnode **head,int Ndata)
{
    Lnode *newNode = (Lnode*) malloc(sizeof(Lnode));
    newNode->data = Ndata;
    newNode->next = *head;
    *head = newNode;
}


int collectList_R(Lnode *head)
{
    int i = 1 , sum=0;
    while (head != NULL)
    {
        sum=sum + (head->data * i);
        head = head->next;
        i=10*i;
    }
    return sum;
}


int main()
{
    Lnode *head =NULL; //make Empty list

    // take the input 'X'
    int X;
    scanf("%d",&X);
    //printf("%d",INT_MAX);
    if (X>=INT_MAX || X<= INT_MIN)
    {
        printf("Not valid");
        exit(EXIT_FAILURE);;
    }

    if(X<0)
        X=-X;

    //put the i/p in linked list
    int c = X;


    while (c>=0)
    {
        if (c==0)
            break;
        insertAtHead(&head,c%10);
        c=c/10;
    }

    //Revers the input in linked list using just sumision
    c=collectList_R(head);

    if (c==X)
        printf("YES");
    else
        printf("NO");


    return 0;
}
