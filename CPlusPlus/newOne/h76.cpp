#include <bits/stdc++.h> 
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *newNode(int data){
	struct node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
struct node *insert(struct node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(data>root->data){
		root->right=insert(root->right,data);
	}
	else if(data<root->data)
		root->left=insert(root->left,data);
	return root;
}
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
void storeInorder(node *root,set<int> &s){
	if(root==NULL)
		return;
	storeInorder(root->left,s);
	s.insert(root->data);
	storeInorder(root->right,s);
}
void setToBST(set<int> &s,node* root){
	if(!root)
		return;
	setToBST(s,root->left);
	auto it=s.begin();
	root->data=*it;
	s.erase(it);
	setToBST(s,root->right);
}
void binaryTreeToBST(node *root){
	set<int> s;
	storeInorder(root,s);
	setToBST(s,root);
}
int main() 
{ 
	node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11); 
    binaryTreeToBST(root);
	inorder(root);
	return 0; 
} 

