#include <bits/stdc++.h> 
using namespace std; 
struct node { 
    int data; 
    struct node *left, *right; 
}; 
node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
node *sortedArrayToBST(int a[],int s,int e){
	if(s>e)	
		return NULL;
	int mid=(s+e)>>1;
	node *root=newNode(a[mid]);
	root->left=sortedArrayToBST(a,s,mid-1);
	root->right=sortedArrayToBST(a,mid+1,e);
	return root;
}
void inorder(node* root) 
{ 
    if (!root) 
        return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    /* Convert List to BST */
    node *root = sortedArrayToBST(arr, 0, n-1);  
    cout << "PreOrder Traversal of constructed BST \n";  
    inorder(root);  
    return 0;
} 
  
