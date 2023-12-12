#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node* newNode(int data){
	struct node* temp=(struct node*) malloc(sizeof(struct node)); 
	temp->data=data;
	temp->left=temp->right=NULL;
}
vCover(struct node* root){
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	int sizeInc=1+vCover(root->left)+vCover(root->right);
	int sizeExc=0;
	if(root->left)
		sizeExc+=1+vCover(root->left->left)+vCover(root->left->right);
	if(root->right)
		sizeExc+=1+vCover(root->right->left)+vCover(root->right->right);
	return min(sizeInc,sizeExc);
}
int main(){
	struct node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25); 
    cout<<vCover(root);
	return 0;
}
