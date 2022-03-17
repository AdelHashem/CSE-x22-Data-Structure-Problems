#include <stdio.h>
#include <stdlib.h>


typedef struct StackNode {
    int data;
    struct StackNode *next;
}stacknode;

typedef struct {
    stacknode *top;
}stack;

void CreateStack(stack *s);
void push( stack* s,int data);
int isEmpty(stack* s);
int pop (stack* s);
int Bipartite(int color[],int N,stack *s);
void printArray(int arr[],int N)
{
    for(int i =0;i<N;i++)
        printf("%d",arr[i]);
}


int main()
{
    stack s;
    CreateStack(&s);
    int N,E,a,b;
    scanf("%d %d",&N,&E);
    for(int i = 0; i<E ; i++)
    {
        scanf("%d %d",&a,&b);
        push(&s,a);push(&s,b);

    }
    int color[N];
    for (int i=0 ;i< N ; i++)
        color[i] = 0;

    int check = Bipartite(color,N,&s);
    if(check == 1) printf("Yes");
    else
        printf("No");

    //printArray(color,N+1);
    return 0;
}

//stack fun
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

//problem func

int Bipartite(int color[],int N,stack *s)
{
        stack v;
    CreateStack(&v);

        int ind = 0;

            while(!isEmpty(s)){
                int t = pop(s);
                int t2 = pop(s);
                if (color[t2-1] == 0 && color[t-1] == 0&& ind ==0) //vertix
                {
                    ind++;
                    color[t2-1] = 1;
                    color[t-1] = -color[t2-1];
                }
                else if(color[t2-1] == 0 && color[t-1] == 0)
                {
                    push(&v,t2); push(&v,t);
                }
                else
                {
                    if(color[t2-1] == color[t-1]) return 0;
                    if(color[t-1] == 0) color[t-1] = - color[t2-1];
                    if(color[t2-1] == 0) color[t2-1] = - color[t-1];
                }
            }
            if(!isEmpty(&v))
            {
                int k = Bipartite(color,N,&v);
                if(k ==0) return 0;
            }
            for(int i = 0;i<N ; i++)
                if(color[i] == 0) return 0;

            return 1;
}
