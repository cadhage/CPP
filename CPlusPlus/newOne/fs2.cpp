#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newNode(int data){
	node *root=new node;
	root->left=root->right=NULL;
	root->data=data;
	return root;
}
void levelOrder(node *root){
	if(root==NULL)
		return;
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	while(!s1.empty()||!s2.empty()){
		while(!s1.empty()){
			node *temp=s1.top();
			cout<<temp->data<<" ";
			s1.pop();
			if(temp->right!=NULL){
				s2.push(temp->right);
			}
			if(temp->left!=NULL){
				s2.push(temp->left);
			}
		}
		while(!s2.empty()){
			node *temp=s2.top();
			cout<<temp->data<<" ";
			s2.pop();
			if(temp->left!=NULL){
				s1.push(temp->left);
			}
			if(temp->right!=NULL){
				s1.push(temp->right);
			}
		}
	}
}
int main(){
	 struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
	levelOrder(root);
	return 0;
}
