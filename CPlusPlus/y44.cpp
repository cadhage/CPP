#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->x=x;
	return temp;
}
node *KthLargestUsingMorrisTraversal(node *root,int x){
	node *klargest=NULL;
	node *a=root;
	int c=0;
	while(a!=NULL){
		if(a->right==NULL)
		{
			if(++c==x)
				klargest=a;
			a=a->left;
		}else{
			node *succ=a->right;
			while(succ->left!=NULL &&succ->left!=a){
				succ=succ->left;
			}
			if(succ->left==NULL){
				succ->left=a;
				a=a->right;
			}else{
				succ->left=NULL;
				if(++c==x)
					klargest=a;
				a=a->left;
			}
		}
	}
	return klargest;
}
int main() 
{ 
    // Your C++ Code 
    /* Constructed binary tree is 
          4 
        /   \ 
       2     7 
     /  \   /  \ 
    1    3  6    10 */
  
    node* root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(7); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(6); 
    root->right->right = newNode(10); 
  
    cout << "Finding K-th largest Node in BST : "
         << KthLargestUsingMorrisTraversal(root, 2)->x; 
  
    return 0; 
} 
