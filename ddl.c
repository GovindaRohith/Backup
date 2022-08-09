#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node * next,*prev;
};
typedef struct node *Node;
struct stack
{
    Node start;
    int tune;
};
typedef struct stack Stack;
void printer(Stack a)
{
    Node temp=a.start;
    while(temp->next!=NULL)
    {
        printf("%d,",temp->item);
        temp=temp->next;
    }
    printf("%d\n",temp->item);
}
Stack insert(Stack s,int a,int pos,int tune)
{
    Node temp=s.start;
    int counter=0;
    Node new=malloc(sizeof(Node));
    new->item=a;
    if(pos==1)
    {
        new->next=s.start;
        new->prev=NULL;
        if(s.start!=NULL)
        {
        s.start->prev=new;
        }
        s.start=new;
        return s;
    }
    while(temp!=NULL)
    {
        counter++;
        if(counter==pos-1)
        {
            new->prev=temp;
            new->next=temp->next;
            if(new->next!=NULL)
            {
            temp->next->prev=new;
            }
            temp->next=new;
            temp=new;
            break;
        }
        else  temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Not valid\n");
        s.tune=1;
    }
    return s;
}
int search(Stack pre,int a)
{
    Node temp=pre.start;
    while(temp->next!=NULL)
    {
        if(temp->item==a) return 1;
        temp=temp->next;
    }
    if(temp->item==a) return 1;
    return 0;
}
Stack del(Stack giv,int a)
{
    Node pre,post;
    pre=giv.start;
    if(pre==NULL) return giv;
    else if(pre->item==a)
    {
        giv.start=pre->next;
        pre->next->prev=NULL;
        free(pre);
        return giv;
    }
    else
    {
        post=pre->next;
        while(post!=NULL)
        {
            if(post->item==a)
            {
                Node temp;
                temp=post;
                pre->next=post->next;
                post=post->next;
                post->prev=pre;
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
    int n,pos;
    Stack s;
    s.start=NULL;
    printf("Enter any number to insert and position number\n");
    while (scanf("%d%d",&n,&pos)!=-1)
    {
        s=insert(s,n,pos,0);
        if(s.tune==1)
        {
            break;
        }
        printer(s);    
        printf("Enter any number to insert and position number\n");
    }
    printf("seraching gives %d\n",search(s,n));
    del(s,n);
    printer(s);
    return 0;
}