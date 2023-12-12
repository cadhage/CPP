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
void findSum(node *root,int &sum){
	if(root==NULL)
		return;
	sum+=root->data;
	findSum(root->left,sum);
	findSum(root->right,sum);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8);  
    int sum=0;
    findSum(root,sum);
    cout<<sum<<'\n';
	return 0;
}
