#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* newNode(int data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* insert(node* root,int data){
	if(root==NULL)
		return newNode(data);
	if(root->data>=data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
void seqExistUtil(node *root,int a[],int &index){
	if(root==NULL)
		return;
	seqExistUtil(root->left,a,index);
	if(root->data==a[index])
		index++;
	seqExistUtil(root->right,a,index);
}
bool seqExist(node *root,int a[],int n){
	int index=0;
	seqExistUtil(root,a,index);
	if(index==n)
		return true;
	else return false;
}
int main(){
	   struct node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 10); 
    root = insert(root, 3); 
    root = insert(root, 6); 
    root = insert(root, 1); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 14); 
    root = insert(root, 13); 
  
    int seq[] = {4, 6, 8, 14}; 
    int n = sizeof(seq)/sizeof(seq[0]); 
  
    seqExist(root, seq, n)? cout << "Yes" : 
                            cout << "No"; 
	return 0;
}
