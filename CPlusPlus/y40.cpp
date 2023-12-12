#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=x;
	return temp;
}
void preOrder(node *root){
	if(root==NULL)
		return;

	preOrder(root->left);
	cout<<root->data<<' ';
	preOrder(root->right);
}
int countNodes(node *root){
	if(root==NULL)
		return 0;
	return countNodes(root->left)+1+countNodes(root->right);
}
void storeInorder(node *root,int a[],int &index){
	if(root==NULL)
		return;
	storeInorder(root->left,a,index);
	a[index++]=root->data;
	storeInorder(root->right,a,index);
}
void arrToBST(int a[],node *root,int &index){
	if(root==NULL)
		return;
	arrToBST(a,root->left,index);
	root->data=a[index++];
	arrToBST(a,root->right,index);
}
void binaryTreeToBST(node *root){
	if(root==NULL)
		return;
	int n=countNodes(root);
	int a[n];
	int i=0;
	storeInorder(root,a,i);
	sort(a,a+n);
	i=0;
	arrToBST(a,root,i);
	//delete[] a;
}
int main() 
{ 
    struct node *root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /      \ 
      20       5   */
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
  
    // convert Binary Tree to BST 
    binaryTreeToBST (root); 
  
    printf("Following is Inorder Traversal of the converted BST: \n"); 
    preOrder(root);//Inorder 
  
    return 0; 
} 
