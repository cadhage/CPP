#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
int floor(node *root,int n){
	if(root==NULL)
		return -1;
	if(n==root->data)
		return root->data;
	if(root->data>n)
		return floor(root->left,n);
	int ceil=floor(root->right,n);
	return ceil>=n?ceil:root->data;
}
int Print(node *root,int n){
	if(root==NULL)
		return -1;
	if(n==root->data)
		return root->data;
	if(root->data<n)
		return Print(root->right,n);
	int ceil=Print(root->left,n);
	return ceil>=n?ceil:root->data;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = new node();  
    root = newNode(8);  
    root->left = newNode(4);  
    root->right = newNode(12);  
    root->left->left = newNode(2);  
    root->left->right = newNode(6);
	root->right->left=newNode(10);
	root->right->right=newNode(14);   
    cout << 10 << " " << Print(root, 9) << endl;
	cout<<10<<" "<<floor(root,7)<<'\n'; 
}
