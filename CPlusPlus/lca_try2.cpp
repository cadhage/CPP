#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->x=x;
	temp->left=temp->right=NULL;
	return temp;
}
node *findLCAUtil(node *root,int a,int b,bool &aa,bool &bb){
	if(root==NULL)
		return NULL;
	if(root->x==a)
	{
		aa=true;
		return root;
	}
	if(root->x==b){
		bb=true;
		return root;
	}
	node *left=findLCAUtil(root->left,a,b,aa,bb);
	node *right=findLCAUtil(root->right,a,b,aa,bb);
	if(left&&right)
		return root;
	return left?left:right;
}
bool find(node *root,int x){
	if(root==NULL)
		return false;
	if(root->x==x||find(root->left,x)||find(root->right,x))
		return true;
	return false;
}
node *findLCA(node *root,int a,int b){
	bool aa=false,bb=false;
	node *lca=findLCAUtil(root,a,b,aa,bb);
	if(aa&&bb||aa&&find(lca,b)||bb&&find(lca,a))
		return lca;
	return NULL;
}
bool printNodes(node *root,int x){
	if(root==NULL)
		return false;
	if(root->x==x||printNodes(root->left,x)||printNodes(root->right,x))
	{
		cout<<root->x<<' ';
		return true;
	}
	return false;
}
int main(){
	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->right->left->left = newNode(9); 
    root->right->left->right = newNode(10); 
	node *lca=findLCA(root,9,7);
	printNodes(root,lca->x);
	if(lca){
	//	cout<<lca->x<<'\n';
	}
	return 0;
}

