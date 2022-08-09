#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *left,*right;
};
typedef struct node *Node;
struct root
{
    Node start;
};
typedef struct root *Root;
Root insert(Root e,int n)
{
    Node temp=e->start;
    int side=0;
    Node new=malloc(sizeof(Node));
    new->item=n;
    new->left=NULL;
    new->right=NULL;
    while ()
    {
        if(temp->item>n)
        {
            side=-1;
            temp=temp->right;
        }
        else
        {
            side=1;
            temp=temp->left;
        }
        if(temp->right==temp->left&&temp->right==NULL)
        {
            if(n>temp->item)
            {
                temp->right=new;
            }
            break;
        }
    }
    return e;
}
int main()
{
    int n;
    Root r;
    r->start=NULL;
    printf("Enter any number to insert\n");
    while(scanf("%d",&n)!=-1)
    {
        r=insert(r,n);
        printf("Enter any number to insert\n");
    }
    return 0;
}