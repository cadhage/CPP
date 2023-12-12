#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
void printInorder(node *root){
	if(root==NULL)
		return ;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
}
node *newNode(int x){
	node* temp=new node;
	temp->left=temp->right=NULL;
	temp->data=x;
	return temp;
}
node *constructTreeUtil(int a[],int &preIndex,int k,int min,int max,int n ){
	if(preIndex>=n){
		return NULL;
	}
	node *root=NULL;
	if(k>min && k<max){
		root=newNode(k);
		preIndex++;
		if(preIndex<n){
			root->left=constructTreeUtil(a,preIndex,
					a[preIndex],min,k,n);
			root->right=constructTreeUtil(a,preIndex,
					a[preIndex],k,max,n);
		}
	}
	return root;	
}
int main ()  
{  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );    
   	int preIndex=0;  
  	node *root=constructTreeUtil(pre,preIndex,pre[0],INT_MIN,INT_MAX,size);
    cout << "Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
    return 0;  
}  
  
