#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
}
bool treeContinuous(node *root){
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	if(root->left==NULL)
		return abs(root->data-root->right->data)==1
			&& treeContinuous(root->right);
	if(root->right==NULL)
		return abs(root->data-root->left->data)==1
		&&treeContinuous(root->left);
	return abs(root->data-root->left->data)==1
		&&treeContinuous(root->left)
		&&abs(root->data-root->right->data)==1
		&&treeContinuous(root->right);
}
int main(){
	node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No"; 
	return 0;
}
