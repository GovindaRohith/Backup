// 1.Each node contains the Age of a faculty. 
// 2.You should implement  
// A.Insert
// B.Search
// C.Delete 
// 3.Take the value of n as five
#include<iostream>
// #define N 5;
using namespace std;
int N=5;
class Node
{
    public:
    int no;
    // no of keys in Node
    int *keys=NULL;
    Node **child=NULL;
    Node *parent=NULL;
};  
class Root
{
    public :
    Node *start;
};
void act(Node *temp,int age);
void ins_spilt(Node *temp)
{
    //0 1       2         3 4  
    int i,j,age=temp->keys[(N+1)/2+i];
    Node *parent=temp->parent,*entry=new Node();
    for(i=0;i<(N-1)/2;i++)
    {
        entry->keys[i]=temp->keys[(N+1)/2+i];
    }
    temp->no=temp->no-(N-1)/2;
    entry->no=(N-1)/2;
    entry->parent=temp->parent;
    //
    for(i=0;i<parent->no-1;i++)
    {
        if(age>=parent->keys[i]&&age<=parent->keys[i+1])
        {
            for(j=parent->no;j>i+1;j=j-1)
            {
                //equality check
                parent->child[j]=parent->child[j-1];
            }
            parent->child[j]=temp;
            parent->child[j+1]=entry;
        }
    }
    //
    act(temp->parent,temp->keys[(N-1)/2]);
}
void act(Node *temp,int age)
{
    int i,j;
    //temp is a node which have to insert age
    for(i=0;i<temp->no-1;i++)
    {
        if(age>=temp->keys[i]&&age<=temp->keys[i+1])
        {
            for(j=temp->no;j>i+1;j=j-1)
            {
                //equality check
                temp->keys[j]=temp->keys[j-1];
            }
            temp->keys[j]=age;
            
        }
    }
    temp->no++;
    if(temp->no==N) ins_spilt(temp);
}
Root insert_a(Root r,int age)
{
    Node *temp=r.start;
    int i;
    //arr
    while (temp!=NULL)
    {
        for(i=0;i<temp->no-1;i++)
        {
            if(age>=temp->keys[i]&&age<=temp->keys[i+1])
            {
                if(temp->child[i]!=NULL) temp=temp->child[i];
                else break;
            }
        }
        if(age<temp->keys[0])
        {
            if(temp->child[0]!=NULL) temp=temp->child[0];
            else break;
        } 
        else
        {
            if(temp->child[temp->no]!=NULL) temp=temp->child[temp->no];
            else break;
        }
    }
    act(temp,age);
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

    return 0;
}