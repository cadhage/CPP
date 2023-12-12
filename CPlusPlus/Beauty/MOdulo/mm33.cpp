#include <bits/stdc++.h>
using namespace std;
struct node{
	int data,count;
	node *left,*parent,*right;
};
node *insert(node *root,node *temp){
	node *traversal=root;
	node *current=root;
	while(traversal){
		current=traversal;
		if(temp->data<traversal->data){
			traversal->count++;
			traversal=traversal->left;
		}else{
			traversal=traversal->right;
		}
	}
	if(!root){
		root=temp;
	}else if(temp->data<current->data){
		current->left=temp;
	}else{
		current->right=temp;
	}
	return root;
}
node *binary_search_tree(node *root,int a[],int n){
	node *temp=NULL;
	for(int i=0;i<n;i++){
		temp=new node;
		temp->left=temp->right=NULL;
		temp->data=a[i];
		temp->count=0;
		root=insert(root,temp);
	}
	return root;
}
int k_smallest_element(node *root,int k){
	int res=-1;
	if(root){
		node *traverse=root;
		while(traverse){
			if((traverse->count+1)==k){
				res=traverse->data;
				break;
			}else if(k>traverse->count){
				k=k-(traverse->count+1);
				traverse=traverse->right;
			}else{
				traverse=traverse->left;
			}
		}
	}
	return res;
}
int main(){
    int a[]={20,8,22,4,12,10,14};
    node *root=NULL;
    int n=sizeof a/sizeof a[0];
    root=binary_search_tree(root,a,n);
    	for(int i=1;i<=n;i++){
		cout<<i<<" "<<k_smallest_element(root,i)<<'\n';
	}
    return 0; 
} 
