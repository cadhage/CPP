#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node *root,int data){
	if(root==NULL)
		return  newNode(data);
	if(root->data<data)
		root->left=insert(root->left,data);
	else root->right=insert(root->right,data);
}
void printRoot(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<'\n';
	printRoot(root->left);
	
	printRoot(root->right);
}
void find(node *root,int x){
	if(root==NULL)
		return;
	if(root->data==x)
		printRoot(root);
	if(root->data<x)
		find(root->left,x);
	else find(root->right,x);
}
int main() {
	int n;
	cin>>n;
	int a[n];
	int x;cin>>x;
	node *root=newNode(x);
	for(int i=1;i<n;i++){
		cin>>x;
		root=insert(root,x);
	}
	int r;cin>>r;
	find(root,r);
	return 0;
}
