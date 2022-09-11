// 1.Each node contains the Age of a faculty. 
// 2.You should implement  
// A.Insert
// B.Search
// C.Delete 
// 3.Take the value of n as five
#include<iostream>
#define N 5;
using namespace std;
class Node
{
    public:
    int no;
    // no of keys in Node
    int *keys;
    Node **child;
    Node *parent;
};  
class Root
{
    public :
    Node *start;
};
void act(Node *temp,int age)
{
    //temp is a node which have to insert age
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