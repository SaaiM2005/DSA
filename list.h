#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct slist
{
    NODE * st; //head pointer
    int cnt; //No of nodes from the slist
}SLIST;

//To  create Node
NODE * createNode(int d)
{
    NODE * a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

//function to initialize 
void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}

//add new Node at End 
void addEnd(SLIST *t,int d)
{
    NODE *a,*b;
    if(t->st==NULL)
    {
        t->st=a=createNode(d);
    }
    else
    {
        b=t->st; //here b is a traversal pointer
        while(b->next!=NULL)
            b=b->next;
        a=createNode(d);
        b->next=a;
    }
    t->cnt=t->cnt+1;
}

//Function to add new node at begin
void addBeg(SLIST *t,int d)
{
    NODE *a;
    a=createNode(d);
    a->next=t->st;
    t->st=a;
    t->cnt=t->cnt+1;
}

//Function to display
void display(SLIST *t)
{
    NODE *a=t->st; //these is the pointer for traversal 
    if(t->st==NULL)
        printf("\nEmpty List");
    else
    {
        printf("\n Data:S");
        while (a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}

// function to compute data sum
int sum(SLIST *t)
{
    NODE *a=t->st;
    int tot=0;
    while(a!=NULL)
    {
        tot=tot+a->data;
        a=a->next;
    }
    return tot;
}

//function to find out maximum data from the list 
int maxValue(SLIST *t)
{
    NODE *a=t->st;
    int max;
    while(a!=NULL)
    {
        if(a==t->st)
            max=a->data;
        else
        {
            if(a->data > max)
                max=a->data;
        }
        a=a->next;
    }
    return max;
}

//function to  find the minimum data from the lsit
int minValue(SLIST *t)
{
    NODE *a=t->st;
    int min;
    while(a!=NULL)
    {
        if(a==t->st)
            min=a->data;
        else
        {
            if(a->data < min)
                min=a->data;
        }
        a=a->next;
    }
    return min;
}

//Function to count odd data in the list
int oddCount(SLIST *t)
{
    NODE *a=t->st; //these is a traversal node
    int ocnt=0;
    while(a!=NULL)
    {
        if(a->data%2==1)
            ocnt++;
        a=a->next;
    }
    return ocnt;

}

//Function to count even data in the list
int evenCount(SLIST *t)
{
    NODE *a=t->st; //these is a traversal node
    int ecnt=0;
    while(a!=NULL)
    {
        if(a->data%2==0)
            ecnt++;
        a=a->next;
    }
    return ecnt;

}

//function to display odd data from the list 
int odisplay(SLIST *t)
{   
    NODE *a=t->st;
    if(t->st==NULL)
        printf("Empty List");
    else
    {
        while(a!=NULL)
        {
            if(a->data%2==1)
                printf("%4d",a->data);
            a=a->next;
        }
    }
}

//Function to display even data
int edisplay(SLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        printf("Empty List");
    else
    {
        while(a!=NULL)
        {
            if(a->data%2==0)
                printf("%4d",a->data);
            a=a->next;
        }
        
    }
}

//function to search data from the list
int search(SLIST *t,int sv)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(a->data==sv)
            break;
        a=a->next;
    }
    if(a==NULL)
        return 0; //Value not Found
    else
        return 1;
         //Value Found
}

//function to find search value and replace 
int findRep(SLIST *t,int sv,int rep)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(a->data==sv)
            a->data=rep;
        a=a->next;
    }
}

//function to delete last node from the List
void delFirst(SLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        printf("Empty List");
    else
    {
        t->st=a->next;
        t->cnt=t->cnt-1;
        free(a);
    }
}

//function to delete last node from the list
void delLast(SLIST *t)
{
    NODE *a=t->st,*b;
    if(t->st==NULL)
        printf("\nEmpty List");
    if(t->cnt==1)
        t->st=NULL;
    else
    {
        while(a->next!=NULL)
        {
            b=a;
            a=a->next;
        }
        b->next=NULL;
        free(a);
    }
    t->cnt=t->cnt-1;
    //free(a);
}

