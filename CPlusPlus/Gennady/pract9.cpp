#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,p;
	struct node *left,*right;
};
struct node *newNode(int data,int p){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->k=data;
	temp->p=p;
	temp->left=temp->right=NULL;
	return temp; 
}
void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->k<<' ';
		inorder(root->right);
	}
}
struct node* insert(struct node* node,int key,int pos){
	if(node==NULL){
		cout<<pos<<"\n";
		return newNode(key,pos);
	}
	if(key<node->k){
		node->left=insert(node->left,key,2*pos);
	}
	if(key>node->k){
		node->right=insert(node->right,key,2*pos+1);
	}
	return node;
}
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct node* deleteNode(struct node* root, int key) 
{ 
	if(root==NULL)
		return root;
	if(key<root->k){
		root->left=deleteNode(root->left,key);
	}
	else if(key>root->k){
		root->right=deleteNode(root->right,key);
	}
	else{
		cout<< root->p <<"\n";
		if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node* temp=minValueNode(root->right);
		root->k=temp->k;
		root->right=deleteNode(root->right,temp->k);
	}
	return root;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	struct node *root=NULL;
	for(int i=0;i<n;i++){
		char x;cin>>x;
		int y;cin>>y;
		if(x=='i'){
			if(root==NULL){
				root=insert(root,y,1);
			}else{
				insert(root,y,1);	
			}
		}else if(x=='d'){
			deleteNode(root,y);
		}
	}
	return 0;
}
