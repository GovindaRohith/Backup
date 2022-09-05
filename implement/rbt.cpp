#include<iostream>
#include<iostream>
using namespace std;
class Node 
{
    public :
    int item;
    bool isblack=true;
    Node *left,*right,*parent;
};
class Root
{
    public :
    Node *start;
};
void printer(Node *temp)
{
    if(temp->left!=NULL) printer(temp->left);
    cout<<" "<<temp->item<<endl;
    if(temp->right!=NULL) printer(temp->right);
}
void free_mem(Node *temp)
{
    if(temp->left!=NULL) free_mem(temp->left);
    if(temp->right!=NULL) free_mem(temp->right);
    free(temp);
}
Root right(Root r,Node *parent,Node *a)
{
    Node *b=a->left;
    a->left=b->right;
    b->right=a;
    if(parent!=NULL)
    {
        if(parent->left==a)  parent->left=b;
        else parent->right=b;
    }
    return r;
}
Root left(Root r,Node *parent,Node *x)
{
    Node *y=x->right;
    x->right=y->left;
    y->left=x;
    if(parent!=NULL)
    {
        if(parent->left==x)  parent->left=y;
        else parent->right=y;
    }
    return r;
}
Root color(Root e,Node *temp)
{
    Node *parent=temp->parent,*uncle,*gp=temp->parent->parent;
    temp->isblack=false;
    if(temp==e.start)
    {
        temp->isblack=true;
        return e;
    }
    while(temp!=e.start&&temp->parent->isblack == false)
    {
    if(gp->left==parent)
    {
        uncle=gp->right;
        if(uncle->isblack)
        {
            if(parent->right==temp)
            {
                e=left(e,gp->parent->parent,gp->parent);
                temp=gp->parent;
            }
            else    
            {
                e=right(e,gp->parent->parent,gp->parent);
                temp=gp->parent;
            }
        }
        else
        {
            gp->isblack=false;
            parent->isblack=true;
            uncle->isblack=true;
            return e;
        }
    }
    else
    {
        uncle=gp->left;
        if(uncle->isblack)
        {
            if(parent->right==temp)
            {

            }
            else
            {
                
            }
        }
        else
        {

            return e;
        }
    }
    parent=temp->parent;
    gp=parent->parent;
    }
    
    return e;
}
Root insert(Root e,int a)
{
    Node *temp=e.start;
    Node *entry=new Node();
    entry->left=NULL;
    entry->right=NULL;
    entry->item=a;
    if(temp==NULL)
    {
        e.start=entry;
        entry->isblack=true;
        entry->parent=NULL;
        return e;
    }
    while(temp!=NULL)
    {
        if(a>temp->item)
        {
            if(temp->right==NULL)
            {
                entry->parent=temp;
                temp->right=entry; 
                e=color(e,entry);
                return e; 
            }
            else temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                entry->parent=temp;
                temp->right=entry; 
                e=color(e,entry);
                return e; 
            }
            else temp=temp->left;
        }
    }
    return e;
}
int main()
{
    Root r;
    r.start=NULL;
    return 0;
}