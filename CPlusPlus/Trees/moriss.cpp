#include <bits/stdc++.h>
//Morris travessal
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int d){
	node *temp=new node;
	temp->data=d;
	temp->left=temp->right=NULL;
	return temp;
}
void morrisTravarsal(node *root){
	node *a,*pre;
	if(root==NULL)
		return;
	a=root;
	while(a){
		if(a->left==NULL){
			cout<<a->data<<' ';
			a=a->right;
		}
		else{
			pre=a->left;
			while(pre->right && pre->right!=a){
				pre=pre->right;
			}
			if(pre->right==NULL){
				pre->right=a;
				a=a->left;
			}else{
				pre->right=NULL;
				cout<<a->data<<' ';
				a=a->right;
			}
		}
	} 
}
int main(){
	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    morrisTravarsal(root); 
	return 0 ;
}
