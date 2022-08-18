#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *left,*right;
};
typedef struct node *Node;
struct root
{
    Node start;
};
typedef struct root Root;
Root insert(Root r,int n)
{
    
    return r;
}
int main()
{
    Root r;
    r.start=NULL;
    r=insert(r,6);
    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,3);
    r=insert(r,10);
    r=insert(r,1);
    r=insert(r,9);
    r=insert(r,11);
    r=insert(r,7);
    r=insert(r,8);
    r=insert(r,12);

    return 0;
}