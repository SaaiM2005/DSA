//IMPLEMENTATION OF SINGLE LINKED LIST
/*
DEFINE A HEADER FILE list.h


SLIST
st  | cnt
100 |  4

NODE
data |  next
28   |  200
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct slist
{
    NODE *st;//head node pointer
    int cnt;//NUMBER OF NODES FROM SLIST
}SLIST;

//FUNCTION TO CREATE NODE
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//function to initalize SLIST
void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}

//add new NODE at END
void addEnd(SLIST *t,int d)   //t REFERS TO THE SLIST DATA PART
{
    NODE *a,*b;
    if(t->st==NULL)
    {
        t->st=a=createNode(d);
    }
    else
    {
        b=t->st;
        while(b->next!=NULL)
        {
            b=b->next;
        }
        a=createNode(d);
        b->next=a;
    }
    t->cnt=t->cnt+1;
}
//add new NODE at BEGIN
void addBeg(SLIST *t,int d)
{
    NODE *a;
    a=createNode(d);
    a->next=t->st;
    t->st=a;
    t->cnt=t->cnt+1;
}
//FUNCTION TO DISPLAY LIST DATA
void display(SLIST *t)
{
    NODE *a=t->st;
    if(t->st!=NULL)
    {
        printf("EMPTY LIST.\n");
    }
    else
    {
        printf("\nDATA:");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}