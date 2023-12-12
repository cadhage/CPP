#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *right,*left;
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
	if(root->data>=data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
int minValue(node *root){
	node* a=root;
	while(a->left!=NULL){
		a=a->left;
	}
	return a->data;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int x;cin>>x;
	node *root=NULL;
	root=insert(root,x);
	for(int i=0;i<n-1;i++){
		cin>>x;
		insert(root,x);
	}
	cout<<minValue(root);
	return 0;
}

