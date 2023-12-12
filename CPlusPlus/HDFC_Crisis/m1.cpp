#include <bits/stdc++.h>
using namespace std;
struct node{
	int data,pos;
	node *left,*right;
};
node *newNode(int data,int pos){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	temp->pos=pos;
	cout<<pos<<'\n';
	return temp;
}
node *insert(int k,node *root,int pos){
	if(root==NULL)
		newNode(k,pos);
	if(root->data>k)
		root->left=insert(k,root->left,2*pos);
	else 
		root->right=insert(k,root->right,2*pos+1);
	return root;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root=NULL;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char op;cin>>op;
		int key;cin>>key;
		if(op=='i');
			root=insert(key,root,1);
		//else 
		//	root=remove(key,root);
	}
	return 0;
}
