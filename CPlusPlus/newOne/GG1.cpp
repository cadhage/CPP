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
	return  temp;
}
node *search(node *root,int x){
	if(root->x==NULL ||root->x==x)
		return root;
	if(root->x>x){
		return search(root->left,x);
	}
	else return search(root->right,x);
}
node *insert(node *root,int x){
	if(root==NULL)
		return newNode(x);
	if(x<=root->x){
		root->left=insert(root->left,x);
	}
	else root->right=insert(root->right,x);
	return root;
}
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
node *deleteNode(node *root,int x){
	if(root==NULL)
		return root;
	if(x<root->x){
		root->left=deleteNode(root->left,x);
	}
	else if(x>root->x)
		root->right=deleteNode(root->right,x);
	else{
		if(root->left==NULL){
			node *temp=root->right;
			free(root);
			return temp;
		}
		if(root->right==NULL){
			node *temp=root->left;
			free(root);
			return temp;
		}
		node *temp=minValueNode(root->right);
		root->x=temp->x;
		root->right=deleteNode(root->right,temp->x);
	}
	return root;
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->x); 
        inorder(root->right); 
    } 
} 
int main(){
	struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
	inorder(root);
	deleteNode(root,20);
	cout<<'\n';
	inorder(root); 
    //cout<<search(root,20);
    
	return 0;
}
