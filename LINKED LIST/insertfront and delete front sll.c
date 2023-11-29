#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *node;
node insertfront(node first,int ele)
{
    node temp=(node)malloc(sizeof(struct node));
    temp->info=ele;
    temp->link=NULL;
    
    if(first==NULL)
    {
        return temp;
    }
    temp->link=first;
    return temp;
}
void display(node first)
{
    printf("The elements of list is\n");
    if(first==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(first!=NULL)
    {
        printf("%d->",first->info);
        first=first->link;
    }
    printf("NULL\n");
}
main()
{
    node first=NULL;
    for(;;)
    {
        printf("Enter 1-insert\t2-display\n");
        int choice,ele;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the element\n");
               scanf("%d",&ele);
               first=insertfront(first,ele);break;
        case 2:display(first);break;
        
        default:exit(0);
        }
    }
}