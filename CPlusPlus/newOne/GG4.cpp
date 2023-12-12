#include <bits/stdc++.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree Node 
struct node *getNode(int item) 
{ 
    struct node *temp =  new node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void printInorder(struct node *root) 
{ 
    if (root == NULL) return; 
    cout << root->data << " "; 
    printInorder(root->left);
    printInorder(root->right); 
} 
void BSTToMinHeap(node *root,vector<int> a,int &i){
	if(root==NULL)
		return;
		root->data=a[++i];
		BSTToMinHeap(root->left,a,i);
		BSTToMinHeap(root->right,a,i);
}
void store(vector<int> &a,node *root){
	if(root==NULL)
		return;
	store(a,root->left);
	a.push_back(root->data);
	store(a,root->right);
}
void convertToMinHeapUtil(node *root){
	vector<int> a;
	int i=-1;
	store(a,root);
	BSTToMinHeap(root,a,i);
}
int main() 
{ 
    // BST formation 
    struct node *root = getNode(4); 
    root->left = getNode(2); 
    root->right = getNode(6); 
    root->left->left = getNode(1); 
    root->left->right = getNode(3); 
    root->right->left = getNode(5); 
    root->right->right = getNode(7); 
  
    convertToMinHeapUtil(root); 
    cout << "Preorder Traversal:" << endl; 
    printInorder(root); 
  
    return 0; 
} 
