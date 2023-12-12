#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}
int sum=0;
void addBT(node *root,bool isLeft){
	if(root==NULL)
		return;
	if((!root->left && !root->right && isLeft))
			sum+=root->data;
	addBT(root->left,1);
	addBT(root->right,0);
}
int main(){
    node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 
    //int sum = 
	addBT(root,0); 
    cout << "Sum of all the elements is: " << sum << endl; 
	return 0;
}
