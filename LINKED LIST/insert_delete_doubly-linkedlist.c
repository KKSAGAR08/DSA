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
node insertfront_dll(node first,int ele)
{
    node temp=createnode();
    temp->left=temp->right=NULL;
    temp->info=ele;
    if(first==NULL)
    {
        return temp;
    }
    first->left=temp;
    temp->right=first;
    return temp;
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
node deletefront_dll(node first)
{
    node cur=first;
    if(first==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    printf("The deleted element is %d\n",cur->info);
    first=cur->right;
    free(cur);
    return first;
}
node deleterear_dll(node first)
{
    node cur=first,prev=NULL;
    if(first==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else if(first->right==NULL)
    {
        printf("The deleted element is %d\n",first->info);
        free(first);
        return NULL;
    }
    else{
    while(cur->right!=NULL)
    {
        prev=cur;
        cur=cur->right;
    }
    printf("The deleted element is %d\n",cur->info);
    free(cur);
    prev->right=NULL;

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
    int choice,ele;
    for(;;)
    {
        printf("Enter 1-insert_front\t2-insert_rear\t3-delete_front\t4-delete_rear\t5-display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the element\n");
               scanf("%d",&ele);
               first=insertfront_dll(first,ele);break;
        case 2:printf("Enter the element\n");
               scanf("%d",&ele);
               first=insertrear_dll(first,ele);break;
        case 3:first=deletefront_dll(first);break;
        case 4:first=deleterear_dll(first);break;
        case 5:display(first);break;
        default:exit(0);
        }
    }
}