/* 
Name = Rajulapati Bhargava Ram
Roll = CS21BTECH11052
    Red Black Trees
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

    //tree is emptptr
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
	struct Node* parent = temp->parent;
    struct Node* ptr = temp->left;

	ptr->parent = temp->parent;
	temp->parent = ptr;
    
    if(ptr->right != NULL){
        ptr->right->parent = temp;
    }
	temp->left = ptr->right;
	ptr->right = temp;
    
    if(parent != NULL){
		if(temp == parent->left){
        	parent->left = ptr;
   		}
		else{
			parent->right = ptr;
		}
    }
    else{
		root = ptr;
		return root;
	}
    return temp;
}

struct Node* rotateLeft(struct Node* root, struct Node* temp){
	struct Node* parent = temp->parent;
    struct Node* ptr = temp->right;

	ptr->parent = temp->parent;
	temp->parent = ptr;
    
    if(ptr->left != NULL){
        ptr->left->parent = temp;
    }
	temp->right = ptr->left;
	ptr->left = temp;
    
    if(parent != NULL){
		if(temp == parent->left){
        	parent->left = ptr;
   		}
		else{
			parent->right = ptr;
		}
    }
    else{
		root = ptr;
		return root;
	}
    return temp;
}
  
void swap(int &a, int &b){
    int z = a;
    a = b;
    b = z;
}

struct Node *propertptrRB(struct Node* root, struct Node* newNode){

    struct Node* par = NULL;
    struct Node* grandPar = NULL;
    newNode->colour=red;
    if(root==newNode) 
    {
        root->colour=Black;
        return root;
    }
    //We have nothing to change when parent is Black in colour
    while(newNode != NULL && newNode->colour != Black &&newNode->parent!=NULL &&newNode->parent->colour == red)
    {
        par = newNode->parent;
        if(newNode->parent!=NULL){
			grandPar = newNode->parent->parent;
		}
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
					// cout<<root->left->Age<<endl;
                    newNode = par;
                    par = newNode->parent;
                    
                    grandPar=rotateRight(root, grandPar);
                    if(grandPar->parent==NULL) root=grandPar;
                    //cout<<root->left->Age<<endl;
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
                    //bug here
                    rotateRight(root, par);
                    newNode = par;
                    par = newNode->parent;  
                    grandPar = rotateLeft(root, grandPar);
                    if(grandPar->parent==NULL) root=grandPar;
                    swap(par->colour, grandPar->colour);
                    newNode = par;
                }
            }
        }
    }
    root->colour = Black;
    return root;
}

struct Node* insertRBT(struct Node* root, int age){
    
    struct Node* nptr = newNode(age);
    //Normal BST insertion
    root=insertBST(root, nptr);

    root=propertptrRB(root, nptr);

    return root;
}

//To print the RBT in inorder recursivelptr
void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        cout<<root->Age<<"  "<<"Colour: "<<root->colour<<endl;
        inorder(root->right);
    }
}

//Search by Age
void search(struct Node* root,int age){
    Node* temp = root;
    //Iterate from the root till leaves untill we find the name
    while(temp != NULL && age != temp->Age){
        if(age > temp->Age){
            temp = temp->right;
        }
        else temp = temp->left;
    }
    //If we find the node with name we are searching print details
    if(temp != NULL && age == temp->Age){
        cout<<"\nFaculty with given age is there in the RBTree and details are "<<endl;
        cout<<"Age        :  "<<temp->Age<<endl;
        cout<<"Colour     :  "<<temp->colour<<endl;
        cout<<"\n";
    }
    else if(temp == NULL) cout<<"\nSearch: Not found!!"<<endl;
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