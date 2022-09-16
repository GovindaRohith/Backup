// 1.  Each node contains the Age of a faculty.
// 
// 2.  You should implement
// A.Insert
// B.Search
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
    if(temp->isblack) cout<<temp->item<<"->"<<"Black color ";
    else cout<<temp->item<<"->"<<"Red color ";
    if(temp->right!=NULL) printer(temp->right);
}
void free_mem(Node *temp)
{
    if(temp->left!=NULL) free_mem(temp->left);
    if(temp->right!=NULL) free_mem(temp->right);
    delete temp;
}
Root right(Root r,Node *parent,Node *a)
{
    //given parent and top node A
    //    A             B
    //  B   C   ->   D      A
    //D  E                E   C
    Node *b=a->left;
    a->left=b->right;
    b->right=a;
    if(parent!=NULL)
    {
        if(parent->left==a)  parent->left=b;
        else parent->right=b;
    }
    else r.start=b;
    return r;
}
Root left(Root r,Node *parent,Node *x)
{
    //  x                   y
    //A   y        -->    x   C
    //   B  C           A  B
    Node *y=x->right;
    x->right=y->left;
    y->left=x;
    if(parent!=NULL)
    {
        if(parent->left==x)  parent->left=y;
        else parent->right=y;
    }
    else r.start=y;
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
            temp=gp;
        }
    }
    else
    {
        uncle=gp->left;
        if(uncle->isblack)
        {
            if(parent->right==temp)
            {
                e=right(e,gp->parent->parent,gp->parent);
                temp=gp->parent;  
            }
            else
            {
                e=left(e,gp->parent->parent,gp->parent);
                temp=gp->parent;
            }
        }
        else
        {
            gp->isblack=false;
            parent->isblack=true;
            uncle->isblack=true;
            temp=gp;
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
        printer(e.start);
        cout<<endl;
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
                printer(e.start);
                cout<<endl;
                return e; 
            }
            else temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                entry->parent=temp;
                temp->left=entry; 
                e=color(e,entry);
                printer(e.start);
                cout<<endl;
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
    r=insert(r,6);
    r=insert(r,5);
    cout<<"came here"<<endl;
    r=insert(r,2);
    cout<<"came here"<<endl;
    r=insert(r,3);
    r=insert(r,10);
    r=insert(r,1);
    r=insert(r,9);
    r=insert(r,11);
    r=insert(r,7);
    r=insert(r,8);
    r=insert(r,12);
    printer(r.start);
    cout<<endl;
    free_mem(r.start);
    return 0;
}