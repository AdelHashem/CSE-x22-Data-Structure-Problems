#include <stdio.h>
#include <stdlib.h>

//stack structure in array form method
struct stack {
    int top;
    unsigned elements;
    unsigned size;
    int *arr_stack;
};
typedef struct stack stack;

stack* CreatStack(int num)
{
    stack *stackk = (stack*) malloc(num*sizeof(stack));
    stackk->top = -1;
    stackk->size = num;
    stackk->elements = 0;
    stackk->arr_stack = (int*)malloc(num * sizeof(int));
    return stackk;
}
int isEmpty(stack* stakk)
{
    return stakk->elements == 0;
}


void push(stack* stackk,int num)
{
    stackk->elements ++;
    stackk->top ++;
    stackk->arr_stack[stackk->top] = num;
}

int pop(stack* stackk)
{
    int temp = stackk->arr_stack[stackk->top];
    stackk->top --;
    stackk->elements --;
    return temp;
}

//Get Min num of the stack with elements knowlage
int stackMin(stack* stackk)
{
    if (isEmpty(stackk))
        return 0;
    int min = stackk->arr_stack[0];
    for (int i =0 ; i<stackk->elements;i++)
    {
        if (stackk->arr_stack[i]<min)
        {
            min = stackk->arr_stack[i];
        }
    }
    return min;
}




int main()
{
    // initial input
    int Q , E,input,popn,min;
    scanf("%d",&Q);
    if (Q<0 || Q> 10000000)
        exit(1);
    stack *stackk= CreatStack(Q); //use Q to build The stack

    for(int i = 1;i <=Q;i++)
    {
        scanf("%d",&input);
        if ((input>0) && (input<4))
        {
            switch (input)
            {
            case 1: // push to stack
                scanf("%d",&E);
                if (E>1000000000)
                    exit(1);
                push(stackk,E);
                break;
            case 2://delete form the stack
                if (isEmpty(stackk))
                    printf("Empty\n");
                else
                    popn=pop(stackk);
                break;
            case 3://Get Min
                min = stackMin(stackk);
                if (min ==0)
                    printf("Empty\n");
                else
                    printf("%d\n",min);
                break;
            }
        }
        else
            exit(1);
    }




    return 0;
}
