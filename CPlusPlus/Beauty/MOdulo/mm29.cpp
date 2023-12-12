#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};

void inorder(node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
node *newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
node *insert(node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(root->data>data){
		root->left=insert(root->left,data);
	}
	else root->right=insert(root->right,data);
}
node *minValue(node *root){
	node *temp=root;
	while(temp && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
node *deleteNode(node *root,int data){
	if(root==NULL)
		return root;
	else if(root->data>data)
		root->left=deleteNode(root->left,data);
	else if(root->data<data)
		root->right=deleteNode(root->right,data);
	else{
		if(root->left==NULL){
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node *temp=root->left;
			free(root);
			return temp;
		}
		
		node *temp=minValue(root);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
	return root;
}
void _print(node *root,int x,int y){
	if(root==NULL)
		return;
	if(root->data>x)
		_print(root->left,x,y);
	if(root->data>=x && root->data<=y){
		cout<<root->data<<' ';
	}
	if(y>root->data) 
		_print(root->right,x,y);
	
}
int main(){
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root);
    cout<<'\n';
    _print(root,50,70);
  
    return 0; 
} 
