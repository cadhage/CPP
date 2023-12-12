#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=x;
	return temp;
}
void preOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<' ';
	preOrder(root->left);
	preOrder(root->right);
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
int main()  
{  
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    /* Convert List to BST */
    node *root = sortedArrayToBST(arr, 0, n-1);  
    cout << "PreOrder Traversal of constructed BST \n";  
    preOrder(root);  
  
    return 0;  
}  
