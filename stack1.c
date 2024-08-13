//ARRAY IMPLEMENTATION OF STACK:-

#define N 5
#include<stdio.h>
#include<conio.h>
typedef struct stack
{
    int top;
    int arr[N];
}STK;
void init(STK *t)
{
    t->top=-1;
}
int isFull(STK *t)
{
    return (t->top==N-1);
}
int isEmpty(STK *t)
{
    return(t->top==-1);
}
void push(STK *t,int d)
{
    if(isFull(t))
    {
        printf("\nOVERFLOW");
    }    
    else
    {
        t->top++;
        t->arr[t->top]=d;
    }
}
void pop(STK *t)
{
    if(isEmpty(t))
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        t->top--;
    }
}
void display(STK *t)
{
    int i=t->top;
    if(isEmpty(t))
    {
        printf("EMPTY STACK");
    }
    else
    {
        printf("\nDATA:");
        while(i>=0)
        {
            printf("%4d",t->arr[i]);
            i--;
        }
    }
}
int main()
{
    STK p;
    int opt,d;
    init(&p);
    while(1)
    {
        printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nOption:");
        scanf("%d",&opt);
        if(opt>3)
        {
            break;
        }
        switch(opt)
        {
            case 3:
                display(&p);
                break;
            case 2:
                pop(&p);
                break;
            case 1:
                printf("\nDATA:");
                scanf("%d",&d);
                push(&p,d);
        }
    }
}


