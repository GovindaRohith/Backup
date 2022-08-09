#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
struct q
{
    Node start,end;
};
typedef struct q Qu;
struct stat
{
    int *arr;
    int *start,*end;
    int size;
};
typedef struct stat Stat;
void printer(Qu a)
{
    Node temp=a.start;
    while(temp->next!=NULL)
    {
        printf("%d,",temp->item);
        temp=temp->next;
    }
    printf("%d\n",temp->item);
}
Qu insert(int a,Qu s)
{
    Node new=malloc(sizeof(Node));
    new->item=a;
    new->next=NULL;
    if(s.start==NULL)
    {
        s.start=new;
        s.end=new;
    }
    else
    {
        s.end->next=new;
        s.end =new;
    }
    return s;
}
int pop(Qu s)
{
    int temp;
    Node temp2=s.start;
    temp=temp2->item;
    s.start=temp2->next;
    free(temp2);
    printer(s);//inbuilt printer
    return temp;
}
Stat circular(int a,Stat c)
{

    return c;
}
int main()
{
    int a,*arr;
    Qu fir;
    fir.start=NULL;
    fir.end=NULL;
    //*********************
    // printf("Enter any number to insert\n");
    // scanf("%d",&a);
    // fir=insert(a,fir);
    // scanf("%d",&a);
    // fir=insert(a,fir);
    // scanf("%d",&a);
    // fir=insert(a,fir);
    // printer(fir);
    //*********************
    // fir=insert(100,fir);
    // fir=insert(210,fir);
    // fir=insert(310,fir);
    // printf("%d\n",pop(fir));
    //*********************
    Stat init;
    init.arr=NULL;
    init.start=NULL;
    init.end=NULL;
    init.size=0;
    init.arr=(int *)malloc(sizeof(int)*3);
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    init.start=&arr[0];
    init.end=&arr[2];
    printf("Enter any number to insert\n");
    scanf("%d",&a);
    init=circular(a,init);
    //*********************
    return 0;
}