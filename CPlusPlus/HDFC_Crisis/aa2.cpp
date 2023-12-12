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
void deleteDeepest(node *root,node *d_node){
	queue<node *> q;
	q.push(root);
	node *temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp==d_node){
			temp=NULL;
			delete(d_node);
			return;
		}
		if(temp->right){
			if(temp->right==d_node){
				temp->right=NULL;
				delete(d_node);
				return;
			}
			else q.push(temp->right);
		}
		if(temp->left){
			if(temp->left==d_node){
				temp->left=NULL;
				delete(d_node);
				return;
			}
			else q.push(temp->left);
		}
	}
}
void inorder(node *temp){
	if(temp==NULL)
		return;
	inorder(temp->left);
	cout<<temp->data<<' ';
	inorder(temp->right);
}
node *deletion(node *root,int data){
	
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL){
		if(root->data==data){
			return NULL;
		}
		else return root;
	}
	queue<node *> q;
	q.push(root);
	node *temp,*key_node=NULL;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->data==data){
			key_node=temp;
		}
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	if(key_node!=NULL){
		int x=temp->data;
		deleteDeepest(root,temp);
		key_node->data=x;
	}
	return root;
}
int main(){
	    struct node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
    return 0;
}
