#include <stdio.h>
#include <stdlib.h>
// Struct for the Node
typedef struct lruNode{
    int data;
    int key;
    struct lruNode *next,*prev;
}NLRU;

typedef struct {
    NLRU *head;
    NLRU *tail;
    int cap;
    int size;
}LRU;

//Fun for linked list
void deleteNode(LRU *,NLRU *);
void insertNode(LRU *,int,int);
//LRU FUN
LRU* CreatLUR(int);
int get(LRU*,int);
void set(LRU*,int,int);

int main()
{
    int P,C,J,K,V;
    scanf("%d %d",&P,&C);
    LRU *L = CreatLUR(C);
    for(int i = 0; i<P;i++)
    {
        scanf("%d",&J);
        if(J == 1)
        {
            scanf("%d %d",&K,&V);
            set(L,K,V);
        }else if(J==2)
        {
            scanf("%d",&K);
            int val = get(L,K);
            if(val == -1)
                printf("Not Found\n");
            else
                printf("%d\n",val);
        }
    }

    return 0;
}

//some linked list FUNC
void deleteNode(LRU *L,NLRU *node)
{
    if(L->size == 0 || L->cap ==0)
    {
        printf("Error\n");
        L->size = 0;L->head=NULL;L->tail = NULL;

        return;
    }

    if(L->size == 1)
    {
        L->head = NULL; L->tail = NULL;
        free(node);
        L->size --;
        return;
    }
    if(node->next == NULL)
    {
       L->tail = node->prev;
       node->prev->next = NULL;
       free(node);
       L->size --;
       return;
    }
    if(node->prev == NULL)
    {
        L->head = node->next;
        free(node);
        L->size --;
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    L->size --;
    free(node);
}
void insertNode(LRU *L,int key,int value)
{
    if(L->cap == 0)
    {
        printf("Error\n");
        return;
    }
    NLRU *n = (NLRU*) malloc(sizeof(NLRU));
    n->data = value;
    n->key = key;
    if(L->size == 0)
    {
        L->head = n; L->tail = n; L->size ++;
        n->next = NULL;
        n->prev = NULL;
        return;
    }
    n->next = L->head;
    L->head->prev = n;
    n->prev = NULL;
    L->head = n;
    L->size ++;
    if(L->size > L->cap)
    {
        deleteNode(L,L->tail);
    }
}

//Inti The LUR
LRU* CreatLUR(int cap)
{
    LRU *p =(LRU*) malloc(sizeof(LRU));
    p->cap = cap;
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    return p;
}
// GET Value
int get(LRU* L,int key)
{
    NLRU *temp = L->head;
    while(temp !=NULL && temp->key != key)
        temp = temp->next;
    if(!temp)
        return -1; //Error (404)
    else // cash hit
    {
        int val = temp->data;
        deleteNode(L,temp);
        insertNode(L,key,val); // return to Recently used
        return val;
    }
}

// Set value
void set(LRU* L,int key,int val)
{
    NLRU *temp = L->head;
    while(temp && temp->key != key)
        temp = temp->next;
    if(!temp)
        insertNode(L,key,val); // not found --> insert direct
    else{                      //found ----> delete---> insert
        deleteNode(L,temp);
        insertNode(L,key,val);
    }

}
