typedef struct Tqueue{
    Tree data;
    struct Tqueue *next;
}treeQnode;
typedef struct{
    treeQnode *top,*rear;
    int size;
}TreeQ;

void Tq_Intialize(TreeQ *q)
{
    q->size = 0;
    q->rear =NULL;
    q->top = NULL;
}


enQueue(TreeQ *q,Tree data)
{
    if(q->size == 0)
    {

    }
}
