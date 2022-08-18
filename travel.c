#include<stdio.h>
#include<stdlib.h>
struct  node
{
    int item;
    struct node *left,*right; 
};
typedef struct node *Node;
struct root
{
    struct node *start;
};
typedef struct root Root;
//pre order   root->left->right
//post order    left->right->root
//in order  left->root->right
void preorder(Node temp)
{
    printf("%d ",temp->item);
    if(temp->left!=NULL) preorder(temp->left);
    if(temp->right!=NULL) preorder(temp->right);
}
void postorder(Node temp)
{
    if(temp->left!=NULL) postorder(temp->left);
    if(temp->right!=NULL) postorder(temp->right);
    printf("%d ",temp->item);
}
void inorder(Node temp)
{
    if(temp->left!=NULL) inorder(temp->left);
    printf("%d ",temp->item);
    if(temp->right!=NULL) inorder(temp->right);
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
    int n;
    Root r;
    r.start=NULL;
    r=insert(r,6);
    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,3);
    r=insert(r,10);
    r=insert(r,1);
    r=insert(r,9);
    r=insert(r,11);
    r=insert(r,7);
    r=insert(r,8);
    r=insert(r,12);
    if(r.start==NULL) printf("Empty set");
    else 
    {
        printf("Preorder traversal gives  :   ");
        preorder(r.start);
        printf("\n");
        printf("Postorder traversal gives :   ");
        postorder(r.start);
        printf("\n");
        printf("Inorder traversal gives   :   ");
        inorder(r.start);
    }
    printf("\n");
    return 0;
}