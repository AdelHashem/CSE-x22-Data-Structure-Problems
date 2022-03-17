#include <stdio.h>
#include <stdlib.h>

//Stack Build
typedef struct StackNode {
    int data;
    struct StackNode *next;
}stacknode;

typedef struct {
    stacknode *top;
}stack;

void CreateStack(stack *s)
{
    s->top = NULL;
}

void push( stack* s,int data)
{
    stacknode *Nnode = (stacknode*) malloc(sizeof(stacknode)) ;
    Nnode ->data = data;
    Nnode ->next = s ->top;
    s ->top = Nnode;
}
int isEmpty(stack* s)
{
    if (s->top == NULL)
        return 1;
    else
        return 0;
}
int pop (stack* s)
{
    int temp;
    temp = s->top->data;
    stacknode *Tnode = s->top;
    s->top =s->top->next;
    free(Tnode);
    return temp;
}

void PrintStack (stack* s,int N)
{
    int temp;
    while (!isEmpty(s))
    {
        temp = pop(s);
        if (temp < 10)
            printf ("%d",temp);
        else if (temp >9 && temp <N)
            printf("%c",temp - 9 + 64);
        else
            exit(1);
    }
}



//End stack build


//Problem Function

void Base10ToN(int num,int N ,stack* s)
{
    if (num == 0)
        PrintStack(s,N);
    else
    {
        push(s,num % N);
        Base10ToN(num / N,N,s);

    }

}





int main()
{
    int x,N;
    scanf("%d %d",&x,&N);
    if (x<1)
        exit(1);
    stack s;
    CreateStack(&s);
    Base10ToN(x,N,&s);
    return 0;
}
