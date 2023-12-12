#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
struct node 
{ 
    int data; 
    node *left, *right; 
}; 
node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
node *findLCAUtil(node *root,int a,int b,bool &aa,bool &bb){
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
bool find(node *root,int x){
	if(root==NULL)
		return false;
	if(root->data==x||find(root->left,x)||find(root->right,x))
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
	node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data; 
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data; 
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data; 
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data; 
    return 0; 
}
