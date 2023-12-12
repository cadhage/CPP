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
void preorder(node *root){
	if(root==NULL)
		return;
	
	preorder(root->left);
	cout<<root->data<<' ';
	preorder(root->right);
}
void storeBST(node* root,vector<node*> &v){
	if(root==NULL)
		return;
	storeBST(root->left,v);
	v.push_back(root);
	storeBST(root->right,v);
}
node *buildTreeUtil(vector<node*> &nodes,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)>>1;
	node* root=nodes[mid];
	root->left=buildTreeUtil(nodes,s,mid-1);
	root->right=buildTreeUtil(nodes,mid+1,e);
	return root;
}
node *buildTree(node *root){
	vector<node*> nodes;
	storeBST(root,nodes);
	int n=nodes.size();
	return buildTreeUtil(nodes,0,n-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = newNode(5);   
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11); 
  
    root = buildTree(root); 
	preorder(root);
}
