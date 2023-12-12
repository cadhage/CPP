#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
void addGreaterUtil(node* root,int *sum){
	if(root==NULL)
		return;
	addGreaterUtil(root->right,sum);
	*sum=*sum+root->data;
	root->data=*sum;
	addGreaterUtil(root->left,sum);
}
void addGreater(node *root){
	int sum=0;
	addGreaterUtil(root,&sum);
}
void preorder(node *root){
	if(root==NULL)
		return;
	preorder(root->left);
	cout<<root->data<<' ';	
	preorder(root->right);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(13); 
    cout<<("Inorder traversal of the given tree\n"); 
    preorder(root); 
    addGreater(root); 
    cout<<("\nInorder traversal of the modified tree\n"); 
    preorder(root);
	return 0; 
}
