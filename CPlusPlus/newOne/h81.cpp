#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
void Print(node *root,int k1,int k2){
	if(root==NULL)
		return;
	if(k1<root->data)
		Print(root->left,k1,k2);
	if(k1<=root->data &&k2>=root->data)
		cout<<root->data<<' ';
	if(k2>root->data)
		Print(root->right,k1,k2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = new node();  
    int k1 = 10, k2 = 25;  
    root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);   
    Print(root, k1, k2);  
}
