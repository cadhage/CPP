#include <bits/stdc++.h>
using namespace std;
struct  node{
	int  data;
	node *left,*right;
};
node *newNode(int data){
	node* temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}      
void store(node *root,vector<int> &v){
	if(root==NULL)
		return;
	store(root->left,v);
	v.push_back(root->data);
	store(root->right,v);
}
bool checkBST(node *root1,node* root2){
	if(root1==NULL && root2==NULL)
		return true;
	if((root1==NULL && root2!=NULL)||(root2==NULL && root1!=NULL))
		return false;
	vector<int> v1,v2;
	store(root1,v1);
	store(root2,v2);
	return v1==v2;
}
int main(){
	node* root1 = newNode(15); 
    root1->left = newNode(10); 
    root1->right = newNode(20); 
    root1->left->left = newNode(5); 
    root1->left->right = newNode(12); 
    root1->right->right = newNode(25); 
      
    // Second BST 
    node* root2 = newNode(15); 
    root2->left = newNode(12); 
    root2->right = newNode(20); 
    root2->left->left = newNode(5); 
    root2->left->left->right = newNode(10); 
    root2->right->right = newNode(25); 
      
    // check if two BSTs have same set of elements 
    if (checkBST(root1, root2)) 
        cout << "YES"; 
    else
        cout << "NO"; 
	
	return 0;
}
