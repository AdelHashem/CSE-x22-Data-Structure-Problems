#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Building Binary Tree

typedef struct tnode{
    char data;
    int precedence;
    struct tnode *left, *right, *parent;
}Tnode;

typedef Tnode * Tree;

void CreateTree(Tree *t)
{
    *t = NULL;
}

int IsEmpty(Tree *t)
{
    return (!*t);
}

Tree creatTnode(char s)
{
    Tree newNode = (Tnode*)malloc(sizeof(Tnode));
    newNode->data = s;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}
// End Tree

//Start algorithm Func

int GetPre(char s)
{
    if (s == '*' || s =='/' || s =='%')
        return 2;
    else
        return 1;
}

int isnum(char a)
{
    if (a>= 48 && a<=57)
        return 1;
    else
        return 0;
}


int IsOperator(char s)
{
    if (s==42 || s==43 || s==37 || s==45 || s==47)
        return 1;
    else
        return 0;
}

int isABC(char a)
{
    if ((a>= 'A' && a<='Z') || isnum(a))
        return 1;
    else
        return 0;
}

int ISLparentheses(char s)
{
    return s=='(';
}

int ISRparentheses(char s)
{
    return s==')';
}

Tree prefixInsert(char *s) //Building Tree From Expression
{
    Tree root = creatTnode('0'); //temp Root TO Build ON
    root->precedence = -99;

    //initialize pointers to (pre Operator and pre Num)
    Tree preNum =NULL;
    Tree preOperator = root;

    int pareCorrection = 0;

    for (int i = 0;i<strlen(s);i++)
    {
        if (isABC(s[i])) // isnum
        {
            preNum=creatTnode(s[i]);
        }
        else if (IsOperator(s[i]))
        {
            Tree pn = creatTnode(s[i]);
            pn->precedence = GetPre(s[i]) + pareCorrection;

            if (pn->precedence > preOperator->precedence)
            {
                pn->left = preNum ;
                preOperator->right = pn;
                pn->parent = preOperator;
            }
            else
            {
                preOperator->right = preNum;
                Tree temp = preOperator->parent;

                while (pn->precedence <= temp->precedence)
                    temp = temp->parent;

                pn->left = temp->right;
                temp->right = pn;
                pn->parent = temp;
            }
            preNum = NULL;
            preOperator = pn;
        }
        else if (ISLparentheses(s[i]))
            pareCorrection +=2;
        else if (ISRparentheses(s[i]))
            pareCorrection-=2;


    }
    preOperator->right = preNum;

    root = root->right;
    return root;

}

void treeprintPOSTfix(Tree t)
{
    if(t)
    {
        treeprintPOSTfix(t->left);
        treeprintPOSTfix(t->right);
        printf("%c",t->data);
    }


}

void treeprintprefix(Tree t)
{
    if(t)
    {
        printf("%c",t->data);
        treeprintprefix(t->left);
        treeprintprefix(t->right);

    }


}




int main()
{
    while(1)
    {
        char S [100000];
    scanf("%s",S);
    Tree T = prefixInsert(S);
    treeprintPOSTfix(T);
    printf("\n");
    treeprintprefix(T);
    printf("\n");
    }
    char S [100000];
    scanf("%s",S);
    Tree T = prefixInsert(S);
    treeprintPOSTfix(T);
    printf("\n");
    treeprintprefix(T);
    printf("\n");

    return 0;
}
