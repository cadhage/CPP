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
void levelOrder(node* root){
	if(root==NULL)
		return;
	list<node*> q;
	q.push_back(root);
	while(!q.empty()){
		int nodeCount=q.size();
		while(nodeCount>0){
			node *node=q.front();
			cout<<node->data<<' ';
			q.pop_front();
			if(node->left)
				q.push_back(node->left);
			if(node->right)
				q.push_back(node->right);
			nodeCount--;
		}
		cout<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node* root = newNode(8); 
    root->left = newNode(4); 
    root->right = newNode(12); 
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
    root->left->left = newNode(2); 
    root->left->right = newNode(6); 
  
    //BSTToMinHeap(root); 
    levelOrder(root);
	return 0; 
}
