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
void *insert(struct node *root,int key){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		struct node* temp=q.front();
		q.pop();
		if(!temp->left){
			temp->left=newNode(key);
			break;
		}
		else q.push(temp->left);
		if(!temp->right){
			temp->right=newNode(key);
			break;
		}
		else
			q.push(temp->right);
	}
}
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
int main() 
{ 
	node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
    insert(root,12);
	inorder(root);
	return 0; 
} 

