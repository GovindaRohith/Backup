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
typedef struct root *Root;
Root insert(Root e,int n)
{
    
}
int main()
{
    int n;
    Root r;
    r->start=NULL;
    printf("Enter any number to insert\n");
    while(scanf("%d",&n)!=-1)
    {
        r=insert(r,n);
        printf("Enter any number to insert\n");
    }
    return 0;
}