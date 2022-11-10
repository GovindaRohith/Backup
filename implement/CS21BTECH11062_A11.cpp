/*
Code by
Govinda Rohith Y
CS21BTECH11062
Implementation of Binomial heap (Assignment-11)
*/
/*
1.  Each node contains the Age of a faculty.

2.  You should implement  
A.Insert
B.Delete Min
C.Union
*/
#include<iostream>
using namespace std;
class Node
{
    //Class to store each node in Binomial heap
    public:
    int key;
    Node *lchild,*right;
    Node *parent;
    int degree;
};
class Bheap
{
    //Class to store starting node of heap
    public:
    Node *start;
};
void free_mem(Node *temp)
{
    //function to free memory 
    if(temp->lchild!=NULL) free_mem(temp->lchild);
    if(temp->right!=NULL) free_mem(temp->right);
    delete temp;
}
void heap_print(Node *temp)
{
    //function to print elements in each tree in a heap
    //the order of printing is print recursively left most element 
    //and element above and recursively print right sibling
    if(temp->lchild!=NULL) heap_print(temp->lchild);
    cout<<temp->key<<" ";
    if(temp->right!=NULL) heap_print(temp->right);
}
void print_func(Bheap temp)
{
    //function which prints heap_print according to degree
    Node *temp1=temp.start;
    if(temp1==NULL) cout<<"Empty heap try inserting some data"<<endl;
    while(temp1!=NULL)
    {
        cout<<"Degree :"<<temp1->degree<<endl;
        cout<<temp1->key<<" ";
        if(temp1->lchild!=NULL)heap_print(temp1->lchild);
        cout<<endl;
        temp1=temp1->right;
    }
}
Bheap uni(Bheap h,Node *prev,Node *fir,Node *temp)
{
    //function which unions trees untill to 
    //satisfy properties of Binomial heap and returns BHeap
    if(fir->degree!=temp->degree) return h;
    if(fir->key<temp->key)
    {
        temp->right=fir->lchild;
        fir->lchild=temp;
        fir->degree++;
        temp->parent=fir;
        if(prev==NULL) h.start=fir;
        else prev->right=fir;
        if(fir->right!=NULL&&fir->degree==fir->right->degree) return uni(h,prev,fir->right,fir);
    }
    else
    {
        temp->right=fir->right;
        fir->right=temp->lchild;
        temp->lchild=fir;
        fir->parent=temp;
        temp->degree++;
        if(prev==NULL) h.start=temp;
        else prev->right=temp;
        if(temp->right!=NULL&&temp->degree==temp->right->degree) return uni(h,prev,temp->right,temp);
    }
    return h;
}
Bheap union_c(Bheap first,Bheap second)
{
    //Function to return union of two valid Binomial heaps 
    //unions untill a valid tree appears
    //unions first with second
    if(second.start==NULL) return first; //when second heap is empty
    if(first.start==NULL) return second; //when both trees are empty 
    Node *temp1=first.start,*temp2=second.start,*prev=NULL,*right=NULL;
    while(temp2!=NULL) 
    {
        if(temp1==NULL)
        {
            right=temp2->right;
            prev->right=temp2;
            temp2->right=NULL;
            temp2=right;
        }
        else
        {
            if(temp1->degree>temp2->degree)
            {
                right=temp2->right;
                if(prev==NULL) first.start=temp2;
                else prev->right=temp2;
                temp2->right=temp1;
                temp2=right;
            }
            else if(temp1->degree<temp2->degree)
            {
                prev=temp1;
                temp1=temp1->right;
            }
            else
            {
                right=temp2->right;
                first=uni(first,prev,temp1,temp2);
                while(temp1->parent!=NULL)
                {
                    temp1=temp1->parent;
                }
                temp2=right;
            }
        }
    }    
    return first;
}
Bheap insert_a(Bheap temp,int no)
{
    //Inserts a number 'no' into a temproary Bheap and unions with
    //existing temp and returns final heap
    Bheap ins;
    Node *entry = new Node();
    entry->key=no;
    entry->parent=NULL;
    entry->degree=0;
    entry->lchild=NULL;
    entry->right=NULL;
    ins.start=entry;
    if(temp.start==NULL) return ins;
    return union_c(temp,ins);
}
Node * prev_founder(Bheap h,Node *temp)
{
    //function to get left sibling of a node
    Node *temp2=h.start;
    while(temp2!=NULL)
    {
        if(temp2->right==temp) return temp2;
        temp2=temp2->right;
    }
    return NULL;
}
Bheap del_min(Bheap temp)
{
    //Function to find and delete min node and returns a valid heap
    Node *temp1=temp.start,*min=temp1,*prev,*temp2;
    if(temp1==NULL) return temp;
    while(temp1!=NULL)
    {
        if(temp1->key<=min->key) min=temp1;
        temp1=temp1->right;
    }
    prev=prev_founder(temp,min);
    if(prev!=NULL)prev->right=min->right;
    else temp.start=min->right;
    temp2=min->lchild;
    Bheap bt;
    bt.start=NULL;
    while (temp2!=NULL)
    {
        prev=temp2->right;
        bt.start=temp2;
        temp2->parent=NULL;
        temp2->right=NULL;
        //assuming right changes in union function
        temp=union_c(temp,bt);
        temp2=prev;
    }
    delete min;
    return temp;
}
int main()
{
    Bheap h;
    h.start=NULL;
    h=insert_a(h,18);
    h=insert_a(h,3);
    h=insert_a(h,7);
    h=insert_a(h,6);
    h=insert_a(h,8);
    h=insert_a(h,10);
    h=insert_a(h,29);
    h=insert_a(h,44);
    h=insert_a(h,48);
    h=insert_a(h,31);
    h=insert_a(h,17);
    h=insert_a(h,50);
    h=insert_a(h,30);
    h=insert_a(h,23);
    h=insert_a(h,22);
    h=insert_a(h,45);
    h=insert_a(h,32);
    h=insert_a(h,24);
    h=insert_a(h,55);
    Bheap b; //Decalring second heap to test union function
    b.start=NULL;
    b=insert_a(b,25); //Inserting elements in second heap
    b=insert_a(b,75);
    b=insert_a(b,100); 
    h=union_c(h,b); //makes union of h and b and returns to h
    h=del_min(h); 
    h=del_min(h);  
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h);
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h);
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h); 
    h=del_min(h);
    h=del_min(h);
    h=del_min(h); 
    h=del_min(h);
    h=del_min(h);
    print_func(h);
    if(h.start!=NULL)free_mem(h.start); //free allocated memory 
    return 0;
}