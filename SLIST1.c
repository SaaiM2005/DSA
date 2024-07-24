#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main()
{
    SLIST p;
    init(&p);
    addEnd(&p,6);
    addEnd(&p,13);
    addEnd(&p,4);
    addEnd(&p,19);
    display(&p);
    if(search(&p,19)==0)
        printf("\n Not Found ");
    else
        printf("\nFound");
}