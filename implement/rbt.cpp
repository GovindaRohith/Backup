#include<iostream>
#include<iostream>
using namespace std;
class Node 
{
    public :
    int item;
    bool isblack=true;
    Node *left,*right;
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
Root insert(Root e,int a)
{

    return e;
}
int main()
{
    return 0;
}