#include<stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
struct stack
{
    Node start,end;
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
Stack push(Stack s,int a)
{
    Node new=malloc(sizeof(Node));
    new->item=a;
    new->next=s.start;
    s.start=new;
    return s;
}
void freemaker(Stack a,Node additional)
{
    Node temp=a.start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        free(temp->next);
    }
    free(additional);
}
int pop(Stack s)
{
    int temp;
    Node temp2=s.start;
    temp=temp2->item;
    s.start=temp2->next;
    free(temp2);
    printer(s);//inbuilt printer
    return temp;
}

int main()
{
    int a;
    Stack fir;
    fir.start=NULL;
    fir.end =NULL;
    //***********************
    // printf("Enter any number to insert\n");
    // scanf("%d",&a);
    // fir=push(fir,a);
    // scanf("%d",&a);
    // fir=push(fir,a);
    // printer(fir);
    //***********************
    fir=push(fir,100);
    fir=push(fir,210);
    fir=push(fir,330);
    printf("%d\n",pop(fir));
    //***********************
    return 0;
}