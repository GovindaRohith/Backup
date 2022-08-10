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
typedef struct root Root;
void printer(Node temp)
{
    printf("%d,",temp->item);
    if(temp->left!=NULL)
    {
        printer(temp->left);
    }
    if(temp->right!=NULL)
    {
        printer(temp->right);
    }
}
int search (Root e,int n)
{
    Node temp=e.start;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        while (temp!=NULL)
        {
            if(n>temp->item)
            {
                if(temp->right==NULL)
                {
                    return 0;
                }
                else temp=temp->right;
            }
            else if(n==temp->item) return 1;
            else
            {
                if(temp->left==NULL)
                {
                    return 0;
                }
                else temp=temp->left;
            }
        }
        
    }
}
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
    int n=0;
    Root r;
    r.start=NULL;
    printf("Enter any number to insert\n");
    while(scanf("%d",&n)!=-1)
    {
        r=insert(r,n);
        printer(r.start);
        printf("\nEnter any number to insert :");
    }
    return 0;
}