#include<bits/stdc++.h> 
using namespace std;
struct node{
	int data;
	node *left,*right;
}; 
node *newNode(int data){
	node *root=new node;
	root->left=root->right=NULL;
	root->data=data;
	return root;
}
node *insert(node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(root->data>=data)
		root->left=insert(root->left,data);
	else root->right=insert(root->right,data);	
	return root;
}
//int c=0;
int solver(node *root){
	if(root==NULL)
		return 0;
	int c=0;
	if(root->left!=NULL)
		c+=1+solver(root->left);
	if(root->right!=NULL)
		c+=solver(root->right);
	return c;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		node *root=NULL;
		int x;cin>>x;
		root=insert(root,x);
		for(int i=1;i<n;i++){
			cin>>x;
			insert(root,x);
		}
		cout<<solver(root);
	}
	return 0;
}
