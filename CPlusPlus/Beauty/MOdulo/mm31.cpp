#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
node *lca(node *root,int l,int r){
	if(root==NULL)
		return NULL;
	if(root->data>l && root->data>r)
		return lca(root->left,l,r);
	if(root->data<l && root->data<r)
		return lca(root->right,l,r);
	return root;
}
int main(){
	node *root = newNode(3); 
    root->left     = newNode(2); 
    root->right     = newNode(5); 
    root->left->left = newNode(1); 
    root->right->left = newNode(4); 
  	node *prev=NULL;
  	node *temp=lca(root,2,5);
  	cout<<temp->data<<'\n';
	return 0;
}
