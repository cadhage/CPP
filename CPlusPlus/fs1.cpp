// C++ Program for Lowest Common Ancestor in a Binary Tree 
// A O(n) solution to find LCA of two given values n1 and n2 
#include <iostream> 
#include <vector> 
  
using namespace std; 
  
// A Binary Tree node 
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
node * newNode(int k) 
{ 
    node *temp = new node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
node *findLCA(node *root,int a,int b){
	if(root==NULL)
		return false;
	if(root->key==a ||root->key==b)
		return root;
	node *left=findLCA(root->left,a,b);
	node *right=findLCA(root->right,a,b);
	if(left&&right)
		return root;
	if(root->left!=NULL)
	return left;
	else right;
}
int main() 
{ 
    node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key<<'\n'; 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key<<'\n'; 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key<<'\n'; 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key<<'\n'; 
    return 0; 
}
