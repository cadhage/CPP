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
	node *a=root,*pre;
	while(a!=NULL){
		if(a->left==NULL){
			cout<<a->data<<' ';
			a=a->right;
		}
		else{
			pre=a->left;
			while(pre->right!=NULL &&pre->right!=a){
				pre=pre->right;
			}
			if(pre->right==NULL){
				pre->right=a;
				a=a->left;
			}
			else{
				pre->right=NULL;
				cout<<a->data<<' ';
				a=a->right;
			}
		}
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
    diagonalPrint(root); 
  
    return 0; 
} 
