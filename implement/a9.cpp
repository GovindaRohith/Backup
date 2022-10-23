// 1.Each node contains the Age of a faculty. 
// 2.You should implement  
// A.Insert
// B.Search
// C.Delete 
// 3.Take the value of n as five
#include<iostream>
#include<stdlib.h>
// #define N 5;
using namespace std;
int N=5;
class Node
{
    public:
    int no;
    // no of keys in Node
    int *keys; //array of keys
    Node **child; //array of child nodes
    Node *parent; //array of parent NODE
};  
class Root
{
    public :
    Node *start;
};
Root act(Root r,Node *temp,int age,Node *left,Node *right);
void printer(Node *temp)
{
    int i;
    if(temp!=NULL) //change this condition here due to multiple checks
    {
    for(i=0;i<temp->no;i++)
    {
        if(temp->child[i]!=NULL)
        {
            printer(temp->child[i]);
        }
        cout<<temp->keys[i]<<" ";
    }
    if(temp->child[i]!=NULL)
    {
        printer(temp->child[i]);
    }
    }
    else
    {
        cout<<"Empty tree try to insert some data"<<endl;
    }
}
Node * creator()
{
    Node *entry=new Node();
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*N);
    Node **child;
    child=(Node **)malloc(sizeof(Node *)*(N+1));
    entry->keys=arr;
    entry->child=child;
    for(i=0;i<N;i++)
    {
        entry->keys[i]=0;
        entry->child[i]=NULL;
    }
    entry->child[i]=NULL;
    return entry;
}
void destroyer(Node *temp)
{
    free(temp->keys);
    free(temp->child);
    delete temp;
}
void free_mem(Node *temp)
{
    int i;
    if(temp!=NULL)
    {
    free(temp->keys);
    for(i=0;i<temp->no;i++)
    {
        if(temp->child[i]!=NULL)
        {
            free_mem(temp->child[i]);
        }
    }
    if(temp->child[i]!=NULL)
    {
        free_mem(temp->child[i]);
    }
    free(temp->child);
    delete temp;
    }
}
Root ins_spilt(Root r,Node *temp)
{
    //0 1       2         3 4  
    //left taken by temp and right taken by entry
    Node *entry,*parent=temp->parent;
    int i,fel=temp->keys[(N-1)/2];
    entry=creator();
    for(i=0;i<(N-1)/2;i++)
    {
        entry->keys[i]=temp->keys[(N+1)/2+i];
        entry->child[i]=temp->child[(N+1)/2+i];
    }
    entry->child[i]=temp->child[(N+1)/2+i];
    entry->no=(N-1)/2;
    for(i=(N-1)/2+1;i<N;i++)
    {
        temp->child[i]=NULL;
        temp->keys[i]=0;
    }
    temp->child[i]=NULL;
    temp->keys[(N-1)/2]=0;
    temp->no=(N-1)/2;
    entry->parent=parent; //mistake here
    temp->parent=parent;
    for(i=0;i<=entry->no;i++)
    {
        if(entry->child[i]!=NULL) entry->child[i]->parent=entry;
        else break;
    }
    return act(r,parent,fel,temp,entry);
}
Root act(Root r,Node *temp,int age,Node *left,Node *right)
{
    int i,j;
    //temp is a node which have to insert age
    //left is left tree of age 
    if(temp==NULL)
    {
        Node *entry;
        entry=creator();
        entry->no=1;
        entry->keys[0]=age;
        entry->child[0]=left;
        entry->child[1]=right;
        if(left!=NULL)entry->child[0]->parent=entry;
        if(right!=NULL)entry->child[1]->parent=entry;
        r.start=entry;
        return r;
    }
    else
    {
    if(age<=temp->keys[0])
    {
        for(j=temp->no;j>0;j=j-1)
        {
            temp->keys[j]=temp->keys[j-1];
            temp->child[j+1]=temp->child[j];
        }
        temp->child[j]=left;
        temp->child[j+1]=right;
        temp->keys[j]=age;
        if(left!=NULL)temp->child[temp->no]->parent=temp;
        if(right!=NULL)temp->child[temp->no+1]->parent=temp;
    }
    else if(age>=temp->keys[temp->no-1])
    {
        temp->keys[temp->no]=age;
        temp->child[temp->no]=left;
        temp->child[temp->no+1]=right;
        if(left!=NULL)temp->child[temp->no]->parent=temp;
        if(right!=NULL)temp->child[temp->no+1]->parent=temp;
    }
    else
    {
    for(i=0;i<temp->no-1;i++)
    {
        if(age>=temp->keys[i]&&age<=temp->keys[i+1])
        {
            for(j=temp->no;j>i+1;j=j-1)
            {
                temp->keys[j]=temp->keys[j-1];
                temp->child[j+1]=temp->child[j];
            }
            temp->child[j]=left;
            temp->child[j+1]=right;
            temp->keys[j]=age;
            break;
        }
    }
    }
    temp->no++;
    if(temp->no==N) return ins_spilt(r,temp);
    return r;
    }
}
Root insert_a(Root r,int age)
{
    Node *temp=r.start;
    int i;
    if(temp==NULL)
    {
        Node *entry;
        entry=creator();
        entry->keys[0]=age;
        r.start=entry;
        entry->no=1;
        return r;
    }
    //finds node in which the age should be inserted
    while (temp!=NULL)
    {
        if(age<temp->keys[0])
        {
            if(temp->child[0]!=NULL) temp=temp->child[0];
            else break;
        }
        if(age>temp->keys[temp->no-1])
        {
            if(temp->child[temp->no]!=NULL) temp=temp->child[temp->no];
            else break;
        }
        for(i=0;i<temp->no-1;i++)
        {
            if(age>=temp->keys[i]&&age<=temp->keys[i+1])
            {    
                if(temp->child[i+1]!=NULL) temp=temp->child[i+1];
                else 
                {
                    return act(r,temp,age,NULL,NULL);
                }
            }
        }         
    }
    // cout<<age<<"Before"<<temp->keys[0]<<endl;
    return act(r,temp,age,NULL,NULL);
}
bool search_b(Root r,int age)
{
    Node *temp=r.start;
    int i;
    if(temp==NULL)
    {
        cout<<"Empty tree try to insert some data"<<endl;
        return false;
    }
    while(temp!=NULL)
    {
        if(age<temp->keys[0]) temp=temp->child[0];
        if(age>temp->keys[temp->no-1]) temp=temp->child[temp->no];
        else
        {
            for(i=0;i<temp->no;i++)
            {
                if(age==temp->keys[i])
                {
                    cout<<"Found date with age  "<<age<<endl;
                    return true;
                } 
                if(age>temp->keys[i]&&age<temp->keys[i+1])
                {
                    temp=temp->child[i+1];
                    break;
                }
            }
        }
    }
    cout<<"Not found entry with given age"<<endl;
    return false;
}
Node * insucc(Node *temp,int index)
{
    //returns NULL if no inorder successor is present
    //index represents the index of age in temp node
    Node *req=NULL;
    temp=temp->child[index+1];
    while(temp!=NULL)
    {
        req=temp;
        temp=temp->child[0];
    }
    return req;
}
Node * inpre(Node *temp,int index)
{
    //returns NULL if no inorder predecessor is present
    //index represents the index of age in temp node
    Node *req=NULL;
    temp=temp->child[index];
    while(temp!=NULL)
    {
        req=temp;
        temp=temp->child[temp->no];
    }
    return req;
}
Node * left_founder(Node *temp)
{
    int i;
    Node *parent=temp->parent;
    for(i=0;i<=parent->no;i++)
    {
        if(parent->child[i]==temp) break;
    }
    if(i==0) return NULL;
    else return parent->child[i-1];
}
Node * right_founder(Node *temp)
{
    int i;
    Node *parent=temp->parent;
    for(i=0;i<=parent->no;i++)
    {
        if(parent->child[i]==temp) break;
    }
    if(i==parent->no)   return NULL;
    else return parent->child[i+1];
}
Root merge(Root r,Node *left,Node *temp,Node *right)
{
    //index=-1 just merge no need for delete
    //any other delete element in that index of temp
    //     parent
    // left and right  and merge untill proper trees arrives
    //      parent
    //  fir        sec  --> fir parent sec 
    Node *parent=temp->parent;
    int i; 
    if(left!=NULL)
    {
        int conc=0,iso;
        for(i=0;i<parent->no;i++)
        {
            if(parent->child[i]==left&&parent->child[i+1]==temp)
            {
                conc=i;
                break;
            }
        }
        iso=parent->keys[conc];
        for(i=conc;i<parent->no-1;i++)
        {
            parent->keys[i]=parent->keys[i+1];
            parent->child[i+1]=parent->child[i+2];
        }
        parent->keys[i]=0; 
        parent->child[i+1]=NULL;
        parent->no=parent->no-1;
        //parent assignment done here
        left->keys[left->no]=iso;
        left->no++;
        for(i=0;i<temp->no;i++)
        {
            left->keys[i+left->no]=temp->keys[i];
            left->child[i+left->no]=temp->child[i];
            if(left->child[i+left->no]!=NULL)left->child[i+left->no]->parent=left;
        }
        left->child[i+left->no]=temp->child[i+left->no];
        if(left->child[i+left->no]!=NULL)left->child[i+left->no]->parent=left;
        left->no=left->no+temp->no;
        //left totally assigned complete!!!
        destroyer(temp);
        if(parent->no==0)
        {
            destroyer(parent);
            r.start=left;
            left->parent=NULL;
            return r;
        }   
    }
    else if(right!=NULL)
    {

    }
    else
    {
        //left and right are not there
    }
    if(parent->no<(N-1)/2)
    {
        return merge(r,left_founder(parent),parent,right_founder(parent));
        //siblings conditions here
    } 
    return r;
}
Root case_sep(Root r,Node *temp,int index)
{
    //assume leaf only comes here
    //pairin to be deleted number is greater then parent[pairin]
    int nright=0,nleft=0,i,pairin=0;
    Node *right=NULL,*left=NULL,*parent=temp->parent;
    if(parent==NULL)
    {
        //internal node case here swapping
        cout<<"Swapping here"<<endl;
        return r;
    }
    for(i=0;i<parent->no;i++)
    {
        if(temp->keys[index]<=parent->keys[i]) break;
    }
    if(i==0)
    {
        left=NULL;
        //pairin not needed
        right=parent->child[1];
    }
    else if(i==parent->no)
    {
        right=NULL;
        left=parent->child[parent->no];
    }
    else
    {
        pairin=i-1;
        left=parent->child[i-1];
        right=parent->child[i+1];
    }
    if(left!=NULL) nleft=left->no;
    if(right!=NULL) nright=right->no;
    if(temp->child[index]!=NULL||temp->child[index+1]!=NULL)
    {
        //test for more than one swappings
        //internal node case
        Node *temp2;
        while(temp->child[index]!=NULL||temp->child[index+1]!=NULL)
        {
            if(temp->child[index+1]!=NULL)
            {
                temp2=insucc(temp,index);
                i=temp->keys[index];
                temp->keys[index]=temp2->keys[0];
                temp2->keys[0]=i;
                index=0;
                temp=temp2;
            }
            else
            {
                temp=inpre(temp,index);
                i=temp->keys[index];
                temp->keys[index]=temp2->keys[temp2->no-1];
                temp2->keys[temp2->no-1]=i;
                index=temp2->no-1;
                temp=temp2;
            }
        }
        return case_sep(r,temp,index);
    }
    else if (temp->no>=(N+1)/2)
    {
        //leaf with enough keys
        for(i=index;i<temp->no-1;i++)
        {
            temp->keys[i]=temp->keys[i+1];
        }
        temp->no=temp->no-1;
        return r;
    }
    else if(nleft>=(N+1)/2)
    {
        //left sibling have more 
        for(i=temp->no;i>0;i=i-1)
        {
            temp->keys[i]=temp->keys[i-1];
            temp->child[i+1]=temp->child[i];
        }
        temp->no++;
        temp->keys[0]=parent->keys[pairin];
        temp->child[0]=left->child[left->no];
        if(temp->child[0]!=NULL)temp->child[0]->parent=temp;
        parent->keys[pairin]=left->keys[left->no-1];
        left->keys[left->no-1]=0;
        left->child[left->no]=NULL;
        left->no=left->no-1;
        return case_sep(r,temp,index+1);
    }
    else if(nright>=(N+1)/2)
    {
        //right sibling have more
        temp->keys[temp->no]=parent->keys[pairin+1];
        temp->no++;
        temp->child[temp->no]=right->child[0];
        if(temp->child[temp->no]!=NULL) temp->child[temp->no]->parent=temp;
        parent->keys[pairin+1]=right->keys[0];
        for(i=0;i<right->no;i++)
        {
            right->keys[i]=right->keys[i+1];
            right->child[i]=right->child[i+1];
        }
        right->child[i+1]=NULL;
        right->no=right->no-1;
        right->keys[right->no]=0;
        return case_sep(r,temp,index);
    }
    else if(nleft<=(N-1)/2&&nright<=(N-1)/2)
    {
        for(i=index;i<temp->no-1;i++)
        {
            temp->keys[i]=temp->keys[i+1];
            temp->child[i]=temp->child[i+1];
        }
        temp->child[i]=temp->child[i+1];
        temp->keys[i]=0;
        temp->child[i+1]=NULL;
        temp->no=temp->no-1; //deletes req node
        return merge(r,left,temp,right);
    }
    else 
    {
        cout<<"Other if there...."<<endl;
        return r;
    }
    return r;
}
Root delete_c(Root r,int age)
{
    Node *temp=r.start;
    int i;
    if(temp==NULL)
    {
        cout<<"Empty tree try to insert some data"<<endl;
        return r;
    }
    while(temp!=NULL)
    {
        if(age<temp->keys[0]) temp=temp->child[0];
        if(age>temp->keys[temp->no-1]) temp=temp->child[temp->no];
        else
        {
            for(i=0;i<temp->no;i++)
            {
                if(age==temp->keys[i])
                {
                    return case_sep(r,temp,i);
                } 
                if(age>temp->keys[i]&&age<temp->keys[i+1])
                {
                    temp=temp->child[i+1];
                    break;
                }
            }
        }
    }
    cout<<"Not found entry with given age"<<endl;
    return r;
}
int main()
{
    //1 12 8 2 25 6 14 28 17 7 52 16
    //48 68 3 26 29 53 55 45
    Root r;
    r.start=NULL;
    r=insert_a(r,1);
    r=insert_a(r,12);
    r=insert_a(r,8);
    r=insert_a(r,2);
    r=insert_a(r,25);       
    r=insert_a(r,6);
    r=insert_a(r,14);
    r=insert_a(r,28); 
    r=insert_a(r,17);
    r=insert_a(r,7);
    r=insert_a(r,52);
    r=insert_a(r,16);
    r=insert_a(r,48);
    r=insert_a(r,68);
    r=insert_a(r,3);
    r=insert_a(r,26);
    r=insert_a(r,29);
    r=insert_a(r,53);
    r=insert_a(r,55);
    r=insert_a(r,45); 
    r=delete_c(r,7);
    r=delete_c(r,8);
    r=delete_c(r,48); 
    printer(r.start);
    cout<<endl;
    // search_b(r,17);
    free_mem(r.start);    
    return 0;
}