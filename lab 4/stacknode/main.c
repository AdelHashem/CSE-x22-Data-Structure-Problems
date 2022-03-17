#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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



//My Function
int isnum(char a)
{
    if (a>= 48 && a<=57)
        return 1;
    else
        return 0;
}
int valition2(char s)
{
    if (s>= 48 && s<=57)
        return 1;
    else if (s==42 || s==43 || s==37 || s==45 || s==47)
        return 1;
    else
        return 0;
}

int prefixcalc(char*s)
{
    stack Stack;
    CreateStack(&Stack);

    int num1,num2,res;

    for (int i = 0; i<strlen(s);i++)
    {
        if (!valition2(s[i]))
        {
            printf("Not Valid");
            exit(0);
        }
        if (isnum(s[i]))
        {
            push(&Stack,s[i]-48);
        }
        else
        {
            if (isEmpty(&Stack))
            {
                printf("Not Valid");
                exit(0);
            }
            num1 = pop(&Stack);
            if (isEmpty(&Stack))
            {
                printf("Not Valid");
                exit(0);
            }
            num2 = pop(&Stack);
            switch (s[i])
            {
            case '+':
                push(&Stack,num2 + num1);
                break;
            case '-':
                push(&Stack,num2 - num1);
                break;
            case '*':
                push(&Stack,num2 * num1);
                break;
            case '/':
                if(num1==0)
                {
                    printf("Not Valid");
                    exit(0);
                }
                push(&Stack,num2 / num1);
                break;
            case '%':
                if(num1==0)
                {
                    printf("Not Valid");
                    exit(0);
                }
                push(&Stack,num2 % num1);
                break;
            }
        }
    }

res = pop(&Stack);
if (isEmpty(&Stack))
{
    //free(Stack);
return res;
}
else{
    printf("Not Valid");
    exit(0);
}

}



int main()
{
    char S [100000];
    scanf("%s",S);
    printf("%d",prefixcalc(S));

    return 0;
}
