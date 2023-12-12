#include <bits/stdc++.h>
using namespace std;
// Driver program to test above functions 
struct Node { 
	int key; 
	Node *left, *right; 
}; 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
int UN_SumRight(Node *root){
	if(root->left==NULL && root->right==NULL)
		return root->key;
	if(root->right!=NULL)
		return root->key+UN_SumRight(root->right);
	else 
		return root->key+UN_SumRight(root->left);
}
int UN_SumLeft(Node *root){
	if(root->left==NULL && root->right==NULL)
		return root->key;
	if(root->left!=NULL)
		return root->key+UN_SumLeft(root->left);
	else 
		return root->key+UN_SumLeft(root->right);
}
int UN_Sum(Node *root){
	int lb=0,rb=0;
	if(root->left){
		lb=UN_SumLeft(root->left);
	}
	if(root->right)
		rb=UN_SumRight(root->right);
	return root->key+lb+rb;
}
int sum(Node *root){
	if(!root)
		return 0;
	return root->key+sum(root->left)+sum(root->right);
}
bool isSumSame(Node *root){
	int sumUC=UN_Sum(root);
	int sumT=sum(root);
	return sumUC==(sumT);
}
int main() 
{ 
    // Making above given diagram's binary tree 
    Node* root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    if (isSumSame(root)) 
        printf("Sum of covered and uncovered is same\n"); 
    else
        printf("Sum of covered and uncovered is not same\n"); 
}
