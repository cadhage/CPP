#include <bits/stdc++.h>
using namespace std;
struct node 
{ 
    int key; 
    struct node *left, *right; 
};   
node * newNode(int k) 
{ 
    node *temp = new node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
node *findLCAUtil(node *root,int n1,int n2,bool &v1,bool &v2 ){
	if(root==NULL)
		return NULL;
	if(root->key==n1){
		v1=true;
		return root;
	}
	if(root->key==n2){
		v2=true;
		return root;
	}
	node *l=findLCAUtil(root->left,n1,n2,v1,v2);
	node *r=findLCAUtil(root->right,n1,n2,v1,v2);
	if(l&&r)
		return root;
	return l!=NULL?l:r;
}
bool find(node *root,int k){
	if(root==NULL)
		return false;
	if(root->key==k||find(root->left,k)||find(root->right,k))
		return true;
	return false;
}
node *findLCA(node *root,int n1,int n2){
	bool v1=0,v2=0;
	node *lca=findLCAUtil(root,n1,n2,v1,v2);
	if(v1&&v2||v1&&find(lca,n2)||v2&&find(lca,n1))
		return lca;
	return NULL;
}
int main(){	
	node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key<<'\n'; 
    return 0;
}
