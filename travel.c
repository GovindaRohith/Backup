#include<stdio.h>
#include<stdlib.h>
struct  node
{
    int item;
    struct node *left,*right; 
};
typedef struct node * Node;
struct root
{
    struct node *start;
};
typedef struct root Root;
Root insert(Root e,int n)
{
    Node temp=e.start;
    Node new=malloc(sizeof(Node));
    new->item=n;
    new->left=NULL;
    new->right=NULL;
    if(temp==NULL)
    {
        e.start=new;
        return e;
    }
    else
    {
        while(temp!=NULL)
        {
            if(n>temp->item)
            {
                if(temp->right==NULL)
                {
                    temp->right=new; 
                    return e; 
                }
                else temp=temp->right;
            }
            else
            {
                if(temp->left==NULL)
                {
                    temp->left=new;
                    return e; 
                }
                else temp=temp->left;
            }
        }
        return e;
    }
}
int main()
{
    printf("Enter any elements to insert");
    int n;
    while(scanf("%d",&n)!=-1)
    {
        //assa
    }
    return 0;
}