#include<stdlib.h>
#include<stdio.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
struct store
{
 Node start;
};
typedef struct store Store;
void printer(Store a)
{
    Node temp=a.start;
    while(temp->next!=NULL)
    {
        printf("%d,",temp->item);
        temp=temp->next;
    }
    printf("%d\n",temp->item);
}
void freemaker(Store a,Node additional)
{
    Node temp=a.start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        free(temp->next);
    }
    free(additional);
}
Store insert(Store s,int a)
{
    Node new=malloc(sizeof(Node));
    new->item=a;
    new->next=s.start;
    s.start=new;
    return s;
}
int search(Store pre,int a)
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
Store del(Store giv,int a)
{
    Node prev,post;
    prev=giv.start;
    if(prev==NULL) return giv;
    else if(prev->item==a)
    {
        giv.start=prev->next;
        free(prev);
        return giv;
    }
    else
    {
        post=prev->next;
        while(post!=NULL)
        {
            if(post->item==a)
            {
                Node temp;
                temp=post;
                prev->next=post->next;
                post=post->next;
                free(temp);
            }
            else
            {
                prev=post;
                post=post->next;
            }
        }
    }
    return giv; 
}
int main()
{
    int a;
    Store temp;
    temp.start=NULL;
    //***************** 
    // printf("Enter any number to insert\n");
    // while (scanf("%d",&a)!=-1)
    // {
    //     temp=insert(temp,a);
    //     printer(temp);
    // }
    //*****************

    //*****************
    // temp=insert(temp,100);
    // temp=insert(temp,321);
    // temp=insert(temp,296);
    // printf("Enter any number for searching\n");
    // scanf("%d",&a);
    // printf("%d\n",search(temp,a));
    //*****************
    // 895    
    //296
    //321
    //100
    //*****************
    temp=insert(temp,100);
    temp=insert(temp,321);
    temp=insert(temp,296);
    temp=insert(temp,895);
    printf("Enter any number for deleting\n");
    scanf("%d",&a);
    temp=del(temp,a);
    printer(temp);
    //*****************

    // freemaker(temp,init);
    return 0;
}