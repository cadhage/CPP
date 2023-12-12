#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newnode(int x){
	node *temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}
int sum=0;
bool Util(node *node,unordered_set<int> &s,int d){
	if(!node)
		return false;
	int rem=d-node->data;
	if(s.find(rem)!=s.end())
		return true;
	s.insert(node->data);
	bool res=Util(node->left,s,d)||
			Util(node->right,s,d);
	s.erase(node->data);
	return res;
}
int isPathSum(node *root){
	unordered_set<int> s;
	return Util(root->left,s,root->data)||Util(root->right,s,root->data);
}
int main() 
{ 
    struct node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    isPathSum(root)? cout << "Yes" : cout << "No"; 
    return 0; 
} 
