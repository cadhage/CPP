
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right;
};
node* newNode(int data){
	node* temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* insert(node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(root->data>=data){
		root->left=insert(root->left,data);
	}
	else root->right=insert(root->right,data);
	return root;
}
int findMax(node *root,int n){
	if(root==NULL)
		return -1;
	if(root->data==n)
		return n;
	else if(root->data<n){
		int k=findMax(root->right,n);
		if(k==-1)
			return root->data;
		else return k;
	}
	else if(root->data>n)
		return findMax(root->left,n);
}
int main(){
	node *root=NULL;
	root=insert(root,25);
   insert(root, 2); 
    insert(root, 1); 
    insert(root, 3); 
    insert(root, 12); 
    insert(root, 9); 
    insert(root, 21); 
    insert(root, 19); 
    insert(root, 25); 
	cout<<findMax(root,4);
	return 0;
}
