#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//stack structure in linked list form method
struct StackN {
    int data;
    struct StackN* next;
};

typedef struct StackN StackN;

StackN* CreatStackNode(int data)
{
   StackN* stackNode =(StackN*) malloc(sizeof(StackN));
   stackNode->data = data;
   stackNode->next = NULL;

    return stackNode;
}


void push(StackN **stack,int num)
{
    StackN *newnode = CreatStackNode(num);
    newnode->next = *stack;
    *stack = newnode;
}

int pop(StackN **stack)
{
    StackN *temp = *stack;
    *stack = (*stack)->next;
    int num = temp->data;
    free(temp);
    return num;
}

int isEmpty(StackN* stack)
{
    return !stack;
}




//End of stack coding


//my functions
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
    StackN *stack = NULL;

    int num1,num2,res;

    for (int i = 0; i<strlen(s);i++)
    {
        if (!valition2(s[i]))
        {
            printf("Not Valid");
            exit(1);
        }
        if (isnum(s[i]))
        {
            push(&stack,s[i]-48);
        }
        else
        {
            if (isEmpty(stack))
            {
                printf("Not Valid");
                exit(1);
            }
            num1 = pop(&stack);
            if (isEmpty(stack))
            {
                printf("Not Valid");
                exit(1);
            }
            num2 = pop(&stack);
            switch (s[i])
            {
            case '+':
                push(&stack,num2 + num1);
                break;
            case '-':
                push(&stack,num2 - num1);
                break;
            case '*':
                push(&stack,num2 * num1);
                break;
            case '/':
                if(num1==0)
                {
                    printf("Not Valid");
                    exit(1);
                }
                push(&stack,num2 / num1);
                break;
            case '%':
                if(num1==0)
                {
                    printf("Not Valid");
                    exit(1);
                }
                push(&stack,num2 % num1);
                break;
            }
        }
    }
res = pop(&stack);
if (isEmpty(stack))
{
    free(stack);
return res;
}
else{
    printf("Not Valid");
    exit(1);
}

}

int valition(char *s)
{
    for (int i = 0; i<strlen(s);i++)
    {
        if (s[i]>= 48 && s[i]<=57)
            continue;
        else if (s[i]==42 || s[i]==43 || s[i]==37 || s[i]==45 || s[i]==47)
            continue;
        else
            return 0;
    }
    return 1;
}



int main()
{
    char S [100000];
    scanf("%s",S);
    printf("%d",prefixcalc(S));

    return 0;
}
