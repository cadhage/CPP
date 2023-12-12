#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
int maxDiffUtil(node *root,int &res){
	if(root==NULL)
		return INT_MAX;
	if(root->left==NULL &&root->right==NULL)
		return root->data;
	int val=min(maxDiffUtil(root->left,res),maxDiffUtil(root->right,res));
	res=max(val,root->data-val);
	return min(val,root->data);
}
int maxDiff(node *root){
	int res=INT_MIN;
	maxDiffUtil(root,res);
	return res;
}
int main(){
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
           " its ancestor is : %d\n", maxDiff(root)); 
	return 0;
}
