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
bool deadEnd(node *root,int min=1,int max=INT_MAX){
	if(!root)
		return false;
	if(min==max){
		return true;
	}
	return deadEnd(root->left,min,root->data-1)||
			deadEnd(root->right,root->data+1,max);
	
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
root = insert(root, 8); 
    root = insert(root, 5); 
    root = insert(root, 2); 
    root = insert(root, 3); 
    root = insert(root, 7); 
    root = insert(root, 11); 
    root = insert(root, 4); 
    if (deadEnd(root) == true) 
        cout << "Yes " << endl; 
    else
        cout << "No " << endl; 
    //secondLargest(root); 
	return 0; 
}
