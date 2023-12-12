#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
void preorder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<' ';
	preorder(root->left);
	
	preorder(root->right);
}
void storeBST(node* root,vector<node*> &v){
	if(root==NULL)
		return;
	storeBST(root->left,v);
	v.push_back(root);
	storeBST(root->right,v);
}
vector<node*> cunstructTrees(int s,int e){
	vector<node*> v;
	if(s>e){
		v.push_back(NULL);
		return v;
	}
	for(int i=s;i<=e;i++){
		vector<node*> left=cunstructTrees(s,i-1);
		vector<node*> right=cunstructTrees(i+1,e);
		for(int j=0;j<left.size();j++){
			node* l=left[j];
			for(int k=0;k<right.size();k++){
				node *r=right[k];
				node* node=newNode(i);
				node->left=l;
				node->right=r;
				v.push_back(node);
			}
			
		}
	}
	return v;
}
//void preorder(node* root){
//	if(node==NULL)
//		return;
//	cout<<root->data<<' ';
//	preorder(root->left);
//	preorder(root->right);
//}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<node *> trees=cunstructTrees(1,3);
	cout << "Preorder traversals of all constructed BSTs are \n"; 
    for (int i = 0; i < trees.size(); i++) 
    { 
        preorder(trees[i]); 
        cout << endl; 
    } 
}
