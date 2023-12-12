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
	if(root->x==a){
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
	if(aa&&bb||find(lca,a)&&bb||aa&&find(lca,b))
		return lca;
	return NULL;
}
int main(){
	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	node *lca=findLCA(root,4,5);
	if(lca){
		cout<<lca->x<<'\n';
	}
	return 0;
}

