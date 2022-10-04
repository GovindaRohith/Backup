/*
* Code by
* Govinda Rohith Y
* CS21BTECH11062
* implemenation of Threaded binary search tree
*/
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
    //Class to store each node of the tree
    public :
    int age;
    unsigned short int pos;
    string name,gender,dept;
    Node *left,*right;
};
class Root
{
    //class to store the root node of the tree
    public :
    Node *start;
};
Node * left_search(Node *temp)
{
    //function to return the inorder successor of *temp
    while(temp->pos!=00&&temp->pos!=01)
    {
        temp=temp->left;
    }
    return temp;
}
void free_mem(Root r)
{
    //function to free allocated memory
    if(r.start!=NULL)
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
            delete temp2;
        }
    }
}
void print_func(Root r)
{
    //Inorder traversal of the tree
    if(r.start==NULL) cout<<"Empty tree try to insert some data"<<endl;
    else
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
        cout<<endl;
    }
}
Root insert_a(Root r,int age,string name,string gender,string dept)
{
    //function which inserts and returns the root 
    Node *entry=new Node();
    entry->age=age;
    entry->name=name;
    entry->gender=gender;
    entry->dept=dept;
    entry->left=NULL;
    entry->right=NULL;
    entry->pos=00;
    if(r.start==NULL) r.start=entry;
    else
    {
        Node *temp=r.start;
        while(temp!=NULL)
        {
            if(temp->name==name)
            {
                cout<<"Entry with given name already exsits"<<endl;
                delete entry;
                return r;
            }
            if(name>temp->name&&(temp->pos==11||temp->pos==01)) temp=temp->right;
            else if(name>temp->name&&(temp->pos==00||temp->pos==10))
            {
                entry->right=temp->right;
                temp->right=entry;
                entry->left=temp;
                if(temp->pos==00) temp->pos=01;
                else temp->pos=11;
                break;
            }
            else if(name<temp->name&&(temp->pos==11||temp->pos==10)) temp=temp->left;
            else 
            {
                entry->left=temp->left;
                temp->left=entry;
                entry->right=temp;
                if(temp->pos==01)  temp->pos=11;
                else  temp->pos=10;
                break;
            }
        }
    }
    cout<<"*** Inserted Successfully ***"<<endl;
    return r;
}
bool search_c(Root r,string name)
{
    //function returns true if node is present with given "name"
    Node *temp=left_search(r.start);
    if(temp==NULL)
    {
        cout<<"Empty tree try to insert some data"<<endl;
    }
    while(temp!=NULL)
    {
        if(temp->name==name)
        {
            cout<<"***** Requested details *****"<<endl;
            cout<<"Name           :"<<temp->name<<endl;
            cout<<"Age            :"<<temp->age<<endl;
            cout<<"Gender         :"<<temp->gender<<endl;
            cout<<"Department     :"<<temp->dept<<endl;
            cout<<"****************************"<<endl;
            return true;
        }
        if(temp->pos==01||temp->pos==11)
        {
            temp=left_search(temp->right);
        }
        else 
        {
            temp=temp->right;
        }
    }
    cout<<"Entry not found with given name"<<endl;
    return false;
}

Node * opt(Node *temp)
{
    //swaps given node (temp) data with its inorder Suc untill
    //it returns deletion of a leaf node case
    Node *temp2;
    while(temp->pos!=00)
    {
        if(temp->pos==01||temp->pos==11)
        {
            temp2=left_search(temp->right);
            temp->age=temp2->age;
            temp->dept=temp2->dept;
            temp->gender=temp2->gender;
            temp->name=temp2->name;
            temp=temp2;
        }
        else 
        {
            if(temp->right==NULL) return temp;
            temp->age=temp->right->age;
            temp->dept=temp->right->dept;
            temp->gender=temp->right->gender;
            temp->name=temp->right->name;
            temp=temp->right;
        }
    }
    return temp;
}
Root deleter(Root r,Node *temp)
{
    //function for deletion of a LEAF node and returns Root 
    cout<<"*** Deleted Successfully ***"<<endl;
    Node *parent;
    bool isleft;
    if(temp->left==NULL||temp->right==NULL)
    {
        if(temp->left==NULL)
        {
            if(r.start==temp) r.start=temp->right;
            isleft=1;
            parent=temp->right;
            parent->left=temp->left;
        } 
        else
        {
            if(r.start==temp)r.start=temp->left;
            isleft=0;
            parent=temp->left;
            parent->right=temp->right;
        } 
    } 
    else
    {
        //is left tells if it's left child or not 
        //else block here assigns isleft param according to left
        //or right child
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
        //pos assigner and inOrder assigner
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
    delete temp;
    return r;
}
Root delete_b(Root r,string name)
{
    //function to delete node with given name
    Node *temp=r.start;
    if(temp->pos==00&&temp->name==name)
    {
        //deletion of ONLY root node
        cout<<"*** Deleted Successfully ***"<<endl;
        delete temp;
        r.start=NULL;
        return r;
    }
    if(r.start==NULL) cout<<"Empty list try to insert some data"<<endl;
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
           cout<<"Entry not found with given name"<<endl;
           break;
        }
    }
    return r;
}
int main()
{
    Root r;
    r.start=NULL;
    r=insert_a(r,18,"l","M","A");
    r=insert_a(r,18,"h","M","A");
    r=insert_a(r,18,"d","M","A");
    search_c(r,"l");
    r=delete_b(r,"l");
    r=delete_b(r,"d");
    r=delete_b(r,"h");
    print_func(r); 
    free_mem(r);
    return 0;
}