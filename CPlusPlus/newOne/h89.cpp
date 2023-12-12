#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
int c=0;
void secondLargest(node *root){
	if(root==NULL)
		return;
	secondLargest(root->right);
	if()
	secondLargest(root->left);
}
node* insert(node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, re cur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node* root=NULL;
	 root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    secondLargest(root); 
	return 0; 
}
