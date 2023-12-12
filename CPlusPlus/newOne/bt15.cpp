#include <bits/stdc++.h>
using namespace std;
struct node{
	int key;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->key=data;
	return temp;
}
node *insert(node *root,int k){
	if(root==NULL)
		return newNode(k);
	if(root->key>k)
		root->left=insert(root->left,k);
	else root->right=insert(root->right,k); 
	return root;
}
int distRoot(node *root,int x){
	if(root->key==x)
		return 0;
	else if(root->key>x)
		return 1+distRoot(root->left,x);
	else return 1+distRoot(root->right,x);
}
int findDist(node *root,int a,int b){
	if(root==NULL)
		return 0;
	if(root->key>a&&root->key>b)
		findDist(root->left,a,b);
	if(root->key<a && root->key<b)
		findDist(root->right,a,b);
	if(root->key>=a && root->key<=b)
		return distRoot(root,a)+
				distRoot(root,b);
}
int main(){
	struct node* root = NULL; 
    root = insert(root, 20); 
    insert(root, 10); 
    insert(root, 5); 
    insert(root, 15); 
    insert(root, 30); 
    insert(root, 25); 
    insert(root, 35); 
    cout << findDist(root, 5, 35); 
	return 0;
}
