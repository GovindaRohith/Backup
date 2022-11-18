/*
Code By
Govinda Rohith Y
CS21BTECH11062
Implementation of skip lists (Assignment-12)
*/
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
    //class to store indivdual node
    public:
    int age;
    string name,gender,dept; 
    Node *left, *right, *top, *bottom;
};
class Unode
{
    //class to store heads of linked lists
    public:
    Node *curhead;
    Unode *prev, *next;
};
class Collection
{
    //class to store head of linked lists
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
    //function to print each linked list
    Node *temp = head;
    if(head->left==NULL&&head->right->right==NULL)cout << "-inf ";
    else cout<<"-inf"<<endl;
    temp = temp->right;
    while (temp->right != NULL)
    {
        cout<<"******************"<<endl;
        cout <<"Name      :"<< temp->name<<endl;
        cout <<"Gender    :"<< temp->gender<<endl;
        cout <<"Department:"<< temp->dept<<endl;
        cout <<"Age       :"<< temp->age<<endl;
        cout<<"******************"<<endl;
        temp = temp->right;
    }
    cout << "+inf" << endl;
}
void printer(Collection c)
{
    //function to print whole collection(Skip list)
    int i;
    Unode *temp = c.start;
    for (i = 0; temp != NULL; i++)
    {
        cout << "Linked list number " << i + 1 << ":  "<<endl;
        llprint(temp->curhead);
        temp = temp->next;
    }
}
Node *llcreate()
{
    // creats a linked lists with -inf and +inf
    Node *entry = new Node();
    Node *entry1 = new Node();
    entry->name ="A";   //-inf value
    entry1->name = "zzzzzzzzzzzz"; //+inf values
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
    //standard insertion to double linked list
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
    //function which inserts the node according to alogorithm and returns the collection
    // temp obtained after insetion of age(which contains age)
    Unode *utemp = c.start;
    Node *temp2;
    while (utemp->next != NULL)
    {
        utemp = utemp->next;
    }
    while (coin() == 1 && utemp != NULL&&utemp->prev != NULL)
    {
        Node *entry = new Node();
        entry->age = temp->age;
        entry->name = temp->name;
        entry->gender = temp->gender;
        entry->dept = temp->dept;
        entry->bottom = temp;
        entry->top = NULL;
        temp->top = entry;
        temp2 = temp->right;
        while (temp2!=NULL&&temp2->top == NULL)
        {
            temp2 = temp2->right;
        }
        temp2 = temp2->top;
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
Collection insert_a(Collection c, string name,int age ,string gender,string dept)
{
    //Function to return a node to ins_coin to which data is to inserted 
    // x = y: we return element(after(p))
    // x > y: we “scan forward”
    // x < y: we “drop down”
    Unode *utemp = c.start;
    Node *temp;
    Node *entry = new Node();
    entry->name=name;
    entry->dept=dept;
    entry->gender=gender;
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
        return ins_coin(c, entry);
    }
    while (utemp != NULL) // check again
    {
        temp = utemp->curhead;
        // entry=ddl_insert(entry,temp);
        // return ins_coin(c,entry);
        while (temp != NULL)
        {
            if (name < temp->name|| (temp->right != NULL && temp->right->right == NULL&&temp->right->left->left==NULL))
            {
                if (temp->bottom == NULL)
                {
                    if((name<temp->name&&name>temp->left->name)||temp->left->left==NULL)
                    {
                        ddl_insert(entry,temp);
                        return ins_coin(c, entry);
                    }
                    else temp=temp->left;
                }
                else temp = temp->bottom;
            }
            else if (name > temp->name||temp->left==NULL)
            {
                temp=temp->right;
            }
            else if (name== temp->name)
            {
                if(temp->right==NULL)
                {
                   temp=c.start->curhead->right;
                    while (temp->bottom!=NULL)
                    {
                        temp=temp->bottom;
                    }
                    ddl_insert(entry,temp);
                    return ins_coin(c, entry); 
                }
                cout << "Invalid entry already exists with give name" << endl;
                delete entry;
                return c;
            }
            else
            {
                //Just kept for syntax completion IGNORE
            }
        }
        utemp = utemp->next;
    }
    temp=c.start->curhead->right;
    while (temp->bottom!=NULL)
    {
        temp=temp->bottom;
    }
    ddl_insert(entry,temp);
    return ins_coin(c, entry);
    // return c;
}
Node *search_c(Collection c,string name,bool isDel)
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
            if (name < temp->name || (temp->right != NULL && temp->right->right == NULL&&temp->left==NULL))
            {
                if (temp->bottom == NULL)
                {
                    if((name<temp->name&&name>temp->left->name)||(temp->left->left==NULL))
                    {
                        cout<<"Not Found with given name"<<endl;
                        return NULL;
                    }
                    else temp=temp->left;
                }
                else temp = temp->bottom;
            }
            else if (name > temp->name||temp->left==NULL)  temp=temp->right;
            else if (name == temp->name)
            {
                //exp here
                if(temp->right==NULL)
                {
                    if(temp->left->name==name)
                    {
                        cout<<"*** Requested Details  ****"<<endl;
                        cout <<"Name      :"<< temp->left->name<<endl;
                        cout <<"Gender    :"<< temp->left->gender<<endl;
                        cout <<"Department:"<< temp->left->dept<<endl;
                        cout <<"Age       :"<< temp->left->age<<endl;
                        cout<<"******************"<<endl;
                    }
                    else
                    {
                        cout<<"Not Found with given name"<<endl;
                        return NULL;
                    }
                }
                //exp here
                if(isDel)cout<<"*** Deleted Successfully ***"<<endl;
                else
                {
                    cout<<"*** Requested Details  ****"<<endl;
                    cout <<"Name      :"<< temp->name<<endl;
                    cout <<"Gender    :"<< temp->gender<<endl;
                    cout <<"Department:"<< temp->dept<<endl;
                    cout <<"Age       :"<< temp->age<<endl;
                    cout<<"******************"<<endl;
                } 
                return temp;
            }
            else
            {
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
Collection delete_b(Collection c, string name)
{
    //function to return collection after search and delete data with given name
    Node *temp=search_c(c,name,1);
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
        if(c.start->prev!=NULL)
        {
            c.start->prev->curhead->bottom=c.start->next->curhead;
            c.start->prev->curhead->right->bottom=c.start->next->curhead->right;
            c.start->prev->next=c.start->next;
        }
        if(c.start->next!=NULL)
        {
            c.start->next->curhead->top=NULL;
            c.start->next->curhead->right->top=NULL;
            c.start->next->prev=c.start->prev;
        }
        c.start=c.start->next;
        delete utemp;
    }
    return c;
}
int main()
{
    Collection c = create(c);
    c=insert_a(c,"bran",18,"M","CSE");
    c=insert_a(c,"cod",19,"M","CSE");
    c=insert_a(c,"donkey",20,"M","CSE");
    c=insert_a(c,"emp",21,"M","CSE");
    c=insert_a(c,"food",22,"M","CSE");
    c=insert_a(c,"gold",23,"M","CSE");
    c=insert_a(c,"honey",24,"M","CSE");
    c=insert_a(c,"ink",25,"M","CSE");
    c=insert_a(c,"jump",26,"M","CSE");
    c=insert_a(c,"zzzzzzzzzzzz",26,"M","CSE");
    Node *temp;
    temp=search_c(c,"zzzzzzzzzzzz",0); //for searching make the third argument 0
    c=delete_b(c,"A");
    c=delete_b(c,"bran");
    c=delete_b(c,"cod");
    c=delete_b(c,"emp");
    c=delete_b(c,"food");
    c=delete_b(c,"gold");
    c=delete_b(c,"honey");
    c=delete_b(c,"ink");
    c=delete_b(c,"jump");
    c=delete_b(c,"donkey");
    c=insert_a(c,"cod",19,"M","CSE");
    c=insert_a(c,"donkey",20,"M","CSE");
    c=insert_a(c,"emp",21,"M","CSE");
    c=insert_a(c,"food",22,"M","CSE");
    c=insert_a(c,"gold",23,"M","CSE");
    c=insert_a(c,"honey",24,"M","CSE");
    c=insert_a(c,"ink",25,"M","CSE");
    c=insert_a(c,"jump",26,"M","CSE");
    c=delete_b(c,"A");
    c=delete_b(c,"bran");
    c=delete_b(c,"cod");
    c=delete_b(c,"emp");
    c=delete_b(c,"food");
    c=delete_b(c,"gold");
    c=delete_b(c,"honey");
    c=delete_b(c,"ink");
    c=delete_b(c,"jump");
    c=delete_b(c,"donkey");
    printer(c);
    free_mem(c);
    return 0;
}