#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node *root,int data){
	if(root==NULL)
		return  newNode(data);
	if(root->data>data)
		root->left=insert(root->left,data);
	else root->right=insert(root->right,data);
}
void inorder(node *root){
	if(root==NULL)
		return;
	///cout<<root->data<<'\n';
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
int main() {
	
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	inorder(root);
	return 0;
}
