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

void myfunction(Lnode **head,Lnode **dist,int n)
{
    Lnode *newNode = NULL;
    Lnode *temp = *head;


    for (int j = 0;j<n;j++)
        {
            insertAtHead(&newNode,temp->data);
            temp=temp->next;
        }
        //printf("node\n");
        //printLList(newNode);
    for (int j = 0;j<n;j++)
        {
            insertAtEnd(dist,newNode->data);
            newNode=newNode->next;
        }
       // printf("dist\n");
       // printLList(*dist);
        //printf("dist\n");

        *head = temp;
}



void insertAtEnd(Lnode **head,int Ndata)
{
    Lnode *newNode = (Lnode*) malloc(sizeof(Lnode));
    newNode->data = Ndata;
    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else
    {
        Lnode *temp = *head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next =newNode;

    }
}

void reversing(Lnode **head,int s,int n)
{
    int sample = s/n,remSample=s%n;
    Lnode *temp = NULL;

    Lnode *temp3 = NULL;

    for (int i = 0;i<sample;i++)
    {
        myfunction(head,&temp,n);
        //printf("Fun\n");
       // printLList(temp);
       // printf("Fun\n");
    }
Lnode *temp2 = *head;

    for (int i = 0;i<remSample;i++)
    {
        insertAtEnd(&temp,temp2->data);
        temp2=temp2->next;
    }
*head = temp;
}


void printLList(Lnode *head)
{
    while (head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

int main()
{
        Lnode *head =NULL; //make Empty list
        int S,N,num;
        scanf("%d %d",&S,&N);
        if (N<=0 || N > 10000)
            exit(1);
        if (S<=0 || S > 10000000)
            exit(1);

        for(int i =1; i<=S;i++)
        {
            scanf("%d",&num);
            insertAtEnd(&head,num);
        }

        if (N==1)
        {
            printLList(head);
            exit(0);
        }

        reversing(&head,S,N);

        printLList(head);
    return 0;
}
