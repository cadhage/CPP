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
struct node *minNode(struct node *root){
	if(root==NULL)
		return root;
	struct node *a=root;
	while(a->left!=NULL){
		a=a->left;
	}
	return a;
}
struct node *deleteNode(struct node *root,int data){
	if(root==NULL)
		return root;
	if(root->data>data)
		root->left=deleteNode(root->left,data);
	else if(root->data<data){
		root->right=deleteNode(root->right,data);
	}
	else{
		if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node *temp=minNode(root);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
	return root;
}
int main() 
{ 
	struct node *root=NULL;
	root=insert(root,50);
	int a[]={30,20,40,70,60,80};
	for(int i=0;i<6;i++){
		insert(root,a[i]);
	}
	inorder(root);
	root = deleteNode(root, 20); 
	cout<<'\n';
	inorder(root);
	return 0; 
} 

