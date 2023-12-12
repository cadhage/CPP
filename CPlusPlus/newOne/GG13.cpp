#include <bits/stdc++.h>
using namespace std;
struct node { 
    int key; 
    struct node *left, *right; 
}; 
  
// A utility function to  
// create a new BST node 
struct node* newNode(int item) 
{ 
    struct node* temp = new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void inorder(struct node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->key << " "; 
        inorder(root->right); 
    } 
} 
struct node* insert(struct node* node, 
                              int key) 
{ 
    if (node == NULL) 
        return newNode(key); 
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    return node; 
} 
void reversePath(node *root,int k,queue<int> &q){
	if(root==NULL)
		return;
	if(root->key==k){
		q.push(root->key);
		root->key=q.front();
		q.pop();
		return;
	}
	else if(k<root->key){
		q.push(root->key);
		reversePath(root->left,k,q);
		root->key=q.front();
		q.pop();
	}
	else if(k>root->key){
		q.push(root->key);
		reversePath(root->right,k,q);
		root->key=q.front();
		q.pop();
	}
	return;
}
int main() 
{ 
    struct node* root = NULL; 
    queue<int> q1; 
    int k = 80; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    cout << "Before Reverse :" << endl; 
    inorder(root); 
    cout << "\n"; 
    reversePath(root, k, q1);  
    cout << "After Reverse :" << endl; 
    inorder(root); 
  
    return 0; 
} 
