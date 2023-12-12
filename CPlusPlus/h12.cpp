#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
void findSum(node *root,int &sum,int x){
	if(root==NULL)
		return;
	if(root->left)
		sum+=root->data;
	findSum(root->left,sum,x);
	findSum(root->right,sum,x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12);
      
    int sum=0;
    findSum(root,sum,2);
    cout<<sum<<'\n';
	return 0;
}
