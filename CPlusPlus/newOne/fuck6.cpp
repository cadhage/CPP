// C++ Program for Lowest Common Ancestor in a Binary Tree 
// A O(n) solution to find LCA of two given values n1 and n2 
#include <iostream> 
#include <vector> 

using namespace std; 

// A Binary Tree node 
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
	Node *temp = new Node; 
	temp->key = k; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
Node *findLCA(Node *root, int n1, int n2) 
{ 
	if(root==NULL)
		return 0;
	if(root->key==n1 ||root->key==n2)
		return root;
	Node *l=findLCA(root->left,n1,n2);
	Node *r=findLCA(root->right,n1,n2);
	if(l && r)
		return root;
	return l?l:r;	
} 
int main() 
{ 
	// Let us create the Binary Tree shown in above diagram. 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	cout << "LCA(4, 5) = " <<findLCA(root, 4, 5)->key; 
	cout << "\nLCA(4, 6) =  " << findLCA(root, 4, 6)->key; 
	cout << "\nLCA(3, 4) =  " << findLCA(root, 3, 4)->key; 
	cout << "\nLCA(2, 4) =  " << findLCA(root, 2, 4)->key; 
	return 0; 
} 

