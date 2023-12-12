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
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
}
int main(){
	node* root=newNode(1);
	root->left=newNode(3);
	root->right=newNode(2);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	levelOrder(root);
	return 0;
}
