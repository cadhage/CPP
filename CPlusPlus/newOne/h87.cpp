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
bool isBST(node* root){
	if(root==NULL)
		return true;
	node *prev=NULL;
	return isBST(root->left);
	if(prev!=NULL&&root->data<=prev->data)
		return false;
	prev=root;
	return isBST(root->right);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(5); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(4); 
  
    if (isBST(root)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
	return 0; 
}
