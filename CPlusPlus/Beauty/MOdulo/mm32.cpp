#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*parent,*right;
};
node *minValue(node *root){
	node *temp=root;
	while(temp && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
node *inorderSuccessor(node *root,node *n){
	if(n->right!=NULL)
		return  minValue(n->right);
	node *p=n->parent;
	while(p!=NULL&& n==p->right){
		n=p;
		p=p->parent;
	}
	return p;
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
	else {
		node *temp;
		if(root->data>data){
			temp=insert(root->left,data);
			root->left=temp;
			temp->parent=root;
		}
		else{
			temp=insert(root->right,data);
			root->right=temp;
			temp->parent=root;
		}
		return root;
	}
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
    cout<<inorderSuccessor(root,root->left)->data; 
    return 0; 
} 
