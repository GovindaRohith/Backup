/*
Code by
Govinda Rohith Y
CS21BTECH11062
Assignment 4
Implmentation of Binary search tree
*/
// 1. Each node contains the Age, Name, Gender, and
// Department of a faculty. Assume the Name is unique
// 2. You should implement  
// A.insert_a
// B.Delete by Name
// C.Search by Name
#include<iostream>
using namespace std;
class Node 
{
    //Class to store data from each node of the tree
    public :
    int age;
    string name,gender,dept;
    Node *left,*right;
};
class Root
{
    //Class to store root node of the tree
    public :
    Node *start;
};
void inOrder_rec(Node *temp)
{
    //prints data according to the inorder traversal of the tree
    if(temp->left!=NULL) inOrder_rec(temp->left);
    cout<<"***********************"<<endl;
    cout<<"Name           :"<<temp->name<<endl;
    cout<<"Age            :"<<temp->age<<endl;
    cout<<"Gender         :"<<temp->gender<<endl;
    cout<<"Department     :"<<temp->dept<<endl;
    cout<<"***********************"<<endl;
    if(temp->right!=NULL) inOrder_rec(temp->right);
}
void inOrder(Node *temp)
{
    //Evaluates if the tree is empty
    if(temp==NULL) cout<<"Empty tree try to insert some data"<<endl;
    else inOrder_rec(temp);
}
void free_mem_in(Node *temp)
{
    //frees allocated memory using recursion
    if(temp->left!=NULL) free_mem_in(temp->left);
    if(temp->right!=NULL) free_mem_in(temp->right);
    delete temp;
}
void free_mem(Root r)
{
    //Evaluates if the tree is empty
    if(r.start!=NULL) free_mem_in(r.start);
}
Root insert_a(Root e,int age,string name,string gender,string dept)
{
    //inserts node according to property of BST and returns the root of BST
    Node *temp=e.start;
    Node *entry=new Node();
    entry->age=age;
    entry->name=name;
    entry->gender=gender;
    entry->dept=dept;
    entry->left=NULL;
    entry->right=NULL;
    if(temp==NULL)
    {
        e.start=entry;
        cout<<"*** Inserted Successfully *****"<<endl;
        return e;
    }
    else
    {
        while(temp!=NULL)
        {
            if(name>temp->name)
            {
                //propagation to right side of the tree
                if(temp->right==NULL)
                {
                    temp->right=entry; 
                    cout<<"*** Inserted Successfully *****"<<endl;
                    return e; 
                }
                else temp=temp->right;
            }
            else if(name==temp->name)
            {
                //case when duplicate name is entered
                cout<<"Entry with given name already exits"<<endl;
                delete entry;
                return e;
            }
            else
            {
                //propagation to left side of the tree
                if(temp->left==NULL)
                {
                    temp->left=entry;
                    cout<<"*** Inserted Successfully *****"<<endl;
                    return e; 
                }
                else temp=temp->left;
            }
        }
        return e;
    }
}
bool search_c(Root e,string name)
{
    //returns TRUE if there exist a data entry with given name
    //else returns FALSE
    Node *temp=e.start;
    if(temp==NULL)
    {
        cout<<"Empty tree try to insert some data"<<endl;
        return 0;
    }
    else
    {
        while (temp!=NULL)
        {
            if(name>temp->name)
            {
                if(temp->right==NULL) break;
                else temp=temp->right;
            }
            else if(name==temp->name)
            {
                //Prints when node is found
                cout<<"*** Requested details ***"<<endl;
                cout<<"Name           :"<<temp->name<<endl;
                cout<<"Age            :"<<temp->age<<endl;
                cout<<"Gender         :"<<temp->gender<<endl;
                cout<<"Department     :"<<temp->dept<<endl;
                cout<<"***********************"<<endl;
                return true;
            } 
            else
            {
                if(temp->left==NULL) break;
                else temp=temp->left;
            }
        }
        cout<<"*** Not found ****"<<endl;
        return 0;
    }
}
Node *inSucc(Node *temp)
{
    //Returns in order successor for a given node
    
    return temp;
}
Node * dell(Node *temp,Node *parent,Node *start,int dir)
{
    if(temp->right==NULL&&temp->left==NULL)
    {
        if(temp==start)
        {
            delete (temp);
            return NULL;
        }
        if(dir==1)parent->right=NULL;
        else parent->left=NULL;
        delete (temp);
        return start;
    }
    else if(temp->right==NULL)
    {
        //dir -->1 denotes right side
        if(parent==NULL)
        {
            Node *temp2=temp->left;
            delete (temp);
            return temp2;
        }
        if(dir==1) parent->right=temp->left;
        else parent->left=temp->left;
        delete (temp);
    }
    else if(temp->left==NULL)
    {
        if(parent==NULL)
        {
            Node *temp2=temp->right;
            delete (temp);
            return temp2;
        }
        if(dir==1)parent->right=temp->right;
        else parent->left=temp->right;
        delete (temp);
    }
    else
    {
        parent=temp;
        Node *succ,*temp2=temp;
        temp=temp->right;
        while(temp!=NULL&&temp->left!=NULL)
        {
            parent=temp;
            if(temp->left!=NULL) temp=temp->left;
            else break;
        }
        succ=temp;
        //parent is inorder successor
        temp2->age=succ->age;
        temp2->dept=succ->dept;
        temp2->gender=succ->gender;
        temp2->name=succ->name;
        if(succ==parent->right)dir=1;
        else dir=0;
        //parent is inorder succ
        return dell(succ,parent,start,dir);
    }
    return start;
}
Node * delete_b(Node *start,string name)
{
    //Deletes the node accordingly and returns root node
    Node *temp=start,*parent=NULL;
    int dir=1;
    if(temp==NULL)
    {
        cout<<"Empty Tree insert some data"<<endl;
        return start;
    }
    while(temp!=NULL)
    {
        if(name>temp->name)
        {
            parent=temp;
            dir=1;
            if(temp->right==NULL)
            {
                cout<<"Entry not found"<<endl;
                break;
            }
            else temp=temp->right;
        }
        else if(name==temp->name)
        {
            cout<<"*** Deleted Successfully ***"<<endl;
            return  dell(temp,parent,start,dir);
            break;
        }
        else
        {
            dir=0;
            parent=temp;
            if(temp->left==NULL)
            {
                cout<<"Entry not found"<<endl;
                break;
            }
            else temp=temp->left;
        }
    }
    return start;
}
int main()
{
    Root r;
    r.start=NULL;
    r=insert_a(r,18,"f","M","A");
    r=insert_a(r,18,"e","M","A");
    r=insert_a(r,18,"b","M","A");
    r=insert_a(r,18,"c","M","A");
    r=insert_a(r,18,"j","M","A");
    r=insert_a(r,18,"a","M","A");
    r=insert_a(r,18,"i","M","A");
    r=insert_a(r,18,"k","M","A");
    r=insert_a(r,18,"g","M","A");
    r=insert_a(r,18,"h","M","A");
    r=insert_a(r,18,"l","M","A");
    r=insert_a(r,18,"d","M","A");
    // search_c(r,"a");
    r.start=delete_b(r.start,"f");
    r.start=delete_b(r.start,"e");
    r.start=delete_b(r.start,"b");
    r.start=delete_b(r.start,"c");
    r.start=delete_b(r.start,"j");
    r.start=delete_b(r.start,"a");
    r.start=delete_b(r.start,"i");
    r.start=delete_b(r.start,"k");
    r.start=delete_b(r.start,"g");
    r.start=delete_b(r.start,"h");
    r.start=delete_b(r.start,"l");
    r.start=delete_b(r.start,"d");
    inOrder(r.start);
    free_mem(r);
    return 0;
}