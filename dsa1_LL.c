#include<stdio.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE* st=NULL;
//function to create a node
NODE* createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//function to find the last node
NODE * getLastNode()
{
    NODE *a=st;;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    return a;
}
//display function
void display()
{
    NODE *a=st;
    if(st==NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
        printf("\nDATA:\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
        
    }
}
//add node at the begin
NODE *getAtBegin(int b)
{
    NODE *a=createNode(b);
    if(st==NULL)
    {
        st=a;
    }
    else
    {
        a->next=st;
        st=a;
    }
    return st;
}
//add node at the end
NODE *getAtEnd(int c)
{
    NODE *a = createNode(c);
    if(st == NULL)
    {
        st = a;
    }
    else
    {
        NODE *temp = getLastNode();
        temp->next = a;
    }
    return st;
}
/*ADD AT END
    NODE *addEnd(int d)
    {
        NODE *a,*b;
        a=createNode(d);
        if(st==NULL)
        {
            st=a;
        }
        else
        {
            b=getLastNode();
            b->next=a;
        }
        return;
    }
*/

/*ADD AT BEGIN
    NODE *AddBeg(int d)
    {
        NODE *a;
        a=createNode(d);
        a->next=st;
        st=a;
    }
*/
//NODE *getAtNth(int pos)
//{
//    int value;
//    printf("ENTER VALUE TO INSERT:");
//    scanf("%d", &value);
//
//    NODE *a = createNode(value);
//    if (st == NULL || pos == 0)
//    {
//        a->next = st;
//        st = a;
//    }
//    else
//    {
//        NODE *temp = st;
//        int i = 0;
//        while (temp->next != NULL && i < pos - 1)
//        {
//            temp = temp->next;
//            i++;
//        }
//        a->next = temp->next;
//        temp->next = a;
//    }
//    return st;
//}

//function to count NODES in the list
int count()
{
    int cnt=0;
    NODE *a=st;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}
int main()
{
    int opt,d;
    while(1)
    {
        printf("\nMENU\n1.ADD AT END\n2.ADD AT BEGIN\n3.COUNT\n4.DISPLAY\n5.EXIT\nCHOOSE OPTION:");
        scanf("%d",opt);
        if(opt>=5)
        {
            break;
        }
        switch(opt)
        {
            case 1:
                printf("\nDATA:");
                scanf("%d",&d);
                getAtEnd(d);
                break;
            case 2:
                printf("\nDATA:");
                scanf("%d",&d);
                getAtBegin(d);
                break;
            case 3:
                printf("\nNODE COUNT:\n");
                scanf("%d",count());
                break;
            case 4:
                display();
                break;
        }
    }
}