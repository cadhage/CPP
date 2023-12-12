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
bool isBST(node *root,int min,int max){
	if(root==NULL)
		return true;
	if(root->data<min||root->data>max)
		return false;
	return isBST(root->left,min,root->data-1)&&
			isBST(root->right,root->data+1,max);
}
int main(){
	node *root = newNode(3); 
    root->left     = newNode(2); 
    root->right     = newNode(5); 
    root->left->left = newNode(1); 
    root->right->left = newNode(4); 
  	node *prev=NULL;
    if (isBST(root,INT_MIN,INT_MAX)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
  
    return 0; 
	return 0;
}
