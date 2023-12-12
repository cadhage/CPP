#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	int data;
	node *left,*right;
};
node *newNode(ll data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node *root,ll data){
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
void find(node *root,ll x){
	if(root==NULL)
		return;
	if(root->data==x)
		printRoot(root);
	if(root->data<x)
		find(root->left,x);
	else find(root->right,x);
}
int main() {
	ll n;
	cin>>n;
	ll a[n];
	ll x;cin>>x;
	node *root=newNode(x);
	for(ll i=1;i<n;i++){
		cin>>x;
		root=insert(root,x);
	}
	ll r;cin>>r;
	find(root,r);
	return 0;
}
