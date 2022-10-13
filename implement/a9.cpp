// 1.Each node contains the Age of a faculty. 
// 2.You should implement  
// A.Insert
// B.Search
// C.Delete 
// 3.Take the value of n as five
#include<iostream>
#include<stdlib.h>
// #define N 5;
using namespace std;
int N=5;
class Node
{
    public:
    int no;
    // no of keys in Node
    int *keys; //array of keys
    Node **child; //array of child nodes
    Node *parent; //array of parent NODE
};  
class Root
{
    public :
    Node *start;
};
void act(Node *temp,int age,Node *left,Node *right);
void printer(Node *temp)
{
    int i;
    if(temp!=NULL) //change this condition here due to multiple checks
    {
    for(i=0;i<temp->no;i++)
    {
        if(temp->child[i]!=NULL)
        {
            printer(temp->child[i]);
        }
        cout<<temp->keys[i]<<" ";
    }
    if(temp->child[i]!=NULL)
    {
        printer(temp->child[i]);
    }
    }
}
void free_mem(Node *temp)
{
    int i;
    if(temp!=NULL)
    {
    free(temp->keys);
    for(i=0;i<temp->no;i++)
    {
        if(temp->child[i]!=NULL)
        {
            free_mem(temp->child[i]);
        }
    }
    if(temp->child[i]!=NULL)
    {
        free_mem(temp->child[i]);
    }
    free(temp->child);
    delete temp;
    }
}
void ins_spilt(Node *temp)
{
    //0 1       2         3 4  
    Node *entry=new Node(),*parent=temp->parent;
    int i,fel=temp->keys[(N-1)/2];
    for(i=0;i<N;i++)
    {
        entry->keys[i]=0;
        entry->child[i]=NULL;
    }
    entry->child[i+1]=NULL;
    for(i=0;i<(N-1)/2;i++)
    {
        entry->keys[i]=temp->keys[(N+1)/2+i];
        entry->child[i]=temp->child[(N+1)/2+i];
    }
    entry->child[i]=temp->child[(N+1)/2+i];
    entry->no=(N-1)/2;
    for(i=(N-1)/2+1;i<N;i++)
    {
        temp->child[i]=NULL;
        temp->keys[i]=0;
    }
    temp->child[i]=NULL;
    temp->no=(N-1)/2;
    entry->parent=parent;
    temp->parent=parent;
    act(parent,fel,temp,entry);
}
void act(Node *temp,int age,Node *left,Node *right)
{
    int i,j;
    //temp is a node which have to insert age
    //left is left tree of age 
    if(age<=temp->keys[0])
    {
        for(j=temp->no;j>0;j=j-1)
        {
            temp->keys[j]=temp->keys[j-1];
            temp->child[j+1]=temp->child[j];
        }
        temp->child[j]=left;
        temp->child[j+1]=right;
        temp->keys[j]=age;
    }
    else if(age>=temp->keys[temp->no-1])
    {
        temp->keys[temp->no]=age;
        temp->child[temp->no]=left;
        temp->child[temp->no+1]=right;
    }
    else
    {
    for(i=0;i<temp->no-1;i++)
    {
        if(age>=temp->keys[i]&&age<=temp->keys[i+1])
        {
            for(j=temp->no;j>i+1;j=j-1)
            {
                temp->keys[j]=temp->keys[j-1];
                temp->child[j+1]=temp->child[j];
            }
            temp->child[j]=left;
            temp->child[j+1]=right;
            temp->keys[j]=age;
            break;
        }
    }
    }
    temp->no++;
    if(temp->no==N) ins_spilt(temp);
}
Root insert_a(Root r,int age)
{
    Node *temp=r.start;
    int i;
    if(temp==NULL)
    {
        Node *entry=new Node();
        int *arr;
        arr=(int *)malloc(sizeof(int)*N);
        Node **child;
        child=(Node **)malloc(sizeof(Node *)*(N+1));
        entry->keys=arr;
        entry->child=child;
        for(i=0;i<N;i++)
        {
            entry->keys[i]=0;
            entry->child[i]=NULL;
        }
        entry->child[i]=NULL;
        entry->keys[0]=age;
        r.start=entry;
        entry->no=1;
        return r;
    }
    //finds node in which the age should be inserted
    while (temp!=NULL)
    {
        if(age<temp->keys[0])
        {
            if(temp->child[0]!=NULL) temp=temp->child[0];
            else break;
        }
        if(age>temp->keys[temp->no-1])
        {
            if(temp->child[temp->no]!=NULL) temp=temp->child[temp->no];
            else break;
        }
        for(i=0;i<temp->no-1;i++)
        {
            if(age>=temp->keys[i]&&age<=temp->keys[i+1])
            {
                if(temp->child[i]!=NULL) temp=temp->child[i];
                else 
                {
                    act(temp,age,NULL,NULL);
                    return r;  
                }
            }
        }         
    }
    act(temp,age,NULL,NULL);
    return r;
}
bool search_b(Root r,int age)
{
    return false; 
}
Root delete_c(Root r,int age)
{
    return r;
}
int main()
{
    //1 12 8 2 25 6 14 28 17 7 52 16
    //48 68 3 26 29 53 55 45
    Root r;
    r.start=NULL;
    r=insert_a(r,1);
    r=insert_a(r,12);
    r=insert_a(r,8);
    r=insert_a(r,2);
    // r=insert_a(r,25);
    // r=insert_a(r,6);
    // r=insert_a(r,14);
    // r=insert_a(r,28);
    // r=insert_a(r,17);
    // r=insert_a(r,7);
    // r=insert_a(r,52);
    // r=insert_a(r,16);
    // r=insert_a(r,48);
    // r=insert_a(r,68);
    // r=insert_a(r,3);
    // r=insert_a(r,26);
    // r=insert_a(r,29);
    // r=insert_a(r,53);
    // r=insert_a(r,55);
    // r=insert_a(r,45);
    printer(r.start);
    cout<<endl;
    free_mem(r.start);    
    return 0;
}