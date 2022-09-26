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
    public :
    int age;
    string name,gender,dept;
    Node *left,*right;
};
class Root
{
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
    if(temp==NULL) cout<<"Empty tree try to insert some data"<<endl;
    else inOrder_rec(temp);
}
void free_mem(Node *temp)
{
    //frees allocated memory
    if(temp->left!=NULL) free_mem(temp->left);
    if(temp->right!=NULL) free_mem(temp->right);
    delete temp;
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
Root deleter(Node *req,Root e,Node *prev,int dir)
{
    //function to delete node "req"
    if(req->left==NULL&&req->right!=NULL)
    {
        if(dir==1) prev->right=req->right;
        else prev->left=req->right;
        cout<<"*** Deleted successfully ***"<<endl;
        delete req;
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
        cout<<"*** Deleted successfully ***"<<endl;
        delete req;
    }
    else
    {
        // name ,age ,gender,dept
        req->name=req->right->name;
        req->age=req->right->age;
        req->gender=req->right->gender;
        req->dept=req->right->dept;
        return deleter(req->right,e,req,1);
    }
    return e;
}
Root delete_b(Root e,string name)
{
    //this function seperates the cases and calls the function deleter
    //appropiately and return Root after deletion
    Node *prev;
    int dir=0;
    Node *temp=e.start;
    if(temp==NULL) 
    {
        cout<<"Empty tree try to insert some data"<<endl;
        return e;
    }
    while (temp!=NULL)
    {
        if(name>temp->name)
        {
            if(temp->right==NULL)
            {
                cout<<"Empty tree try to insert some data"<<endl;
                return e;
            } 
            else
            {
                prev=temp;
                temp=temp->right;
            } 
            dir=1;
        }
        else if(name==temp->name)
        {
            return deleter(temp,e,prev,dir);
        }
        else
        {
            if(temp->left==NULL)
            {
                cout<<"Empty tree try to insert some data"<<endl;
                return e;
            } 
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
    Root r;
    r.start=NULL;
    r=insert_a(r,7,"abcdefghi","M","CSE");
    r=insert_a(r,12,"abcdefghijkl","M","CSE");
    r=insert_a(r,6,"a","M","CSE");
    r=insert_a(r,1,"abcdef","M","CSE");
    r=insert_a(r,2,"abc","M","CSE");
    r=insert_a(r,5,"ab","M","CSE");
    r=insert_a(r,10,"abcde","M","CSE");
    r=insert_a(r,3,"abcd","M","CSE");
    r=insert_a(r,11,"abcdefgh","M","CSE");
    r=insert_a(r,9,"abcdefg","M","CSE");
    r=insert_a(r,8,"abcdefghij","M","CSE");
    delete_b(r,"a");
    delete_b(r,"ab");
    delete_b(r,"abc");
    delete_b(r,"abcd");
    delete_b(r,"abcde");
    delete_b(r,"abcdef");
    delete_b(r,"abcdefg");
    delete_b(r,"abcdefgh");
    delete_b(r,"abcdefghi");
    // delete_b(r,"abcdefghij");
    // delete_b(r,"abcdefghijkl");
    inOrder(r.start);
    free_mem(r.start);
    return 0;
}