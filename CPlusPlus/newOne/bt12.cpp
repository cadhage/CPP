#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right;
};
node* newNode(int data){
	node* temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* insert(node *root,int data){
	if(root==NULL)
		return newNode(data);
	if(root->data>=data){
		root->left=insert(root->left,data);
	}
	else root->right=insert(root->right,data);
	return root;
}
void store(node *root,unordered_set<int> &all_nodes,unordered_set<int> &leaf_nodes){
	if(root==NULL)
		return;
	all_nodes.insert(root->data);
	if(root->left==NULL && root->right==NULL){
		leaf_nodes.insert(root->data);
		return;
	}
	store(root->left,all_nodes,leaf_nodes);
	store(root->right,all_nodes,leaf_nodes);
}
bool isDeadEnd(node *root){
	if(root==NULL)
		return false;
	unordered_set<int> all_nodes,leaf_nodes;
	all_nodes.insert(0);
	store(root,all_nodes,leaf_nodes);
	for(auto i:leaf_nodes){
		if(all_nodes.find(i+1)!=all_nodes.end()||
			all_nodes.find(i-1)!=all_nodes.end())
				return true;
	}
	return false;
}
int main(){
	node *root=NULL;
	root=insert(root,8);
	insert(root,5);
	insert(root,2);
	insert(root,3);
	insert(root,7);
	insert(root,11);
	insert(root,4);
	if(isDeadEnd(root))
		cout<<"Yes";
	else cout<<"No";
	return 0;
}
