#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *left,*right;
};
node *newNode(int x){
	node *temp=new node;
	temp->x=x;
	temp->left=temp->right=NULL;
	return temp;
}
node *findLCA(node *root,int a,int b,int &aa,int &bb,int &dist,int lvl){
	if(root==NULL)
		return NULL;
	if(root->x==a){
		aa=lvl;
		return root;
	}
	if(root->x==b){
		bb=lvl;
		return root;
	}
	node *left=findLCA(root->left,a,b,aa,bb,dist,lvl+1);
	node *right=findLCA(root->right,a,b,aa,bb,dist,lvl+1);
	if(left&&right)
	{
		dist=aa+bb-2*lvl;
		return root;
	}
	return left?left:right;
}
int findLevel(node *root,int x,int level){
	if(root==NULL)
		return -1;
	if(root->x==x)
		return level;
	int l=findLevel(root->left,x,level+1);
	return (l=-1)?l:findLevel(root->right,x,level+1);
}
int findDistance(node *root,int a,int b){
	int aa=-1,bb=-1,dist;
	node *lca=findLCA(root,a,b,aa,bb,dist,1);
	if(aa!=-1 &bb!=-1)
		return dist;
	if(aa!=-1){
		dist=findLevel(lca,b,0);
		return dist;
	}
	if(bb!=-1){
		dist=findLevel(lca,a,0);
		return dist;
	}
	return -1;
}
int main(){
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

