#include<bits/stdc++.h>
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
void modofiedLevelOrderUtil(node *root,stack<node*> &s){
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root->left);
	q.push(root->right);
	node *first=NULL,*second=NULL;
	while(!q.empty()){
		first=q.front();
		q.pop();
		second=q.front();
		q.pop();
		s.push(second->left);
		s.push(first->right);
		s.push(second->right);
		s.push(first->left);
		if(root->left->left!=NULL)
		{
			q.push(first->right);
			q.push(second->left);
			q.push(first->left);
			q.push(second->right);
		}
	}
}
void modifiedLevelOrder(node *root){
	stack<node *> s;
	s.push(root);
	if(root->left!=NULL){
		s.push(root->right);
		s.push(root->left);
	}
	if(root->left->left!=NULL){
		modofiedLevelOrderUtil(root,s);
	}
	while(!s.empty()){
		cout<<s.top()->data<<" ";
		s.pop();
	}
}
int main() 
{  
 node* root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
  root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31);
    modifiedLevelOrder(root); 
  
    return 0; 
} 
