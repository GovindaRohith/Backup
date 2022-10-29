//Implementation of skipped list
// 1.Each node contains the Age, Name, Gender, and Department of 
// a faculty. Assume the Name is unique
// 2.You should implement
// A.Insert
// B.Delete by Name
// C.Search by Name
#include<iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
class Node
{
    public:
    int age;
    // string name,gender,dept; //NOTE change here for assign
    Node *left,*right,*top,*bottom;
};
class Unode
{
    public:
    Node *curhead;
    Unode *prev,*next;
};
class Collection
{
    public:
    int height;// no of linked lists
    Unode *start,*end;
};
bool coin()
{
    //true for even
    //false for odd
    // srand(time(0)); //UNCOMMENT HERE
    if(rand()%2==0) return true;
    return false;
}
void llp(Node *head)
{
    Node *temp=head;
    cout<<"-inf"<<endl;
    temp=temp->right;
    while(temp->right!=NULL)
    {
        cout<<temp->age<<endl;
        temp=temp->right;
    }
    cout<<"+inf"<<endl;
    cout<<endl;
}
void printer(Collection c)
{
    int i;
    Unode *temp=c.start;
    for(i=0;i<c.height&&temp!=NULL;i++)
    {
        llp(temp->curhead);
        cout<<endl;
        temp=temp->next;
    }
}
Collection insert_a(Collection c,int age)
{

    return c;
}
Node* search_c(Collection c,string name)
{
    //return NULL if not present
    //else return node which contains
    return NULL;
}
Collection delete_b(Collection c,string name)
{
    return c;
}
int main()
{
    //12 23 26 31 34 44 56 64 78
    Collection c;
    c.start=NULL;
    c.end =NULL;
    c.height=0;
    c=insert_a(c,26);
    c=insert_a(c,12);
    c=insert_a(c,34);
    c=insert_a(c,56);
    c=insert_a(c,64);
    c=insert_a(c,78);
    c=insert_a(c,23);
    c=insert_a(c,31);
    c=insert_a(c,44);
    printer(c);
    return 0;
}