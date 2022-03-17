#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode{
    char data;
    struct Tnode *left,*right;
}tnode;
typedef tnode *Tree;

typedef struct nodemap
{
    Tree val;
    int count;
    struct nodemap *next ,*prev;
}NodeM;
typedef struct{
    NodeM *front,*rear;
    int size;
}Map;

void creatMap(Map *m);
NodeM* Mnodecreate(char val);
void push_map(Map *m,char val);
Tree pop_map(Map *m);
void Mapkill(Map *m);
Tree CreatTNode(char data);
void push_string(char *s,Map *m);
void swap(NodeM *a, NodeM *b);
void bubbleSort(NodeM *start);
void push_tree(Map *m,Tree a,int freq);
void BuildTree(Map *m);
int isLeaf(Tree root);
void decode(Tree root,char *E);

int main()
{
    char S [10000];
    scanf("%[^\n]%*c",S);
    char E [10000];
    scanf("%[^\n]%*c",E);
    Map m;
    creatMap(&m);
    push_string(S,&m);
    bubbleSort(m.front);
    BuildTree(&m);
    decode(pop_map(&m),E);
    return 0;
}
//tree
Tree CreatTNode(char data)
{
    Tree newnode = (Tree) malloc(sizeof(tnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int isLeaf(Tree root) {
  return !(root->left) && !(root->right);}

void decode(Tree root,char *E)
{
    int i =0; Tree temp = root;
    while(i<strlen(E)){
        if(E[i] == '1')
            temp = temp->right;
        else
            temp = temp->left;

        if (isLeaf(temp)){
           printf("%c",temp->data);
           temp = root;
        }
        i++;

    }
}


//map function
void creatMap(Map *m)
{
    m->front=NULL;m->rear = NULL; m->size = 0;
}


NodeM* Mnodecreate(char val)
{
    NodeM *node = (NodeM*) malloc(sizeof(NodeM));
    node->val = CreatTNode(val);
    node->count = 1;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void push_map_char(Map *m,char val)
{


    if(m->size == 0)
    {
        NodeM* nodenew= Mnodecreate(val);
        m->size = 1;
        m->front = nodenew;
        m->rear = nodenew;
    }
    else{
        NodeM *temp = m->front;

        while (temp !=NULL && temp->val->data != val)
            temp = temp->next;
        if(temp != NULL)
        {
            temp->count++;
        }
        else
        {
            NodeM* nodenew= Mnodecreate(val);
            nodenew->prev = m->rear;
            m->rear->next = nodenew;
            m->rear = nodenew;
            m->size ++;
        }
    }
}
Tree pop_map(Map *m)
{
    NodeM *temp = m->front;
    Tree val = m->front->val;
    //*count = m->front->count;
    m->front = m->front->next;
    m->size--;
    free(temp);
    return val;
}
void Mapkill(Map *m)
{
    for(int i = 0 ; i< m->size ;i++)
        pop_map(m);
}

void push_string(char *s,Map *m)
{
    for(int i = 0 ; i < strlen(s) ; i++)
    {
        push_map_char(m,s[i]);
    }
}

void push_tree(Map *m,Tree a,int freq)
{
    NodeM *node = (NodeM*) malloc(sizeof(NodeM));
    node->val = a;
    node->count = freq;
    node->next = NULL;

    if(m->size == 0)
    {
        m->front = node;
        m->rear = node;
        m->size ++;
    }
    else if(m->front->count > freq)
    {
        node->next = m->front;
        m->front = node;
        m->size ++;
    }
    else{
        NodeM *temp = m->front;
        while(temp->next != NULL && freq >= temp->next->count)
            temp=temp->next;
        node->next = temp->next;
        temp->next =node;
        m->size ++;
    }

}

void bubbleSort(NodeM *start)
{
    int swapped, i;
    NodeM *ptr1;
    NodeM  *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->count >= ptr1->next->count)
            {
                if (ptr1->count == ptr1->next->count && ptr1->val->data < ptr1->next->val->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }else if (ptr1->count > ptr1->next->count){

                swap(ptr1, ptr1->next);
                swapped = 1;
            }else if(ptr1->count == ptr1->next->count && ptr1->next->val->data == ' ')
                {
                   swap(ptr1, ptr1->next);
                   swapped = 1;
                }
            }




            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void swap(NodeM *a, NodeM *b)
{
    Tree atree = a->val; int acount = a->count;

    a->count = b->count;a->val = b->val;
    b->count = acount;b->val = atree;
}

void BuildTree(Map *m)
{
    while(m->size > 1)
    {
        Tree nnode = CreatTNode('$');
        int freq = m->front->count;
        nnode->left = pop_map(m);
        freq += m->front->count;
        nnode->right = pop_map(m);
        push_tree(m,nnode,freq);
    }
}
