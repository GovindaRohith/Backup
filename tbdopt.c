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
    while(temp->pos!=00&&temp->pos!=01)
    {
        temp=temp->left;
    }
    return temp;
}
void printer(Root r)
{
    Node temp=left_search(r.start);
    while(temp!=NULL)
    {
        printf("%d ",temp->item);
        if(temp->pos==01||temp->pos==11)
        {
            temp=left_search(temp->right);
        }
        else 
        {
            temp=temp->right;
        }
    }
}
void verify(Node temp)
{
    if(temp->pos!=00&&temp->pos!=01) verify(temp->left);
    printf("%d ",temp->item);
    if(temp->pos!=00&&temp->pos!=10) verify(temp->right);
}
Root deleter(Root r,Node temp)
{
    Node parent;
    int isleft=1;
    //1 -> left child
    //0 ->right child
    //if  left node 
    //    temp->left ||->left  !=temp  --> parent=temp->right
    //    temp->left ||->right !=temp  -->
    //   temp->right->left ==temp   ->left node
    //right node 
    //    temp->right ||->left !=temp   --> 
    //    temp->right ||->right !=temp  -->parent=temp->left
    //   temp->left->right ==temp   -->right node
    if(temp->pos==00)
    {
        if(temp->left==NULL||temp->right==NULL)
        {
            if(temp->left==NULL)
            {
                isleft=1;
                parent=temp->right;
            } 
            else
            {
                isleft=0;
                parent=temp->left;
            } 
        } 
        else
        {
            if(temp->right->left==temp)
            {
                isleft=1;
                parent=temp->right;
            } 
            if(temp->left->right ==temp)
            {
                isleft=0;
                parent=temp->left;
            } 
        }
        if(isleft==1)
        {
            parent->left=temp->left;
        }
        else
        {
            parent->right=temp->right;
        }
        return r;
    }
    else
    {
        temp->item=temp->right->item;
        return deleter(r,temp->right);
    }
}
Root delete(Root r,int a)
{
    Node temp=r.start;
    int prev;
    while(1>0)
    {
        if(a<temp->item&&temp->pos!=01&&temp->pos!=00)
        {
            temp=temp->left;
        }
        else if(a>temp->item&&temp->pos!=00&&temp->pos!=10)
        {
            temp=temp->right;
        }
        else if(a==temp->item)
        {
            //code here    
            break;
        }
        else
        {
            printf("Element not found!");
            break;
        }
    }
    return r;
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
    printer(r);
    printf("\n");
    verify(r.start);
    printf("\n");
    return 0;
}