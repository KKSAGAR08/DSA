#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct  node *left;
    struct node *right;
};
typedef struct node *node;
node createnode()
{
    node ptr=(node)malloc(sizeof(struct node));
    return ptr;
}
node insertrear_dll(node first,int ele)
{
    node temp=createnode();
    temp->left=temp->right=NULL;
    temp->info=ele;
    if(first==NULL)
    {
        return temp;
    }
    else if(first->right==NULL)
    {
        first->right=temp;
        temp->left=first;
        return first;
    }
    else 
    {
        node cur=first;
        while (cur->right!=NULL)
        {
            cur=cur->right;
        }
        cur->right=temp;
        temp->left=cur;
        return first;
    }   
}
node concatenate(node first,node second)
{
    if(first==NULL)
    {
        printf("Concatenation successful\n");
        return second;
    }
    else if(second==NULL)
    {
        printf("Concatenation successful\n");
        return first;
    }
    else
    {
        node cur=first;
        while(cur->right!=NULL)
        {
            cur=cur->right;
        }
        cur->right=second;
        second->left=cur;
        printf("Concatenation successful\n");
        return first;
    }
}
void display(node first)
{
    if(first==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(first!=NULL)
    {
        printf("%d->",first->info);
        first=first->right;
    }
    printf("NULL\n");
}
main()
{
    node first=NULL;
    node second=NULL;
    node third=NULL;
    int choice,ele;
    for(;;)
    {
        printf("Enter 1-insert first node\t2-insert second node\t3-display first node\t4-display second node\n5-concatenate two node\t6-display concatenated node\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the element\n");
               scanf("%d",&ele);
               first=insertrear_dll(first,ele);break;
        case 2:printf("Enter the element\n");
               scanf("%d",&ele);
               second=insertrear_dll(second,ele);break;
        case 3:display(first);break;
        case 4:display(second);break;
        case 5:third=concatenate(first,second);break;
        case 6:display(third);break;
        default:exit(0);
        }
    }
}