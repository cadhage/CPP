#include <bits/stdc++.h> 
using namespace std; 
struct Node{
	struct Node* left, *right;
	int key;
};
struct Node* newNode(int d){
	struct Node* temp=new Node;
	temp->key=d;
	temp->left=temp->right=NULL;
	return temp;
}
void storeSorted(Node* root,int a[],int &i){
	if(root!=NULL){
		storeSorted(root->left,a,i);
		a[i++]=root->key;
		storeSorted(root->right,a,i);
	}
}
Node* insert(Node* node,int key){
	if(node==NULL)
		return newNode(key);
	if(key<node->key)
		node->left=insert(node->left,key);
	else if(key>node->key)
		node->right=insert(node->right,key);
	return node;
}
void treeSort(int a[],int n){
	struct Node *root=NULL;
	root=insert(root,a[0]);
	for(int i=1;i<n;i++){
		insert(root,a[i]);
	}
	int i=0;
	storeSorted(root,a,i);
}
int main() 
{ 
	int a[] ={64, 25, 12, 22, 11}; 
	treeSort(a, 5); 
	cout << "Sorted array: \n"; 
	for(auto it:a){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

