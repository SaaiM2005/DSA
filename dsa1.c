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
NODE *getAtNth(int pos)
{
    int value;
    printf("ENTER VALUE TO INSERT:");
    scanf("%d", &value);

    NODE *a = createNode(value);
    if (st == NULL || pos == 0)
    {
        a->next = st;
        st = a;
    }
    else
    {
        NODE *temp = st;
        int i = 0;
        while (temp->next != NULL && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        a->next = temp->next;
        temp->next = a;
    }
    return st;
}
int main() {
    int choice, value, pos;
    while(1) {
        printf("\nMENU:\n");
        printf("1. Add node at the beginning\n");
        printf("2. Add node at the end\n");
        printf("3. Add node at nth position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                st = getAtBegin(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                st = getAtEnd(value);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                st = getAtNth(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}