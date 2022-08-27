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
#include<stdlib.h>
#include<string>
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
Head insert_c(Head h,string name,int age,string gender,string dept)
{
    Node* entry=NULL;
    entry = new Node();
    entry->name=name;
    entry->dept=dept;
    entry->age=age;
    entry->gender=gender;
    entry->next=h.start;
    h.start=entry;
    return h;
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
int main()
{
    Head h;
    h.start=NULL;
    h=insert_c(h,"ab",18,"Male","cse");
    h=insert_c(h,"bb",18,"Female","ES");
    h=insert_c(h,"cb",18,"Female","EE");
    h=insert_c(h,"db",18,"Female","CSE");
    printer_func(h);
    cout<<"After the delete"<<endl;
    h=delete_b(h,"db");
    // h=delete_b(h,"ab");
    printer_func(h);
    return 0;
}