#include <bits/stdc++.h> 
using namespace std; 
struct node { 
    int data; 
    struct node *left, *right; 
}; 
void inOrder(node *root){
	if(!root)
		return;
	inOrder(root->left);
	cout<<root->data<<' ';
	inOrder(root->right);
}
node* newNode(int data) 
{ 
    // dynamically allocating memory 
    node* temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void store(node *root,set<int> &s){
	if(root==NULL)
		return;
	store(root->left,s);
	s.insert(root->data);
	store(root->right,s);
}
void setToBST(set<int> &s,node *root){
	if(root==NULL)
		return;
	setToBST(s,root->left);
	auto it=s.begin();
	root->data=*it;
	s.erase(it);
	setToBST(s,root->right);
}
void binaryTreeToBST(node *root){
	set<int> s;
	store(root,s);
	setToBST(s,root);
}
void inorder(node* root) 
{ 
    if (!root) 
        return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 
int main() 
{ 
    node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11); 
  
    /* Constructing tree given in the above figure 
           5 
         /   \ 
        7     9 
       /\    / \ 
      1  6   10 11   */
  
    // converting the above Binary tree to BST 
    binaryTreeToBST(root); 
    cout << "Inorder traversal of BST is: " << endl; 
    inorder(root); 
    return 0;
} 
  