//function to delete all nodes from list
//Here are 2 code the second one is more efficient 

// void delAll(SLIST *t)
// {
//     while(t->st!=NULL)
//         delfirst(t);
// }

//These is most efficient code  
//function to delete all nodes from list
void delAll(SLIST *t)
{
    NODE *a=t->st;
    while(t->st!=NULL)
    {   
        t->st=a->next;
        free(a);
        a=t->st;
    }
    t->cnt=0;
}
//function to delete ith node 
void deliNode(SLIST *t,int pos)
{
    int i=1;
    NODE *a=t->st,*b,*c;
    if(t->st==NULL)
        return;
    if(pos<1 || pos>t->cnt)
        printf("Invalid node position");
    else
    {
        if(pos==1)
            delFirst(t);
        else
        {
            if(pos==t->cnt)
                delLast(t);
            else
            {
                while(i<pos)
                {
                    b=a;
                    a=a->next;
                    i++;
                }
                c=a->next;
                b->next=c;
                free(a);
                t->cnt=t->cnt-1;
            }
        }
    }
}

//function to reverse the list
void reverse(SLIST *t)
{
    NODE *a=t->st,*b,*c=NULL;
    while(a!=NULL)
    {
        b=a->next;
        a->next=c;
        c=a;
        a=b;
    }
    t->st=c;
}

//function to display the list in reverse order
//recurssive function 
void rdisplay(NODE *a)
{
    if (a==NULL)
        return;
    rdisplay(a->next);
    printf("%4d",a->data);
}

//function to convert list into an array
int * toArray(SLIST *t)
{
    int *q;NODE *a=t->st;
    int i=0,n=t->cnt;
    q=(int *)malloc(n*sizeof(int));
    while(a!=NULL)
    {
        q[i]=a->data;
        i++;
        a=a->next;
    }
    return q;
}

//function to convert array to list
void toList(SLIST *t,int *q,int n)
{
    int i=0,d;
    NODE *a,*b;
    delAll(t);
    while(i<n)
    {
        a=createNode(q[i]);
        if(t->st==NULL)
            t->st=a;
        else
            b->next=a;
        b=a;
        i++;
    }
    t->cnt=n;
}

//function to sort the list 
void sort(SLIST *t)
{
    NODE *a=t->st,*b,*c;
    int tmp;
    if(t->st==NULL) //list is empty 
        return;
    if(a->next==NULL)  //list having only one node  
        return;
    while(a->next!=NULL)
    {
        c=a;
        for(b=a->next;b!=NULL;b=b->next)
        {
            if(b->data < c->data)
                c=b;
        }
        if(a!=c)
        {
            tmp=a->data;
            a->data=c->data;
            c->data=tmp;
        }
        a=a->next;
    }    
}

//function to check list is in ascending order
int isOrdered(SLIST *t)
{
    NODE *a,*b;
    if(t->st==NULL)
        return 0;
    a=t->st;
    for(b=a->next;b!=NULL;b=b->next)
    {
        if(b->data < a->data)
            break;
        a=b;
    }
    if(b==NULL)
        return 1;  //Data is Ascending order
    else    
        return 0;  //Data is not in ascending order
}

//Function to write list data in file
void toFile(SLIST *t)
{
    NODE *a;
    int d;
    FILE *f1;
    if(t->st==NULL)
        return;
    a=t->st;
    f1=fopen("List.dat","wb"); //write binary
    while(a!=NULL)
    {
        d=a->data;
        fwrite(&d,sizeof(int),1,f1);
        a=a->next;
    }
    fclose(f1);
    return;
}

//function to built list from file
void fromFile(SLIST *t)
{
    NODE *a;
    int d;
    FILE *f1;
    f1=fopen("List.dat","rb"); //read binary
    if(f1==NULL)
        return;
    delAll(t);
    while(1)
    {
        fread(&d,sizeof(int),1,f1);
        if(feof(f1))
            break;
        addEnd(t,d);
    }
    fclose(f1);
        return;
}