#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
int findLevel(node *root,int k,int level){
	if(root==NULL)
		return -1;
	if(root->data==k)
		return level;
	int l=findLevel(root->left,k,level+1);
	return (l!=-1)?l:findLevel(root->right,k,level+1);
}
node *findDistUtil(node *root,int n1,int n2,int &d1,int &d2,int dist,int level){
	if(root==NULL)
		return NULL;
	if(root->data==n1){
		d1=level;
		return root;
	}
	if(root->data==n2){
		d2=level;
		return root;
	}
	node *left=findDistUtil(root->left,n1,n2,d1,d2,dist,level+1);
	node *right=findDistUtil(root->right,n1,n2,d1,d2,dist,level+1);
	if(left&&right){
		dist=d1+d2-2*level;
		return root;
	}	
	return (left!=NULL)?left:right;
}
int findDistance(node *root,int n1,int n2){
	int d1=-1,d2=-1,dist;
	node *lca=findDistUtil(root,n1,n2,d1,d2,dist,1);
	if(d1!=-1&&d2!=-1)
		return dist;
	if(d1!=-1){
		dist=findLevel(lca,n1,0);
		return dist;
	}
	if(d2!=-1){
		dist=findLevel(lca,n2,0);
		return dist;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    // above example 
    node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5); 
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6); 
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4); 
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4); 
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5); 
	return 0;
}
