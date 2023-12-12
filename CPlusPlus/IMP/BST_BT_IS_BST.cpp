#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newnode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
bool isBST(node* root,int mn,int mx){
	if(root==NULL)
		return true;
	if(root->data<mn ||root->data>mx)
		return false;
	return isBST(root->left,mn,root->data-1)&&
			isBST(root->right,root->data+1,mx);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = newnode(4);  
    root->left = newnode(2);  
    root->right = newnode(5);  
    root->left->left = newnode(1);  
    root->left->right = newnode(3);  
    if(isBST(root,INT_MIN,INT_MAX))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
	return 0;
}
