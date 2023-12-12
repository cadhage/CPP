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
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
int height(node *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void inorder(node *root){
	if(root==NULL)
		return;
	
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}
int main(){
	int n;cin>>n;
	vector<int> a(n);
	int x;cin>>x;
	node *root=NULL;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	root=insert(root,a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	//inorder(root);
	cout<<height(root);
	return 0;
}
