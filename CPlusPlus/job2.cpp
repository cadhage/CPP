#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int d){
	node *temp=new node;
	temp->data=d;
	temp->left=temp->right=NULL;
	return temp;
}
node *findLCAUtil(node* root,int a,int b,bool &aa,bool &bb){
	if(root==NULL)
		return NULL;
	if(root->data==a){
		aa=true;
		return root;
	}
	if(root->data==b){
		bb=true;
		return root;
	}
	node *left=findLCAUtil(root->left,a,b,aa,bb);
	node *right=findLCAUtil(root->right,a,b,aa,bb);
	if(left&&right)
		return root;
	return left?left:right;
}
bool find(node *root,int k){
	if(root==NULL)	
		return false;
	if(root->data==k||find(root->left,k)||find(root->right,k))
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
int main() 
{ 
    // Let us create binary tree given in the above example 
    node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    node *lca =  findLCA(root, 4, 5); 
    if (lca != NULL) 
       cout << "LCA(4, 5) = " << lca->data<<'\n'; 
    else
       cout << "Keys are not present \n"; 
  
    lca =  findLCA(root, 4, 10); 
    if (lca != NULL) 
       cout << "nLCA(4, 10) = " << lca->data<<'\n'; 
    else
       cout << "nKeys are not present "<<'\n'; 
  
    return 0; 
}
