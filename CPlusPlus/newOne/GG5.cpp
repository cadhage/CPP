#include <bits/stdc++.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree Node 
struct node *newNode(int item) 
{ 
    struct node *temp =  new node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void printInorder(struct node *root) 
{ 
    if (root == NULL) return; 
  
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 
int sum=0;
void transformTree(node *root){
	if(root==NULL)
		return;
	transformTree(root->right);
	sum+=root->data;
	root->data=sum-root->data;
	transformTree(root->left);
}
int main() 
{ 
    struct node *root = newNode(11); 
    root->left = newNode(2); 
    root->right = newNode(29); 
    root->left->left = newNode(1); 
    root->left->right = newNode(7); 
    root->right->left = newNode(15); 
    root->right->right = newNode(40); 
    root->right->right->left = newNode(35); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    transformTree(root); 
  
    cout << "\n\nInorder Traversal of transformed tree\n"; 
    printInorder(root); 
  
    return 0; 
} 
