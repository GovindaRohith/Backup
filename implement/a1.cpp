/*
Govinda Rohith Y
CS21BTECH11062
Problem 1:
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
    public:
    string name,dept,gender;
    int age;
    Node *next;
};
class Head
{
    public:
    Node *start;
};
void printer_func(Head h)
{
    Node *temp=h.start;
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
Head delete_b(Head h,string name)
{
    Node* prev=h.start,*post;
    if(prev==NULL)
    {
        cout<<"Empty list try to insert some data"<<endl;
        return h;
    }
    else if(prev->name==name)
    {
        h.start=prev->next;
        free(prev);
        return h;
    }
    else
    {
        post=prev->next;
        while(post!=NULL)
        {
            if(post->name==name)
            {
                Node *temp;
                temp=post;
                prev->next=post->next;
                post=post->next;
                free(temp);
                return h;
            }
            else
            {
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
    Node* entry=new Node();
    Node *temp=s.start;
    int counter=0;
    entry->name=name;
    entry->age=age;
    entry->gender=gender;
    entry->dept=dept;
    if(pos==1)
    {
        entry->next=s.start;
        s.start=entry;
        return s;
    }
    while(temp!=NULL)
    {
        counter++;
        if(counter==pos-1)
        {
            entry->next=temp->next;
            temp->next=entry;
            temp=entry;
            break;
        }
        else  temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"Not valid"<<endl;
    }
    return s;
}

bool search_a(Head h,string req)
{
    Node *temp=h.start;
    if(temp==NULL)
    {
        cout<<"Empty list try to insert some data"<<endl;
        return false;
    }
    while(temp!=NULL)
    {
        if(temp->name==req)
        {
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
void free_mem(Head h)
{
    //function to free allocated space
    Node * temp=h.start;
    while(temp!=NULL)
    {
        free(temp);
        temp=temp->next;
    }
}
int main()
{
    Head h;
    h.start=NULL;
    h=insert_c(h,1,"ab",18,"Male","cse");
    h=insert_c(h,2,"bb",18,"Female","ES");
    h=insert_c(h,3,"cb",18,"Female","EE");
    h=insert_c(h,4,"db",18,"Female","CSE");
    printer_func(h);
    cout<<"After the delete"<<endl;
    h=delete_b(h,"db");
    h=delete_b(h,"ab");
    printer_func(h);
    free_mem(h);
    return 0;
}