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
int res=0;
int maxDiff(node *root,int &res){
	if(root==NULL)
		return INT_MAX;
	if(root->left==NULL && root->right==NULL)
		return root->data;
	int val=min(maxDiff(root->left,res),maxDiff(root->right,res));
	res=max(res,root->data-val);
	return min(val,root->data);
}
int maxD(node *root){
	int res=INT_MIN;
	maxDiff(root,res);
	return res;
}
int main() 
{ 
    // Making above given diagram's binary tree 
    node* root; 
    root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    printf("Maximum difference between a node and"
           " its ancestor is : %d\n", maxD(root)); 
} 
