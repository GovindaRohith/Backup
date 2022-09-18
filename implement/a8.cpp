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
    if(temp->isblack) cout<<temp->item<<"->"<<"Black color ,";
    else cout<<temp->item<<"->"<<"Red color ,";
    if(temp->right!=NULL) printer(temp->right);
}
void post(Node *temp)
{
    if(temp->isblack) cout<<temp->item<<"-> "<<"Black color ,";
    else cout<<temp->item<<"->"<<"Red color ,";
    if(temp->left!=NULL) post(temp->left);
    if(temp->right!=NULL) post(temp->right);
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
    Node *parent,*uncle,*gp=NULL;
    temp->isblack=false;
    if(temp==e.start)
    {
        temp->isblack=true;
        return e;
    }
    if(temp->parent->isblack) return e;
    //                 ****Inequality check here ******
    while(temp!=e.start&&temp->parent->isblack == false)
    {
    parent=temp->parent;
    gp=parent->parent;
    if(gp->left==parent)
    {
        uncle=gp->right;
        if(uncle==NULL||uncle->isblack)
        {
            if(uncle==NULL)
            {
                e=right(e,gp->parent,gp);
                temp=parent;
                temp->right->isblack=false;
            }
            else
            {
                if(parent->right==temp)
                {
                    e=left(e,gp->parent,gp);
                    temp=parent;
                }
                else    
                {
                    e=right(e,gp->parent,gp);
                    temp=parent;
                }
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
        if(uncle==NULL||uncle->isblack)
        {
            if(uncle==NULL)
            {
                // e=right(e,gp->parent,gp);
                // temp=parent;
                e=left(e,gp->parent,gp);
                temp=parent;
                temp->left->isblack=false;
            }
            else
            {
                if(parent->right==temp)
                {
                    e=right(e,gp->parent,gp);
                    temp=parent;  
                }
                else
                {
                    e=left(e,gp->parent,gp);
                    temp=parent;
                }
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
    }
    e.start->isblack=true;
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
                temp->left=entry; 
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
    r=insert(r,6);
    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,3);
    r=insert(r,10);
    r=insert(r,1);
    r=insert(r,9);
    // r=insert(r,11);
    // r=insert(r,7);
    // r=insert(r,8);
    // r=insert(r,12);
    post(r.start);
    cout<<endl;
    free_mem(r.start);
    return 0;
}