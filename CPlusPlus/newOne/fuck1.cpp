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
void digUtil(node *root,int s,vector<int> &mp){
	if(!root)
		return;
	mp[s]+=root->data;
	digUtil(root->left,s+1,mp);
	digUtil(root->right,s,mp);
}
void addBT(node *root){
	vector<int> dig;
	digUtil(root,0,dig);
	for(auto it:dig){
		cout<<it<<'\n';
	}
}
int main(){
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
	addBT(root); 
    //cout << "Sum of all the elements is: " << sum << endl; 
	return 0;
}
