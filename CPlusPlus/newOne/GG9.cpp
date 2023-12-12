#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right,*parent;
};
node *newNode(int x){
	node *temp=new node;
	temp->data=x;
	temp->left=temp->right=temp->parent=NULL;
	return temp;
}
node *insert(node *root,int x){
	if(root==NULL)
		return newNode(x);
	if(x<root->data){
		root->left=insert(root->left,x);
		root->left->parent=root;
	}
	else if(x>root->data){
		root->right=insert(root->right,x);
		root->right->parent=root;
	}
	return root;
}
node *LCA(node *n1,node *n2){
	map<node *,bool> ans;
	while(n1!=NULL){
		ans[n1]=true;
		n1=n1->parent;
	}
	while(n2!=NULL){
		if(ans.find(n2)!=ans.end())
			return n2;
		n2=n2->parent;
	}
	return NULL;
}
int main(void) 
{ 
    node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    node *n1 = root->left->right->left; 
    node *n2 = root->left; 
    node *lca = LCA(n1, n2); 
  
    printf("LCA of %d and %d is %d \n", n1->data, n2->data, lca->data); 
  
    return 0; 
} 
