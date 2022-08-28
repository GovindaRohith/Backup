/*
Govinda Rohith Y
CS21BTECH11062
Implementation of double-linked list
1.Each node contains the Name, Age, Gender, and Department of a
faculty. Assume that Name is unique

2.You should implement  
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
    Node *next,*prev;
};
class Head
{
    public:
    Node *start;
//tune to check whether the enetered positon number is whether correct
};
void print_func(Head h)
{
    Node *temp=h.start;
    if(temp==NULL)
    {
        cout<<"Empty list"<<endl;
    }
    else
    {
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
}
Head insert_c(Head s,int pos,string name,int age,string gender,string dept)
{
    Node* entry=new Node();;
    Node *temp=s.start;
    int counter=0;
    entry->name=name;
    entry->age=age;
    entry->gender=gender;
    entry->dept=dept;
    if(pos==1)
    {
        entry->next=s.start;
        entry->prev=NULL;
        if(s.start!=NULL)
        {
        s.start->prev=entry;
        }
        s.start=entry;
        return s;
    }
    while(temp!=NULL)
    {
        counter++;
        if(counter==pos-1)
        {
            entry->prev=temp;
            entry->next=temp->next;
            if(entry->next!=NULL)
            {
            temp->next->prev=entry;
            }
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
Head delete_b(Head giv,string name)
{
    Node *pre,*post;
    pre=giv.start;
    if(pre==NULL)
    {
        cout<<"Empty list try to insert some data"<<endl;
        return giv;
    } 
    else if(pre->name==name)
    {
        giv.start=pre->next;
        if(pre->next==NULL) return giv;
        pre->next->prev=NULL;
        free(pre);
        return giv;
    }
    else
    {
        post=pre->next;
        while(post!=NULL)
        {
            if(post->name==name)
            {
                Node *temp;
                temp=post;
                pre->next=post->next;
                post=post->next;
                if(post!=NULL)  post->prev=pre;
                free(temp);
            }
            else
            {
                pre=post;
                post=post->next;
            }
        }
    }
    return giv; 
}

int main()
{
    Head h;
    h.start=NULL;
    h=insert_c(h,1,"ab",18,"Male","cse");
    h=insert_c(h,1,"cd",18,"Male","cse");
    h=insert_c(h,1,"gh",18,"Male","cse");
    h=insert_c(h,1,"ef",18,"Male","cse");
    h=delete_b(h,"cd");
    h=delete_b(h,"ab");
    h=delete_b(h,"gh");
    h=delete_b(h,"ef");
    print_func(h);
    free_mem(h);
    return 0;
}