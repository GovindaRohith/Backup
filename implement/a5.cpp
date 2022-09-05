//TBST 
//1.  Each node contains the Age, Name, Gender, and
// Department of a faculty.
// Assume the Name is unique
// In-order traversal of threaded binary trees
// 2.  You should implement
// A.Insert
// B.Delete by Name
// C.Search by Name
// D.In-order traversal
#include<iostream>
using namespace std;
class Node 
{
    public :
    int age;
    unsigned short int pos;
    string name,gender,dept;
    Node *left,*right;
};
class Root
{
    public :
    Node *start;
};
Node * left_search(Node *temp)
{
    while(temp->pos!=00&&temp->pos!=01)
    {
        temp=temp->left;
    }
    return temp;
}
void print_func(Root r)
{
    Node *temp=left_search(r.start);
    while(temp!=NULL)
    {
        cout<<"***********************"<<endl;
        cout<<"Name           :"<<temp->name<<endl;
        cout<<"Age            :"<<temp->age<<endl;
        cout<<"Gender         :"<<temp->gender<<endl;
        cout<<"Department     :"<<temp->dept<<endl;
        cout<<"***********************"<<endl;
        if(temp->pos==01||temp->pos==11)
        {
            temp=left_search(temp->right);
        }
        else 
        {
            temp=temp->right;
        }
    }
}
void verify(Node *temp)
{
    if(temp->pos!=00&&temp->pos!=01) verify(temp->left);
    cout<<"***********************"<<endl;
    cout<<"Name           :"<<temp->name<<endl;
    cout<<"Age            :"<<temp->age<<endl;
    cout<<"Gender         :"<<temp->gender<<endl;
    cout<<"Department     :"<<temp->dept<<endl;
    cout<<"***********************"<<endl;
    if(temp->pos!=00&&temp->pos!=10) verify(temp->right);
}
Root deleter(Root r,Node *temp)
{
    Node *parent;
    int isleft;
    //1 -> left child
    //0 ->right child
    //if  left node 
    //    temp->left ||->left  !=temp  --> parent=temp->right
    //    temp->left ||->right !=temp  -->
    //   temp->right->left ==temp   ->left node
    //right node 
    //    temp->right ||->left !=temp   --> 
    //    temp->right ||->right !=temp  -->parent=temp->left
    //   temp->left->right ==temp   -->right node
    if(temp->left==NULL||temp->right==NULL)
    {
        if(temp->left==NULL)
        {
            isleft=1;
            parent=temp->right;
            parent->left=temp->left;
        } 
        else
        {
            isleft=0;
            parent=temp->left;
            parent->right=temp->right;
        } 
    } 
    else
    {
        if(temp->right->left==temp)
        {
            isleft=1;
            parent=temp->right;
        } 
        if(temp->left->right ==temp)
        {
            isleft=0;
            parent=temp->left;
        } 
    }
    if(isleft==1)
    {
        parent->left=temp->left;
        if(parent->pos==11) parent->pos=01;
        if(parent->pos==10) parent->pos=00;
    }
    else
    {
        parent->right=temp->right;
        if(parent->pos==11) parent->pos=10;
        if(parent->pos==01) parent->pos=00;
        
    }
    free(temp);
    return r;
}
Node * opt(Node *temp)
{
    Node *temp2;
    while(temp->pos!=00)
    {
        if(temp->pos==01||temp->pos==11)
        {
            temp2=left_search(temp->right);
            temp->name=temp2->name;
            temp=temp2;
        }
        else 
        {
            temp->name=temp->right->name;
            temp=temp->right;
        }
    }
    return temp;
}
Root delete_b(Root r,string name)
{
    Node *temp=r.start;
    int prev;
    while(1>0)
    {
        if(name<temp->name&&temp->pos!=01&&temp->pos!=00)
        {
            temp=temp->left;
        }
        else if(name>temp->name&&temp->pos!=00&&temp->pos!=10)
        {
            temp=temp->right;
        }
        else if(name==temp->name)
        {
            return deleter(r,opt(temp));
            break;
        }
        else
        {
            printf("Element not found!");
            break;
        }
    }
    return r;
}
Root insert(Root r,int n,int age,string name,string gender,string dept)
{
    Node *entry=new Node();
    entry->age=age;
    entry->name=name;
    entry->gender=gender;
    entry->dept=dept;
    entry->left=NULL;
    entry->right=NULL;
    entry->pos=00;
    if(r.start==NULL)
    {
        entry->right=NULL;
        entry->left=NULL;
        r.start=entry;
    }
    else
    {
        Node *temp=r.start;
        //parent pos change
        while(temp!=NULL)
        {
            //propagation steps
            if(name>temp->name&&(temp->pos==11||temp->pos==01)) temp=temp->right;
            else if(name>temp->name&&(temp->pos==00||temp->pos==10))
            {
                entry->right=temp->right;
                temp->right=entry;
                if(temp->pos==00)
                {
                    entry->left=temp;
                    temp->pos=01;
                }
                else 
                {
                    entry->left=temp->left;
                    temp->pos=11;
                }
                break;
            }
            //propagation steps
            else if(name<temp->name&&(temp->pos==11||temp->pos==10)) temp=temp->left;
            else 
            {
                //n<temp->item &&(temp->pos==01||temp->pos==00)
                if(temp->pos==01) 
                {
                    entry->left=temp->left;
                    temp->pos=11;
                } 
                else  
                {
                    entry->left=NULL;
                    temp->pos=10;
                }
                temp->left=entry;
                entry->right=temp;
                break;
            }
        }
    }
    return r;
}
void free_mem(Root r)
{
    Node *temp=left_search(r.start),*temp2;
    while(temp!=NULL)
    {
        temp2=temp;
        if(temp->pos==01||temp->pos==11)
        {
            temp=left_search(temp->right);
        }
        else 
        {
            temp=temp->right;
        }
        free(temp2);
    }

}
int main()
{
    //a b c d e f g h i j  k  l  m  n  o  p  q  r 
    //1 2 3 4 5 6 7 8 9 10 11 12 13 14
    Root r;
    r.start=NULL;
    r=insert(r,6,18,"f","M","A");
    r=insert(r,5,18,"e","M","A");
    r=insert(r,2,18,"b","M","A");
    r=insert(r,3,18,"c","M","A");
    r=insert(r,10,18,"j","M","A");
    r=insert(r,1,18,"a","M","A");
    r=insert(r,9,18,"i","M","A");
    r=insert(r,11,18,"k","M","A");
    r=insert(r,7,18,"g","M","A");
    r=insert(r,8,18,"h","M","A");
    r=insert(r,12,18,"l","M","A");
    print_func(r);
    printf("After del \n");
    // check for 6,5
    r=delete_b(r,"f");
    r=delete_b(r,"l");
    print_func(r); 
    printf("\n");
    free_mem(r);
    return 0;
}