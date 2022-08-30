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
void printer(Node *temp)
{
    if(temp->left!=NULL) printer(temp->left);
    cout<<"***********************"<<endl;
    cout<<"Name           :"<<temp->name<<endl;
    cout<<"Age            :"<<temp->age<<endl;
    cout<<"Gender         :"<<temp->gender<<endl;
    cout<<"Department     :"<<temp->dept<<endl;
    cout<<"***********************"<<endl;
    if(temp->right!=NULL) printer(temp->right);
}
void free_mem(Node *temp)
{
    if(temp->left!=NULL) free_mem(temp->left);
    if(temp->right!=NULL) free_mem(temp->right);
    free(temp);
}
Root insert_a(Root e,int age,string name,string gender,string dept)
{
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
        return e;
    }
    else
    {
        while(temp!=NULL)
        {
            if(name>temp->name)
            {
                if(temp->right==NULL)
                {
                    temp->right=entry; 
                    return e; 
                }
                else temp=temp->right;
            }
            else
            {
                if(temp->left==NULL)
                {
                    temp->left=entry;
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
    Node *temp=e.start;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        while (temp!=NULL)
        {
            if(name>temp->name)
            {
                if(temp->right==NULL) return 0;
                else temp=temp->right;
            }
            else if(name==temp->name) return 1;
            else
            {
                if(temp->left==NULL) return 0;
                else temp=temp->left;
            }
        }
        return 0;
    }
}
Root deleter(Node *req,Root e,Node *prev,int dir)
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
    Node *prev;
    int dir=0;
    Node *temp=e.start;
    if(temp==NULL) return e;
    while (temp!=NULL)
    {
        if(name>temp->name)
        {
            if(temp->right==NULL) return e;
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
    r=delete_b(r,"a");
    printer(r.start);
    free_mem(r.start);
    return 0;
}