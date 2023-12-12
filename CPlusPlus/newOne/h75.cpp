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
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
struct node *createBST(int a[],int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)>>1;
	struct node *root=newNode(a[mid]);
	root->left=createBST(a,s,mid-1);
	root->right=createBST(a,mid+1,e);
	return root;
}
int main() 
{ 
	int a[]={10,20,40,50,60,80};
	struct node *root=createBST(a,0,6);
	inorder(root);
	return 0; 
} 

