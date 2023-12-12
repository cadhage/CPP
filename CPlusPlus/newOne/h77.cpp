#include <bits/stdc++.h> 
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *newNode(int data){
	struct node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
struct node *insert(struct node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(data>root->data){
		root->right=insert(root->right,data);
	}
	else if(data<root->data)
		root->left=insert(root->left,data);
	return root;
}
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
void storeInorder(node *root,vector<node*> &s){
	if(root==NULL)
		return;
	storeInorder(root->left,s);
	s.push_back(root);
	storeInorder(root->right,s);
}
node *setToBST(vector<node*> &nodes,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)>>1;
	node *root=nodes[mid];
	root->left=setToBST(nodes,s,mid-1);
	root->right=setToBST(nodes,mid+1,e);
	return root;
}
node *binaryTreeToBST(node *root){
	vector<node*> nodes;
	storeInorder(root,nodes);
	int n=nodes.size();
	return setToBST(nodes,0,n-1);
}
int main() 
{ 
	 node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
    root=binaryTreeToBST(root);
	inorder(root);
	return 0; 
} 

