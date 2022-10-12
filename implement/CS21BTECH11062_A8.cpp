/*
Code by
Govinda Rohith Y
CS21BTECH11062
CS2233-Assignment-8 (Red-Black Trees)
*/
// 1.  Each node contains the Age of a faculty.
// 
// 2.  You should implement
// A.Insert
// B.Search
#include<iostream>
using namespace std;
class Node 
{
    //Class which represents each node
    public :
    int age;
    bool isblack=true; //true represents the node is black 
    Node *left,*right,*parent;
};
class Root
{
    //class to store root of tree
    public :
    Node *start;
};
void printer(Node *temp)
{
    if(temp->left!=NULL) printer(temp->left);
    if(temp->isblack) cout<<temp->age<<"->"<<"Black color ,";
    else cout<<temp->age<<"->"<<"Red color ,";
    if(temp->right!=NULL) printer(temp->right);
}
void inorder(Root e)
{
    //Inorder traversal of tree 
    if(e.start==NULL) cout<<"Empty tree try to insert some data"<<endl;
    else printer(e.start);
}
void post(Node *temp)
{
    //postorder traversal of tree
    if(temp->isblack) cout<<temp->age<<"-> "<<"Black color ,";
    else cout<<temp->age<<"->"<<"Red color ,";
    if(temp->left!=NULL) post(temp->left);
    if(temp->right!=NULL) post(temp->right);
}
void free_mem(Node *temp)
{
    //function to free allocated memory
    if(temp->left!=NULL) free_mem(temp->left);
    if(temp->right!=NULL) free_mem(temp->right);
    delete temp;
}
Root right(Root r,Node *a)
{
    //Right rotate the tree as written below
    //    A             B
    //  B   C   ->   D      A
    //D  E                E   C
    Node *parent=a->parent;
    Node *b=a->left;
    b->parent=a->parent;
    a->parent=b;
    if(a->left->right!=NULL) a->left->right->parent=a;
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
Root left(Root r,Node *x)
{
    //Left rotate the tree as written below
    //  x                   y
    //A   y        -->    x   C
    //   B  C           A  B
    Node *parent=x->parent;
    Node *y=x->right;
    y->parent=x->parent;
    x->parent=y;
    if(x->right->left!=NULL)x->right->left->parent=x; 
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
    //function to color the tree according to the cases
    Node *parent,*uncle,*gp=NULL;
    temp->isblack=false;
    if(temp==e.start)
    {
        temp->isblack=true;
        return e;
    }
    if(temp->parent->isblack) return e;
    parent=temp->parent;
    gp=parent->parent;
    if(gp->left==parent)
    {
        //case when parent is left child of gp
        uncle=gp->right;
        if(uncle==NULL||uncle->isblack)
        {
            //uncle is black
            if(temp==parent->left)
            {
                e=right(e,gp);
                parent->isblack=true;
                gp->isblack=false;
            }
            else
            {
                e=left(e,parent);
                e=right(e,gp);
                parent->isblack=false;
                temp->isblack=true;
                gp->isblack=false;
            }
        }
        else
        {
            //uncle is red
            gp->isblack=false;
            parent->isblack=true;
            uncle->isblack=true;
            return color(e,gp);
        }
    }
    else
    {
        //case when parent is right child of gp
        uncle=gp->left;
        if(uncle==NULL||uncle->isblack)
        {
            //case when uncle is black
            if(temp==parent->right)
            {
                e=left(e,gp);
                parent->isblack=true;
                gp->isblack=false;
            }
            else
            {
                e=right(e,parent);
                e=left(e,gp);
                temp->isblack=true;
                gp->isblack=false;
                parent->isblack=false;
            }
        }
        else
        {
            //case when uncle is red
            gp->isblack=false;
            parent->isblack=true;
            uncle->isblack=true;
            return color(e,gp);
        }
    }
    e.start->isblack=true;
    return e;
}
Root insert(Root e,int a)
{
    cout<<"**** Inserted Sucessfully ***"<<endl;
    //function to insert a according to tree property
    Node *temp=e.start;
    Node *entry=new Node();
    entry->left=NULL;
    entry->right=NULL;
    entry->age=a;
    if(temp==NULL)
    {
        e.start=entry;
        entry->isblack=true;
        entry->parent=NULL;
        return e;
    }
    while(temp!=NULL)
    {
        if(a>temp->age)
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
    r=insert(r,11);
    r=insert(r,6);
    r=insert(r,8);
    r=insert(r,12);
    post(r.start);
    cout<<endl;
    free_mem(r.start);
    return 0;
}