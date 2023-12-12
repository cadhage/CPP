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
void diagonalPrint(node *root){
	stack<node *> s;
	node *a=root;
	while(!s.empty()||a!=NULL){
		while(a!=NULL){
			s.push(a);
			a=a->left;
		}
		a=s.top();
		s.pop();
		cout<<a->data<<' ';
		a=a->right;
	}
}
int main() 
{ 
    node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    /*  Node* root = newNode(1); 
        root->left = newNode(2); 
        root->right = newNode(3); 
        root->left->left = newNode(9); 
        root->left->right = newNode(6); 
        root->right->left = newNode(4); 
        root->right->right = newNode(5); 
        root->right->left->right = newNode(7); 
        root->right->left->left = newNode(12); 
        root->left->right->left = newNode(11); 
        root->left->left->right = newNode(10);*/
  
    diagonalPrint(root); 
  
    return 0; 
} 
