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
    //Individual Node
};
class Head
{
    public:
    Node *start,*tail;
    //To store the head and the tail pointer
};
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
void print_for(Head h)
{
    //function to print the double linked list from head
    Node *temp=h.start;
    if(temp==NULL)
    {
        //Empty list case
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
void print_back(Head h)
{
    //function to print the double linked list from tail
    Node *temp=h.tail;
    if(temp==NULL)
    {
        //Empty list case
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
            temp=temp->prev;
        }   
    }
}

Head insert_c(Head s,int pos,string name,int age,string gender,string dept)
{
    //function to insert data in any valid position 'pos' which starts from 1
    //pos=1 for standard double linked list insertion
    Node* entry=new Node();
    Node *temp=s.start;
    int counter=0;
    entry->name=name;
    entry->age=age;
    entry->gender=gender;
    entry->dept=dept;
    if(pos==1)
    {
        //Standard double linked list insertion
        entry->next=s.start;
        entry->prev=NULL;
        if(s.start!=NULL) s.start->prev=entry;
        else s.tail=entry;
        s.start=entry;
        cout<<"*** Inserted Successfully ****"<<endl;
        return s;
    }
    while(temp!=NULL)
    {
        //insert at any position starting from 1
        counter++;
        if(counter==pos-1)
        {
            cout<<"*** Inserted Successfully ****"<<endl;
            entry->prev=temp;
            entry->next=temp->next;
            if(entry->next!=NULL) temp->next->prev=entry;
            else s.tail=entry;
            temp->next=entry;
            temp=entry;
            break;
        }
        else  temp=temp->next;
    }
    if(temp==NULL)
    {
        //Position Not valid case
        cout<<"Not valid"<<endl;
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
            cout<<"****** Requested details ******"<<endl;
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
        if(pre->next==NULL)
        {
            giv.tail=NULL;
        } 
        else pre->next->prev=NULL;
        delete pre;
        cout<<"***Deleted Successfully***"<<endl;
        return giv;
    }
    else
    {
        post=pre->next;
        while(post!=NULL)
        {
            if(post->name==name)
            {
                cout<<"***Deleted Successfully***"<<endl;
                Node *temp;
                temp=post;
                pre->next=post->next;
                post=post->next;
                if(post!=NULL)  post->prev=pre;
                else giv.tail=pre;
                delete temp;
                return giv; 
            }
            else
            {
                pre=post;
                post=post->next;
            }
        }
    }
    cout<<"Entry not found with given name"<<endl;
    return giv; 
}

int main()
{
    Head h;
    h.start=NULL;
    h.tail=NULL;
    h=insert_c(h,1,"ab",18,"Male","cse");
    h=insert_c(h,2,"cd",18,"Male","cse");
    h=insert_c(h,3,"gh",18,"Male","cse");
    h=insert_c(h,4,"ef",18,"Male","cse");
    search_a(h,"ef");
    search_a(h,"ab");  
    h=delete_b(h,"ab");
    h=delete_b(h,"ef");  
    h=delete_b(h,"gh");
    h=delete_b(h,"cd");  
    h=delete_b(h,"ef");  
    print_for(h);
    // print_back(h);
    free_mem(h);
    return 0;
}