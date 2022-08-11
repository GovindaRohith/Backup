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
                if(temp->right==NULL) return 0;
                else temp=temp->right;
            }
            else if(n==temp->item) return 1;
            else
            {
                if(temp->left==NULL) return 0;
                else temp=temp->left;
            }
        }
        return 0;
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
Root deleter(Node req,Root e,Node prev,int dir)
{
    //1 for right
    //-1 for left
    if(req->left==NULL&&req->right!=NULL)
    {
        if(dir==1) prev->right=req->right;
        else prev->left=req->right;
        free(req);
    }
    else if(req->right==NULL&&req->left!=NULL)
    {
        if(dir==1) prev->right=req->left;
        else prev->left=req->left;
    }
    else if(req->right==NULL&&req->right==NULL)
    {
        if(dir==1) prev->right=NULL;
        else prev->left=NULL;
        free(req);
    }
    else
    {
        req->item=req->right->item;
        return deleter(req->right,e,req,1);
    }
    return e;
}
Root delete(Root e,int n)
{
    Node prev;
    int dir=0;
    Node temp=e.start;
    if(temp==NULL) return e;
    while (temp!=NULL)
    {
        if(n>temp->item)
        {
            if(temp->right==NULL) return e;
            else
            {
                prev=temp;
                temp=temp->right;
            } 
            dir=1;
        }
        else if(n==temp->item)
        {
            return deleter(temp,e,prev,dir);
        }
        else
        {
            if(temp->left==NULL) return e;
            else 
            {
                prev=temp;
                temp=temp->left;
            }
            dir=-1;
        }
    }
    return e;
}
int main()
{
    int n=0;
    Root r;
    r.start=NULL;
    r=insert(r,5);
    r=insert(r,4);
    r=insert(r,3);
    r=insert(r,2);
    r=insert(r,1);
    r=insert(r,6);
    r=insert(r,7);
    r=insert(r,8);
    r=insert(r,9);
    printer(r.start);
    printf("\n");
    return 0;
}