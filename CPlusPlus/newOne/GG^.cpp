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
/* This function traverse the skewed binary tree and 
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(node* root, vector<node*> &nodes) 
{ 
    // Base case 
    if (root==NULL) 
        return; 
  
    // Store nodes in Inorder (which is sorted 
    // order for BST) 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
} 
  
/* Recursive function to construct binary tree */
node* buildTreeUtil(vector<node*> &nodes, int start, 
                   int end) 
{ 
    // base case 
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    node *root = nodes[mid]; 
  
    /* Using index in Inorder traversal, construct 
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end); 
  
    return root; 
} 
  
// This functions converts an unbalanced BST to 
// a balanced BST 
node* buildTree(node* root) 
{ 
    // Store nodes of given BST in sorted order 
    vector<node *> nodes; 
    storeBSTNodes(root, nodes); 
  
    // Constucts BST from nodes[] 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1); 
} 
  
void preOrder(node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
int main() 
{ 
 	node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    root = buildTree(root); 
  
    printf("Preorder traversal of balanced "
            "BST is : \n"); 
    preOrder(root); 
  
    return 0; 
} 
