#include <bits/stdc++.h> 
using namespace std; 
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
node *insert(node *root,int n){
	if(root==NULL)
		return newNode(n);
	if(n<root->key)
		root->left=insert(root->left,n);
	else if(n>root->key)
		root->right=insert(root->right,n);
	return root;
}
int maxDepth(node* root)  
{  
    if (root == NULL)  
        return 0;  
  	return max(maxDepth(root->left),maxDepth(root->right))+1; 
} 
int main() 
{ 
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	node *root=NULL;
	root=insert(root,a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	cout<<maxDepth(root);
	return 0; 
} 
