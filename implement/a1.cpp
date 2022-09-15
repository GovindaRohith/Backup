/*
Data Structures(CS2233)
Assignment 1 (Implementation of linked list)
code by
Govinda Rohith Y
CS21BTECH11062
*/
/*
Question :
Each node contains the Name, Age, Gender, and Department of
a faculty. Assume that Name is unique
You should implement  
A.Search by Name
B.Delete by Name
C.Insert
*/
#include<iostream>
using namespace std;
class Node
{
    //Individual Node
    public:
    string name,dept,gender;
    int age;
    Node *next;
};
class Head
{
    public:
    //Stores the head of the linked list
    Node *start;
};
void printer_func(Head h)
{
    //function to print whole linked list
    Node *temp=h.start;
    if(temp==NULL) cout<<"Empty list try to insert some data"<<endl;
    while(temp!=NULL)
    {
        cout<<"***********************"<<endl;
        cout<<"Name           :"<<temp->name<<endl;
        cout<<"Age            :"<<temp->age<<endl;
        cout<<"Gender         :"<<temp->gender<<endl;
        cout<<"Department     :"<<temp->dept<<endl;
        cout<<"***********************"<<endl;
        temp=temp->next;
    }
}
void free_mem(Head h)
{
    //function to free allocated space
    Node * temp=h.start,*temp2;
    while(temp!=NULL)
    {
        temp2=temp;
        temp=temp->next;
        delete temp2;
    }
}
Head delete_b(Head h,string name)
{
    //Delete a Node by a given name
    Node* prev=h.start,*post;
    if(prev==NULL)
    {
        //Empty linked list case
        cout<<"Empty list try to insert some data"<<endl;
        return h;
    }
    else if(prev->name==name)
    {
        //Required node is beggining of the linked list
        h.start=prev->next;
        delete prev;
        cout<<"***  Deleted Successfully    ****"<<endl;
        return h;
    }
    else
    {
        post=prev->next;
        while(post!=NULL)
        {
            if(post->name==name)
            {
                //delete operation
                Node *temp;
                temp=post;
                prev->next=post->next;
                post=post->next;
                delete temp;
                cout<<"***  Deleted Successfully    ****"<<endl;
                return h;
            }
            else
            {
                //propagation steps
                prev=post;
                post=post->next;
            }
        }
    }
    cout<<"Not found!!"<<endl;
    return h;
}
Head insert_c(Head s,int pos,string name,int age,string gender,string dept)
{
    //function to insert data in any valid position 'pos' which starts from 1
    //pos=1 for standard linked list insertion
    Node* entry=new Node();
    Node *temp=s.start;
    int counter=0;
    entry->name=name;
    entry->age=age;
    entry->gender=gender;
    entry->dept=dept;
    if(pos==1)
    {
        //Standard linked list insertion
        entry->next=s.start;
        s.start=entry;
        cout<<"***  Inserted Successfully   ****"<<endl;
        return s;
    }
    while(temp!=NULL)
    {
        //insert at any position starting from 1
        counter++;
        if(counter==pos-1)
        {
            entry->next=temp->next;
            temp->next=entry;
            temp=entry;
            cout<<"***  Inserted Successfully   ****"<<endl;
            break;
        }
        else  temp=temp->next;
    }
    if(temp==NULL)
    {
        //Not valid  case
        cout<<"Entered position is not valid"<<endl;
    }
    return s;
}
bool search_a(Head h,string req)
{
    //returns true if there exists a node with given name else false
    Node *temp=h.start;
    if(temp==NULL)
    {
        //Empty linked list case
        cout<<"Empty list try to insert some data"<<endl;
        return false;
    }
    while(temp!=NULL)
    {
        if(temp->name==req)
        {
            //Prints Required details
            cout<<"**** Requested Details   ****"<<endl;
            cout<<"Name           :"<<temp->name<<endl;
            cout<<"Age            :"<<temp->age<<endl;
            cout<<"Gender         :"<<temp->gender<<endl;
            cout<<"Department     :"<<temp->dept<<endl;
            return true;
        }
        temp=temp->next;
    }
    cout<<"Not found!!"<<endl;
    return false;
}

int main()
{
    Head h;
    h.start=NULL;
    h=insert_c(h,1,"ab",18,"Male","cse");
    h=insert_c(h,1,"bb",18,"Female","ES");
    h=insert_c(h,3,"cb",18,"Female","EE");
    h=insert_c(h,4,"db",18,"Female","CSE");
    search_a(h,"ab");
    search_a(h,"aa");
    h=delete_b(h,"db");
    h=delete_b(h,"ab");
    h=delete_b(h,"bb");
    h=delete_b(h,"cb");
    printer_func(h);
    h=insert_c(h,1,"ab",18,"Male","cse");
    printer_func(h);
    free_mem(h);
    return 0;
}