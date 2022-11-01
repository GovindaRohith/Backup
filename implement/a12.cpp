// Implementation of skipped list
//  1.Each node contains the Age, Name, Gender, and Department of
//  a faculty. Assume the Name is unique
//  2.You should implement
//  A.Insert
//  B.Delete by Name
//  C.Search by Name
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Node
{
public:
    int age;
    // string name,gender,dept; //NOTE change here for assign
    Node *left, *right, *top, *bottom;
};
class Unode
{
public:
    Node *curhead;
    Unode *prev, *next;
};
class Collection
{
    public:
    Unode *start; // start represents first linked list which
    // of only -inf +inf
};
bool coin()
{
    // true for even for head returns 1
    // false for odd for tail returns 0
    if (rand() % 2 == 0) return true;
    else return false;
}
void llprint(Node *head)
{
    Node *temp = head;
    cout << "-inf ";
    temp = temp->right;
    while (temp->right != NULL)
    {
        cout << temp->age << " ";
        temp = temp->right;
    }
    cout << "+inf" << endl;
}
void printer(Collection c)
{
    int i;
    Unode *temp = c.start;
    for (i = 0; temp != NULL; i++)
    {
        cout << "Linked list number " << i + 1 << ":  ";
        llprint(temp->curhead);
        temp = temp->next;
    }
}
Node *llcreate()
{
    // creats a linked lists with -inf and +inf
    Node *entry = new Node();
    Node *entry1 = new Node();
    entry->age = -1;   //-inf value
    entry1->age = 100; //+inf values
    entry->right = entry1;
    entry->left = NULL;
    entry->top = NULL;
    entry->bottom = NULL;
    entry1->right = NULL;
    entry1->left = entry;
    entry1->top = NULL;
    entry1->bottom = NULL;
    return entry;
}
void ddl_insert(Node *entry,Node *temp)
{
    //entry && temp in order
    entry->left = temp->left;
    temp->left->right = entry;
    entry->right = temp;
    temp->left = entry;
}
Collection create(Collection c)
{
    // creates a collection with single ll -inf to + inf
    Unode *entry = new Unode();
    entry->curhead = llcreate();
    entry->next = NULL;
    entry->prev = NULL;
    c.start = entry;
    return c;
}
void free_mem(Collection c)
{
    Unode *utemp = c.start, *utemp2;
    Node *temp, *temp2;
    while (utemp != NULL)
    {
        temp = utemp->curhead;
        while (temp != NULL)
        {
            temp2 = temp;
            temp = temp->right;
            delete temp2;
        }
        utemp2 = utemp;
        utemp = utemp->next;
        delete utemp2;
    }
}
Collection ins_coin(Collection c, Node *temp)
{
    // temp obtained after insetion of age(which contains age)
    Unode *utemp = c.start;
    Node *temp2;
    while (utemp->next != NULL)
    {
        utemp = utemp->next;
    }
    while (coin() == 1 && utemp != NULL)
    {
        Node *entry = new Node();
        entry->age = temp->age;
        entry->bottom = temp;
        entry->top = NULL;
        temp->top = entry;
        temp2 = temp->right;
        while (temp2!=NULL&&temp2->top == NULL)
        {
            temp2 = temp2->right;
        }
        temp2 = temp2->top;
        // cout<<temp2->left->age<<endl;
        ddl_insert(entry, temp2);
        utemp = utemp->prev;
        temp = entry;
    }
    if (utemp==NULL||utemp->prev == NULL)
    {
        //create an empty linked list case
        Unode *old = c.start;
        Unode *uentry = new Unode();
        uentry->curhead = llcreate();
        uentry->next = old;
        uentry->prev = NULL;
        old->prev=uentry;
        old->curhead->top = uentry->curhead;
        temp2 = old->curhead->right; // temp2 represents +inf from old node
        while (temp2->right != NULL)
        {
            temp2 = temp2->right;
        }
        temp2->top = uentry->curhead->right;
        uentry->curhead->bottom = old->curhead;
        uentry->curhead->right->bottom = temp2;
        c.start = uentry;
    }
    return c;
}
Collection insert_a(Collection c, int age)
{
    // x = y: we return element(after(p))
    // x > y: we “scan forward”
    // x < y: we “drop down”
    Unode *utemp = c.start;
    Node *temp;
    Node *entry = new Node();
    entry->age = age;
    entry->bottom = NULL;
    entry->top = NULL;
    entry->left = NULL;
    entry->right = NULL;
    if (utemp->next == NULL)
    {
        // temp1  ->entry1(head)
        // utemp  ->conatins entry
        Node *entry1;
        entry1 = llcreate();
        Unode *temp1 = new Unode(); // newly generated linked list upside
        temp1->curhead = entry1;
        temp1->next = utemp;
        temp1->prev = NULL; // assign next for utemp
        utemp->next = NULL;
        utemp->prev = temp1;
        temp1->curhead->bottom = utemp->curhead;
        utemp->curhead->top = temp1->curhead;
        temp1->curhead->right->bottom = utemp->curhead->right;
        utemp->curhead->right->top = temp1->curhead->right;
        entry->right = utemp->curhead->right;
        entry->left = utemp->curhead;
        utemp->curhead->right->left = entry;
        utemp->curhead->right = entry;
        c.start = temp1;
        // return c;
        return ins_coin(c, entry);
    }
    while (utemp != NULL) // check again
    {
        temp = utemp->curhead;
        // entry=ddl_insert(entry,temp);
        // return ins_coin(c,entry);
        while (temp != NULL)
        {
            if (age < temp->age || (temp->right != NULL && temp->right->right == NULL&&temp->right->left->left==NULL))
            {
                if (temp->bottom == NULL)
                {
                    if(age<temp->age&&age>temp->left->age)
                    {
                        ddl_insert(entry,temp);
                        return ins_coin(c, entry);
                    }
                    else temp=temp->left;
                }
                else temp = temp->bottom;
            }
            else if (age > temp->age)
            {
                temp=temp->right;
            }
            else if (age == temp->age)
            {
                cout << "Invalid entry already exists with give name" << endl;
                return c;
            }
            else
            {
                //Just kept for syntax formation IGNORE
            }
        }
        utemp = utemp->next;
    }
    return c;
}
Node *search_c(Collection c,int age,bool isDel)
{
    //bool isDel is only to display "Deleted successfully"
    //as the delete function also uses the search function
    //So for regular search the third argument should be zero
    //return NULL if not present
    // else return node which contains
    Unode *utemp = c.start;
    Node *temp;
    while (utemp != NULL) // check again
    {
        temp = utemp->curhead;
        while (temp != NULL)
        {
            if (age < temp->age || (temp->right != NULL && temp->right->right == NULL&&temp->left==NULL))
            {
                if (temp->bottom == NULL)
                {
                    if(age<temp->age&&age>temp->left->age)
                    {
                        cout<<"Not Found with given name"<<endl;
                        return NULL;
                    }
                    else temp=temp->left;
                }
                else temp = temp->bottom;
            }
            else if (age > temp->age)
            {
                temp=temp->right;
            }
            else if (age == temp->age)
            {
                if(isDel)cout<<"*** Deleted Successfully ***"<<endl;
                else cout << "Found with given name"<< endl;
                return temp;
            }
            else
            {
                //Just kept for syntax formation IGNORE
            }
        }
        utemp = utemp->next;
    }
    cout<<"Not found"<<endl;
    return NULL;
}
Node *ddl_delete(Node *entry)
{
    //if bottom exists return that else return NULL
    Node *temp=entry->top;
    entry->left->right=entry->right;
    entry->right->left=entry->left;
    delete entry;
    if(temp!=NULL) return temp;
    return NULL;
}
Collection delete_b(Collection c, int age)
{
    Node *temp=search_c(c,age,1);
    if(temp==NULL) return c;
    while(temp->bottom!=NULL)
    {
        temp=temp->bottom;
    }
    while(temp!=NULL)
    {
        temp=ddl_delete(temp);
    }
    while(c.start->next!=NULL&&c.start->next->curhead->right->right==NULL)
    {
        delete c.start->curhead->right;
        delete c.start->curhead;
        Unode *utemp=c.start;
        c.start=c.start->next;
        delete utemp;
    }
    return c;
}
int main()
{
    Collection c = create(c);
    c=insert_a(c,26);
    c=insert_a(c,12);
    c=insert_a(c,34);
    c=insert_a(c,56);
    c=insert_a(c,64);
    c=insert_a(c,78);
    c=insert_a(c,23);
    c=insert_a(c,31);
    c=insert_a(c,44);
    Node *temp;
    temp=search_c(c,78,0); //for searching make the third argument 0
    c=delete_b(c,26);
    c=delete_b(c,12);
    c=delete_b(c,34);
    c=delete_b(c,56);
    c=delete_b(c,64);
    c=delete_b(c,78);
    c=delete_b(c,23);
    c=delete_b(c,31);
    c=delete_b(c,44);
    printer(c);
    free_mem(c);
    return 0;
}