#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* lca(node *root,int a,int b){
	if(root==NULL)
		return NULL;
	if(root->data>a && root->data>b){
		return lca(root->left,a,b);
	}
	if(root->data<a && root->data<b)
		return lca(root->right,a,b);
	return root;
}
node *newNode(int data){
	node* temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
int main(){
	struct node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
    int n1 = 10, n2 = 14; 
    struct node *t = lca(root, n1, n2); 
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
	return 0;
}
