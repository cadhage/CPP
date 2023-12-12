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
node *findLCA(node *root,int n1,int n2 ){
	if(root==NULL)
		return NULL;
	if(root->key==n1||root->key==n2)
		return root;
	node *l=findLCA(root->left,n1,n2);
	node *r=findLCA(root->right,n1,n2);
	if(l&&r)
		return root;
	return l!=NULL?l:r;
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
