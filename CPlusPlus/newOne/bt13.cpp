#include <bits/stdc++.h>
using namespace std;
struct node{
	int key;
	node *left,*right;
};
node* newNode(int data){
	node* temp=new node;
	temp->key=data;
	temp->left=temp->right=NULL;
	return temp;
}
void print(node *root,int k1,int k2){
	if(root==NULL)
		return;
	if(k1<root->key)
		print(root->left,k1,k2);
	if(k1<=root->key && k2>=root->key)
		cout<<root->key<<' ';
	if(k2>root->key)
		print(root->right,k1,k2);
}
int main(){
	node *root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	print(root,10,25);
}
