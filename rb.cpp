/* 
Name = Rajulapati Bhargava Ram
Roll = CS21BTECH11052
    **red Black Trees**
*/
#include <iostream>
using namespace std;
enum colour {red, Black};//red-0 Black-1

struct Node{
    int Age;
    bool colour;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

//Creating new node
struct Node* newNode(int age){
    
    Node* newNode = new Node();
    newNode->Age = age;
    newNode->colour = red;
    newNode->left = NULL;
    newNode->right =NULL;
    newNode->parent = NULL;
    return newNode;
}

//Normal BST insertion
struct Node* insertBST(struct Node* root, struct Node* newNode){
    
    Node* temp = root;
    Node* prev = NULL;
    //temp pointer gives the position where the newnode should but 
    //we need the prev node to create a link so we use prev
    while(temp != NULL){
        prev = temp;
        if(newNode->Age > temp->Age){
            temp = temp->right;
        }
        else temp = temp->left;
    }

    //tree is empty
    if(prev == NULL){
        prev = newNode;
        return prev;
    }
    //Greater than prev node
    else if(newNode->Age > prev->Age){
        prev->right = newNode;
        newNode->parent = prev;
    }
    //Less than prev node
    else{
        prev->left = newNode;
        newNode->parent = prev;
    } 
    return root;    
}

struct Node* rotateRight(struct Node* root, struct Node* temp){
    struct Node* ptr = temp->left;
    //Setting right child of parent to grandparent
    temp->left = ptr->right;
    if(ptr->right != NULL){
        ptr->right->parent = temp;
    }
    //Setting parents of parent and grandparent
    ptr->parent = temp->parent;
    if(temp->parent == NULL){
        root = ptr;
    }
    else if(temp == temp->parent->left){
        temp->parent->left = ptr;
    }
    else{
        temp->parent->right = ptr;
    }

    ptr->right = temp;
    temp->parent = ptr;
    return temp;
}

struct Node* rotateLeft(struct Node* root, struct Node* temp){
    struct Node* ptr = temp->right;
    //Setting right child of parent to grandparent
    temp->right = ptr->left;
    if(ptr->left != NULL){
        ptr->left->parent = temp;
    }
    //Setting parents of parent and grandparent
    ptr->parent = temp->parent;
    if(temp->parent == NULL){
        root = ptr;
    }
    else if(temp == temp->parent->left){
        temp->parent->left = ptr;
    }
    else{
        temp->parent->right = ptr;
    }

    ptr->left = temp;
    temp->parent = ptr;

    return temp;
}

void swap(int &a, int &b){
    int z = a;
    a = b;
    b = z;
}

bool propertyRB(struct Node* root, struct Node* newNode){

    struct Node* par = NULL;
    struct Node* grandPar = NULL;
    newNode->colour=red;
    if(root==newNode) 
    {
        root->colour=Black;
        return true;
    }
    //We have nothing to change when parent is Black in colour
    while(newNode != NULL && newNode->colour != Black && newNode->parent->colour == red)
    {

        par = newNode->parent;
        if(newNode->parent!=NULL)grandPar = newNode->parent->parent;

        //Case 1: Parent is left child
        if(par == grandPar->left){
            struct Node* uncle = grandPar->right;
            //Case A: Uncle colour is red
            if(uncle != NULL && uncle->colour == red){
                uncle->colour = Black;
                par->colour = Black;
                grandPar->colour = red;
                newNode = grandPar;
            }
            //Uncle colour is Black
            else{
                //Case B: newNode is left child
                if(newNode == par->left){
                    rotateRight(root, grandPar);
                    swap(par->colour, grandPar->colour);
                    newNode = par;
                }
                //Case C: newNode is right child
                else{
                    par = rotateLeft(root, par);
                    newNode = par;
                    par = newNode->parent;
                    
                    rotateRight(root, grandPar);
                    swap(par->colour, grandPar->colour);
                    newNode = par;
                }
            }
        }
        //Case 2: Parent is right child
        else{
            struct Node* uncle = grandPar->left;
            //Case A: Uncle colour is red
            if(uncle != NULL && uncle->colour == red){
                uncle->colour = Black;
                par->colour = Black;
                grandPar->colour = red;
                newNode = grandPar;
            }
            //Uncle colour is Black
            else{
                //Case B: newNode is right child
                if(newNode == par->right){
                    grandPar = rotateLeft(root, grandPar);
                    swap(par->colour, grandPar->colour);
                    newNode = par;
                }
                //Case C: newNode is left child
                else{
                    rotateRight(root, par);
                    newNode = par;
                    par = newNode->parent;
                    
                    grandPar = rotateLeft(root, grandPar);
                    swap(par->colour, grandPar->colour);
                    newNode = par;
                }
            }
        }
    }
    root->colour = Black;
    return true;
}

struct Node* insertRBT(struct Node* root, int age){
    
    struct Node* nptr = newNode(age);
    //Normal BST insertion
    root=insertBST(root, nptr);
    propertyRB(root, nptr);

    return root;
}

//To print the RBT in inorder recursively
void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        cout<<root->Age<<" "<<root->colour<<endl;
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    //9
    //4
    root = insertRBT(root, 9);
    root = insertRBT(root, 4);
    root = insertRBT(root, 5);
    // root = insertRBT(root, 12);
    // root = insertRBT(root, 0);
    inorder(root);
    return 0;
}