#include<stdio.h>
#include<stdlib.h>
//1 1 -->l and r present
//0 1 -->r only present
//1 0 -->l only present
//0 0 -->leaf 
struct node
{
    int item;
    unsigned short int pos;
    struct node *left,*right;
};
typedef struct node *Node;
struct root
{
    Node start;
};
typedef struct root Root;
Node left_search(Node temp)
{
    while(temp->pos!=00)
    {
        temp=temp->left;
    }
    return temp;
}
void printer(Root r)
{
    while()
    {
        
    }
}
Root insert(Root r,int n)
{
    Node new=malloc(sizeof(Node));
    new->item=n;
    new->pos=00;
    if(r.start==NULL)
    {
        new->right=NULL;
        new->left=NULL;
        r.start=new;
    }
    else
    {
        Node temp=r.start;
        //parent pos change
        while(temp!=NULL)
        {
            //propagation steps
            if(n>temp->item&&(temp->pos==11||temp->pos==01)) temp=temp->right;
            else if(n>temp->item&&(temp->pos==00||temp->pos==10))
            {
                new->right=temp->right;
                temp->right=new;
                if(temp->pos==00)
                {
                    new->left=temp;
                    temp->pos=01;
                }
                else 
                {
                    new->left=temp->left;
                    temp->pos=11;
                }
                break;
            }
            //propagation steps
            else if(n<temp->item&&(temp->pos==11||temp->pos==10)) temp=temp->left;
            else 
            {
                //n<temp->item &&(temp->pos==01||temp->pos==00)
                if(temp->pos==01) 
                {
                    new->left=temp->left;
                    temp->pos=11;
                } 
                else  
                {
                    new->left=NULL;
                    temp->pos=10;
                }
                temp->left=new;
                new->right=temp;
                break;
            }
        }
    }
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