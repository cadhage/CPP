// CPP program to print the longest leaf to leaf 
// path 
#include <bits/stdc++.h> 
using namespace std; 

// Tree node structure used in the program 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

struct Node* newnode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 

	return (node); 
} 
bool existPath(Node *root,int a[],int n,int index){
	if(root==NULL)
		return n==0;
	if((root->left==NULL &&root->right==NULL)
		&&(root->data==a[index]&& index==n-1))
			return true;
	return ((index<n)&(root->data==a[index])&&
	(existPath(root->left,a,n,index+1))||
	existPath(root->right,a,n,index+1));	
}
int main() 
{ 
   	int arr[] = {5, 8, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    struct Node *root = newnode(5); 
    root->left    = newnode(3); 
    root->right   = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->left->left->left = newnode(1); 
    root->right->left = newnode(6); 
    root->right->left->right = newnode(7); 
  
    existPath(root, arr, n, 0)? cout << "Path Exists" : 
                                cout << "Path does not Exist"; 

	return 0; 
} 

