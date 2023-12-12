#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newNode(int data){
	node* temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return  temp;
}
void mirror(node* root){
	if(root==NULL)
		return;
	else{
		node* temp;
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
bool isStructSame(node *left,node *right){
	if(left==NULL&&right==NULL)
		return true;
	if(left!=NULL &&right!=NULL &&isStructSame(left->left,right->left))
		return true;
	return false;
}
bool isFoldable(node *a,node *b){
	if(a==NULL&&b==NULL)
		return true;
	if(a==NULL||b==NULL)
		return false;
	return isFoldable(a->left,b->right)&&
	isFoldable(a->right,b->left);
}
bool foldable(node *root){
	if(root==NULL)
		return true;
	return isFoldable(root->left,root->right);
}
int main(){
	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->right->left=newNode(4);
	root->left->right=newNode(5);
	if(foldable(root))
		cout<<"yes";
	else cout<<"not";
	return  0;
}      
