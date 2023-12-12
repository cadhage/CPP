
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right,*parent;
};
node* newNode(int data){
	node* temp=new node;
	temp->data=data;
	temp->left=temp->right=temp->parent=NULL;
	return temp;
}
node* insert(node *node,int data){
	if(node==NULL)
		return newNode(data);
	else
  { 
    struct node *temp;   
  
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data) 
    {     
         temp = insert(node->left, data); 
         node->left  = temp; 
         temp->parent= node; 
    } 
    else
    { 
        temp = insert(node->right, data); 
        node->right = temp; 
        temp->parent = node; 
    }     
   
    /* return the (unchanged) node pointer */
    return node; 
  } 
}
node *minValue(node *root){
	node *a=root;
	while(a->left!=NULL)
		a=a->left;
	return a;
}
node *inOrderSuccessor(node *root,node* n){
	if(n->right!=NULL)
		return minValue(n->right);
	node *p=n->parent;
	while(p!=NULL &&n==p->right){
		n=p;
		p=p->parent;
	}
	return p;
}
int main(){
	node *root=NULL,*temp,*succ,*min;
	root=insert(root,20);
   	insert(root, 8); 
    insert(root, 22); 
    insert(root, 4); 
    insert(root, 12); 
    insert(root, 10); 
    insert(root, 14); 
    temp=root->left->right->right;
	succ=inOrderSuccessor(root,temp); 
	if(succ!=NULL)
		cout<<temp->data<<" "<<succ->data<<'\n';
	return 0;
}
